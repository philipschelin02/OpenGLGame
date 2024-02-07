#pragma once
#include <corecrt_math.h>

// Goal: Write a Unit Test to test one Vector Class Feature
//        e.g. Vector3(1, 2, 3) + Vector3(4, 5, 6) = Vector3(5, 7, 9)
// Then: Implement the Vector Class Feature
//        e.g. return Vector3(x + other.x, ...
// Do this for Vector3(float, float, float), ==, !=, -V3, V3*float, V3/float, V3+V3, V3-V3,
class Vector3
{
public:
    float x, y, z;

    Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } { }

    //                v this says this function doesnt change OTHER
    bool operator==(const Vector3& other) const { //dis says dis function does not change THIS
        // fix the equal operator implementation DONE
        return x == other.x && y == other.y && z == other.z;
    }

    // TODO:
    Vector3 operator-() const {
        // return new vector where all components are negated
        return Vector3(-x, -y, -z);
    }

    Vector3 operator+(const Vector3& other) const {
        //return vector where components are added
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator*(const Vector3& other) const {
        //return vector where components are multiplied
        return Vector3(x * other.x, y * other.y, z * other.z);
    }

    Vector3 operator*(float k) const {
        //return vector where components are multiplied
        return Vector3(x * k, y * k, z * k);
    }

    Vector3 operator/(float k) const {
        //return vector where components are divided
        return Vector3(x / k, y / k, z / k);
    }

    float Magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    float Vector3 SquareMagnitude() {

    }
    
    static float DotProduct(const Vector3& a, const Vector3& b) { //const exists to prevent you from using "this->". Since it's static theres no need for "const"
        //return dot product of two vectors
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
};