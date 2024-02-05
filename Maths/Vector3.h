#pragma once
class Vector3
{
public:
    float x, y, z;
    Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } { }

    bool operator==(const Vector3& other) const {
        // fix the equal operator implementation
        return x == other.x;
    }
};