#include <iostream>
#include <vector>
#include "Vector.h"
#include "Utils.h"

int main() {
    int n;
    std::cout << "How many vectors? ";
    std::cin >> n;

    std::vector<Vector> arr(n);

    std::cout << "\n=== Input vectors ===\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Vector " << i + 1 << ":\n";
        std::cin >> arr[i];
    }

    std::cout << "\n=== Original array ===\n";
    Utils::printArray(arr);

    // Сортування
    Utils::sortVectors(arr);

    std::cout << "\n=== Sorted by length ===\n";
    Utils::printArray(arr);

    // Середня довжина
    double avg = Utils::averageLength(arr);
    std::cout << "\nAverage length = " << avg << "\n";

    // Демонстрація операторів
    std::cout << "\n=== Operators demo ===\n";
    std::cout << "v1 <= v2 : " << (arr[0] <= arr[1] ? "true" : "false") << "\n";

    Vector sum = arr[0] + arr[1];
    std::cout << "v1 + v2 = " << sum << "\n";

    return 0;
}
