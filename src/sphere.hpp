#pragma once

#include "object.hpp"


class Sphere : public Object
{
public:
    Sphere(Vec3 pos, Color color, float radius);
    Hit RayIntersect(const Ray3& ray) override;
private:
    float radius;
};