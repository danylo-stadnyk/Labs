#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector {
private:
    struct Components {
        double x, y, z;
    };

    Components data;

public:
    Vector();
    Vector(double x, double y, double z);
    ~Vector();

    double length() const;

    
    bool operator<=(const Vector& other) const;

    
    Vector operator+(const Vector& other) const;

    
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend std::istream& operator>>(std::istream& in, Vector& v);
};

#endif
