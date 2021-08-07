#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long) numbers[first] * numbers[second]);
        }
    }

    return max_product;
}


long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int max_index_1 = 0;
    int max_index_2 = 0;

    for (int first = 0; first < n; ++first) {
        if (numbers[first] > numbers[max_index_1]) {
            max_index_1 = first;
        }
    }

    for (int second = 0; second < n; ++second) {
        // std::cout << "second " << second << "\n";
        // std::cout << "max_index_2 " << max_index_2 << "\n";
        // std::cout << "numbers[second] " << numbers[second] << "\n";
        // std::cout << "numbers[max_index_2] " << numbers[max_index_2] << "\n";
        // std::cout << "max_index_1 " << max_index_1 << "\n";
        // std::cout << "max_index_1 " << max_index_1 << "\n";
        // std::cout << (max_index_2 == 0 || numbers[second] > numbers[max_index_2]) << "\n";
        // std::cout << (second != max_index_1) << "\n";
        
        if ((max_index_2 == 0 || numbers[second] > numbers[max_index_2]) && (second != max_index_1)) {
            // std::cout << "INNER" << "\n";
            max_index_2 = second;
        }
    }

    max_product = (long long) numbers[max_index_1] * numbers[max_index_2];

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
