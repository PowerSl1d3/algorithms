#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <sstream>
#include <algorithm>

// ID удачной посылки: 49883338

std::ostream& operator<<(std::ostream& os, const std::vector<std::pair<uint32_t, uint32_t>>& vec) {

   for (size_t i = 0, end = std::min(vec.size(), static_cast<size_t>(5)); i < end; ++i) {
      if (vec[i].first == 0) {
         continue;
      }
      os << -vec[i].second << ' ';
   }

   return os;

}

std::unordered_map<std::string, std::unordered_map<uint32_t, uint32_t>> get_all_documents_from_cin(const size_t number_of_documents) {

   std::string document, word;
   std::unordered_map<std::string, std::unordered_map<uint32_t, uint32_t>> word_to_documents;

   for (size_t i = 0; i < number_of_documents; ++i) {

      std::getline(std::cin, document);

      std::istringstream iss(document);

      while (iss >> word) {
         ++word_to_documents[word][i];
      }

   }

   return word_to_documents;

}

std::vector<std::vector<std::pair<uint32_t, uint32_t>>> get_filled_requests(const size_t number_of_requests, const size_t number_of_documents) {

   std::vector<std::vector<std::pair<uint32_t, uint32_t>>> request_relevant_to_all_documents;

   request_relevant_to_all_documents.assign(number_of_requests, std::vector<std::pair<uint32_t, uint32_t>>(number_of_documents));

   for (size_t i = 0; i < request_relevant_to_all_documents.size(); ++i) {

      for (size_t j = 0; j < request_relevant_to_all_documents[i].size(); ++j) {

         request_relevant_to_all_documents[i][j].second = -(j + 1);

      }

   }

   return request_relevant_to_all_documents;

}

int main() {

   size_t number_of_documents;
   std::string word;

   std::cin >> number_of_documents;
   //Пропускаем застрявший переход строки
   std::cin.ignore(1);
   // Получаем отображение из слова в отображение из документа, в котором это слово встречается, в количество раз, сколько оно было встречено
   const std::unordered_map<std::string, std::unordered_map<uint32_t, uint32_t>> word_to_documents = get_all_documents_from_cin(number_of_documents);

   size_t number_of_requests;
   std::string request;

   std::cin >> number_of_requests;
   std::cin.ignore(1);

   std::vector<std::vector<std::pair<uint32_t, uint32_t>>> request_relevant_to_all_documents = get_filled_requests(number_of_requests, number_of_documents);

   for (size_t i = 0; i < number_of_requests; ++i) {

      /*
       * Опять же, не замерал скорость выполнения кода, но подумал, что
       * на каждой итерации создавать новое множество будет дорого, поэтому
       * делал как было, вызывая метод clear(), но так действительно лучше:)
       */
      std::unordered_set<std::string> unique_words;

      std::getline(std::cin, request);

      std::istringstream iss(request);

      while (iss >> word) {
         unique_words.insert(std::move(word));
      }

      for (const std::string& unique_word : unique_words) {
         //Теперь find. Совсем забыл про этот метод)
         auto it = word_to_documents.find(unique_word);

         if (it != word_to_documents.end()) {

            for (const auto& dict_doc_to_word_count : it->second) {
               request_relevant_to_all_documents[i][dict_doc_to_word_count.first].first += dict_doc_to_word_count.second;
            }

         }

      }

   }

   for (auto& vector : request_relevant_to_all_documents) {
      std::sort(vector.rbegin(), vector.rend());
   }

   for (const auto& vector : request_relevant_to_all_documents) {
      std::cout << vector << "\n";
   }

   return 0;
}