#pragma once
#include "math.hpp"
#include "types.hpp"

class Object
{
public:
    Object(Vec3 pos, Color color);
    virtual Hit RayIntersect(const Ray3& ray) = 0;

    Color color;
protected:
    Vec3 pos;
};