#include <iostream>
#include <vector>

void sort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec.size() - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    auto data = std::vector<int>{0, 7, 9, 5, 8, 1, 2, 4, 3, 6};

    sort(data);

    for (auto& e : data) {
        std::cout << e << " ";
    }
}
