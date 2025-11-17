#include "Utils.h"
#include <algorithm>
#include <iostream>

void Utils::sortVectors(std::vector<Vector>& arr) {
    std::sort(arr.begin(), arr.end(),
              [](const Vector& a, const Vector& b) {
                  return a.length() < b.length();
              });
}

double Utils::averageLength(const std::vector<Vector>& arr) {
    double sum = 0;
    for (const auto& v : arr)
        sum += v.length();
    return sum / arr.size();
}

void Utils::printArray(const std::vector<Vector>& arr) {
    for (const auto& v : arr)
        std::cout << v << " | length = " << v.length() << "\n";
}
