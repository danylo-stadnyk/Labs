#include "Vector.h"

Vector::Vector() : data{0, 0, 0} {}

Vector::Vector(double x, double y, double z) {
    data.x = x;
    data.y = y;
    data.z = z;
}

Vector::~Vector() {}

double Vector::length() const {
    return std::sqrt(data.x*data.x + data.y*data.y + data.z*data.z);
}

bool Vector::operator<=(const Vector& other) const {
    return this->length() <= other.length();
}

Vector Vector::operator+(const Vector& other) const {
    return Vector(
        data.x + other.data.x,
        data.y + other.data.y,
        data.z + other.data.z
    );
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    out << "(" << v.data.x << ", " << v.data.y << ", " << v.data.z << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v) {
    std::cout << "x: "; in >> v.data.x;
    std::cout << "y: "; in >> v.data.y;
    std::cout << "z: "; in >> v.data.z;
    return in;
}
