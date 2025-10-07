#pragma once

#include "object.hpp"


class Sphere : public Object
{
public:
    Sphere(Vec3 pos = Vec3(), Color color = Color::green, float radius = 1.0f);
    Hit RayIntersect(const Ray3& ray) override;

private:
    float radius;
};