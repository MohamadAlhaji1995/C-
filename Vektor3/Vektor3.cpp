#include <iostream>
#include <cmath>

struct Vector3 {
    float x;
    float y;
    float z = 0.f;

    // Addition von zwei Vector3-Objekten
    Vector3 operator+(const Vector3& other) const {
        return Vector3{x + other.x, y + other.y, z + other.z};
    }

    // Multiplikation eines Vector3 mit einem float-Wert (Vector3 * float)
    Vector3 operator*(float scalar) const {
        return Vector3{x * scalar, y * scalar, z * scalar};
    }

    // Multiplikation eines Vector3 mit einem float-Wert (float * Vector3)
    friend Vector3 operator*(float scalar, const Vector3& vec) {
        return scalar * vec ; 
    }

    // Multiplikation und Zuweisung (Vector3 *= float)
    Vector3& operator*=(float scalar) {
        x *= scalar;  //this -> x 
        y *= scalar;  // this -> y
        z *= scalar;  // this -> z
        return *this;
    }
};

int main() {
    auto position = Vector3{0, 0};
    auto velocity = Vector3{1, 2};
    auto delta_time = 0.1f;

    position = position + velocity * delta_time;  //position =  {0,1,0,2,0}
    velocity *= 0.1f;
    position = position + delta_time * velocity;    //{0,01,0,02,0}

    std::cout << position.x << ", "
              << position.y << ", "
              << position.z << "\n";   // neu position = {0.11,0.22,0}

    return 0;
}
