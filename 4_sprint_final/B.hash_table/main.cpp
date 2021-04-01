#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <exception>
#include <algorithm>
#include <utility>
#include <list>

// ID удачной посылки: 49883464

namespace new_std {

    uint64_t pow(const uint64_t base, const uint32_t pow) {

       uint64_t base_copy = base;

       if (pow == 0u) {
          return 1u;
       }

       for (uint32_t i = pow; i > 1u; --i) {
          base_copy *= base;
       }

       return base_copy;

    }

    uint64_t log_2(const uint64_t x) {

       uint64_t base = 1;
       uint64_t pow = 0;
       while (base < x) {
          base *= 2;
          ++pow;
       }

       return pow;
    }

    template <
            typename Key,
            typename Value,
            typename Hash = std::hash<Key>
                    >
    class hash_table {
    private:
        std::vector<std::list<std::pair<Key, Value>>> buckets_ = std::vector(65'536, std::list<std::pair<Key, Value>>());
        // s_ using for compute bucket in current hash_table
      static constexpr size_t s_ = 2654435769u;
      static constexpr uint64_t pow_2_32 = 4294967296u;
      static constexpr Hash hash = Hash();

      size_t get_hash(const Key key) {

         uint64_t p = new_std::log_2(buckets_.size());
         return (hash(key) * s_ % pow_2_32) >> (32 - p);

      }

    public:
        void put(const Key& key, const Value& value) {

           const size_t id = get_hash(key);
           // Здесь всё же без const, поскольку лист изменяется в методе
           auto& bucket = buckets_[id];

           auto it = std::find_if(bucket.begin(), bucket.end(), [&](const std::pair<Key,Value>& element) {
               return key == element.first;
           });

           if (it != bucket.end()) {

               it->second = value;

           } else {

              bucket.insert(bucket.begin(), {key, value});

           }

        }
         Value get(const Key& key) {

            size_t id = get_hash(key);
            //А здесь уже const))
            const auto& bucket = buckets_[id];

            auto it = std::find_if(bucket.begin(), bucket.end(), [&](const std::pair<Key,Value>& element) {
                return key == element.first;
            });

            if (it != bucket.end()) {

               return it->second;

            }

            throw std::runtime_error("None");

      }
         Value erase(const Key& key) {

            size_t id = get_hash(key);
            auto& bucket = buckets_[id];

            auto it = std::find_if(buckets_[id].begin(), buckets_[id].end(), [&](const std::pair<Key,Value>& element) {
                return key == element.first;
            });

            if (it != bucket.end()) {

               Value value = it->second;

               bucket.erase(it);

               return value;

            }

            throw std::runtime_error("None");

      }

    };


}

int main() {

   new_std::hash_table<uint64_t, uint64_t> hash_table;
   size_t number_of_request;
   uint64_t key, value;
   std::string request;

   std::cin >> number_of_request;

   for (size_t i = 0; i < number_of_request; ++i) {

      std::cin >> request;

      try {
         if (request == "get") {

            std::cin >> key;
            std::cout << hash_table.get(key) << "\n";

         } else if (request == "put") {

            std::cin >> key >> value;
            hash_table.put(key, value);

         } else {

            std::cin >> key;
            std::cout << hash_table.erase(key) << "\n";

         }
      } catch (std::exception& ex) {
         std::cout << ex.what() << "\n";
      }

   }

   return 0;
}
