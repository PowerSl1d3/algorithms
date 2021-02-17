#include <iostream>
#include <vector>

int main() {

    int rows, columns;
    std::vector<std::vector<int>> matrix;

    std::cin >> rows >> columns;

    matrix.assign(rows, std::vector<int>(columns));

    for (std::vector<int>& row : matrix) {
        for (int& element : row) {
            std::cin >> element;
        }
    }

    for (size_t j = 0; j < columns; ++j) {
        for (size_t i = 0; i < rows; ++i) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
