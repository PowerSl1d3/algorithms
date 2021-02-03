#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

std::vector<int16_t> neighbors(const std::vector<std::vector<int16_t>>& matrix, uint16_t i, uint16_t j) {

    std::vector<int16_t> answer;

    if (i > 0) {
        answer.push_back(matrix[i-1][j]);
    }
    if (i < static_cast<uint16_t>(matrix.size() - 1)) {
        answer.push_back(matrix[i+1][j]);
    }
    if (j > 0) {
        answer.push_back(matrix[i][j-1]);
    }
    if (j < static_cast<uint16_t>(matrix[i].size() - 1)) {
        answer.push_back(matrix[i][j+1]);
    }

    std::sort(answer.begin(), answer.end());
    return answer;
}

int main() {

    uint16_t n, m;

    std::vector<std::vector<int16_t>> matrix;

    std::cin >> n >> m;

    matrix.assign(n, std::vector<int16_t>(m));

    for (uint16_t i = 0; i < n; i++) {
        for (uint16_t j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    uint16_t i, j;

    std::cin >> i >> j;

    for (int16_t& element : neighbors(matrix, i, j)) {
        std::cout << element << ' ';
    }

    return 0;
}
