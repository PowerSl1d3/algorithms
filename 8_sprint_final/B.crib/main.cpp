#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

/*
 * Номер удачной посылки: 52119607
 * Временная сложность: Время построения бора( O(m*L) ) + Время разбиения текста на слова ( O(n * (m + L)) )
 * , где m - число паттернов.
 * Итоговая временная сложность: квадратичная, то есть - O(n * L), поскольку при переборе символов текста
 * может случаться так, что для каждой позиции будут возвращаться все паттерны (всего их m штук),
 * где на нахождение всех их будет затрачено время - L. Поскольку m << L, то O(m + L) = O(L).
 * Пространственная сложность: O(n + m*L).
 * Логика работы алгоритма:
 * По заданному набору паттернов строится бор. Затем методом динамики происходит разбиение текста на слова,
 * при этом динамика строится следуюшим образом:
 * База динамики: dp[0] = true, поскольку префикс длины 0 мы всегда сможем разбить на слова
 * Переход динамики: если dp[i] == true, то текст [0...i) мы смогли каким-то образом разбить на слова, а значит
 * можно попытаться разбить текст [i...text.size()) на слова.
 * Где лежит ответ динамики: если dp.back() == true
 */

class PrefixTree {

private:

    struct Node {

        bool is_terminal = false;
        std::vector<std::shared_ptr<Node>> edges;

        Node():
        edges(std::vector<std::shared_ptr<Node>>(26))
        {}

    };

    std::shared_ptr<Node> root_;

public:
    PrefixTree():
            root_(std::make_shared<Node>())
    {}

    PrefixTree(const PrefixTree& other) = delete;
    PrefixTree(PrefixTree&&) = delete;

    explicit PrefixTree(const std::vector<std::string>& list_of_new_strings) {

        root_ = std::make_shared<Node>();

        for (const auto& string : list_of_new_strings) {

            addString(string);

        }

    }

    void addString(const std::string& string) {

        auto current_node = root_;

        for (char character : string) {

            if (!current_node->edges[character - 'a']) {

                current_node->edges[character - 'a'] = std::make_unique<Node>();

            }

            current_node = current_node->edges[character - 'a'];

        }

        current_node->is_terminal = true;

    }

    void findAny(const std::string& text, size_t start_pos, std::vector<bool>& dp) {

        std::vector<size_t> answer;
        auto current_node = root_;
        size_t offset = 0;
        bool mismatch_not_found = true;

        while (mismatch_not_found && (start_pos + offset) < text.size()) {

            char symbol = text[start_pos + offset];

            if (current_node->edges[symbol - 'a']) {

                current_node = current_node->edges[symbol - 'a'];

                if (current_node->is_terminal) {

                    dp[start_pos + offset + 1] = true;

                }

                ++offset;

            } else {

                mismatch_not_found = false;

            }

        }

    }

    [[nodiscard]] bool tryToReadText(const std::string& text) {

        std::vector<bool> dp(text.size() + 1, false);
        dp[0] = true;

        for (size_t i = 0; i < text.size(); ++i) {

            if (dp[i]) {

                findAny(text, i, dp);

            }

        }

        return dp.back();

    }


};

int main() {

    std::string text;

    std::cin >> text;

    size_t number_of_patterns;

    std::cin >> number_of_patterns;

    std::vector<std::string> patterns(number_of_patterns);

    for (auto& pattern : patterns) {

        std::cin >> pattern;

    }

    PrefixTree pt(patterns);

    if (pt.tryToReadText(text)) {

        std::cout << "YES";
        return 0;

    }

    std::cout << "NO";

    return 0;
}
