#include <iostream>
#include <vector>
#include <memory>

/*
 * Номер удачной посылки: 52102897
 * Временная сложность: O(n * L * k), где n - количество вхожных строк, L - длина самой бОльшей из них,
 * k - время распаковки самой "сжатой" строки
 * Пространственная сложность: O(n * L)
 * Логика работы алгоритма:
 * Сначала происходит "распаковка" каждой входной строки, а затем по этому набору находится минимально возможный
 * префикс.
 */

std::string unpackString(const std::string& packed_string, int start_pos, int end_pos) {

    std::string current_building_string;

    for (size_t i = start_pos; i < end_pos; ++i) {

        if (!isalpha(packed_string[i])) {

            int counter_of_bracket = 1;
            size_t current_pack_pos = i + 2;

            while (counter_of_bracket != 0) {

                switch (packed_string[current_pack_pos]) {
                    case '[':
                            ++counter_of_bracket;
                        break;
                    case ']':
                            --counter_of_bracket;
                    default:
                        break;
                }

                ++current_pack_pos;

            }

            --current_pack_pos;

            std::string current_unpacked_brackets = unpackString(packed_string, i + 2, static_cast<int>(current_pack_pos));

            for (size_t j = 0; j < static_cast<size_t>(packed_string[i] - '0'); ++j) {

                current_building_string += current_unpacked_brackets;

            }

            i = current_pack_pos;
            continue;

        }

        current_building_string.push_back(packed_string[i]);

    }

    return current_building_string;

}

int main() {

    size_t number_of_packed_string;

    std::cin >> number_of_packed_string;

    std::vector<std::string> packed_strings(number_of_packed_string);

    for (auto& current_packed_string : packed_strings) {

        std::cin >> current_packed_string;

    }

    std::string unpacked_string;
    std::string current_max_prefix;

    for (auto& packed_string : packed_strings) {

        unpacked_string = unpackString(packed_string, 0, static_cast<int>(packed_string.size()));

        if (current_max_prefix.empty()) {

            current_max_prefix = unpacked_string;

        } else {

            bool was_stop = false;

            for (size_t i = 0; i < std::min(unpacked_string.size(), current_max_prefix.size()); ++i) {

                if (current_max_prefix[i] != unpacked_string[i]) {

                    current_max_prefix.erase(current_max_prefix.begin() + i, current_max_prefix.end());
                    was_stop = true;
                    break;

                }

            }

            if (!was_stop && unpacked_string.size() < current_max_prefix.size()) {

                current_max_prefix = std::move(unpacked_string);

            }

        }

    }

    std::cout << current_max_prefix;

    return 0;
}
