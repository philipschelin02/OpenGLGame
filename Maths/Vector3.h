#pragma once
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
};