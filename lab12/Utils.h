#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "Vector.h"

namespace Utils {
    void sortVectors(std::vector<Vector>& arr);
    double averageLength(const std::vector<Vector>& arr);
    void printArray(const std::vector<Vector>& arr);
}

#endif
