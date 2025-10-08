#pragma once

#include "object.hpp"


class Sphere : public Object
{
public:
    Sphere(Vec3 pos = Vec3(), float radius = 1.0f, Color color = Color::green);
    Hit RayIntersect(const Ray3& ray) override;

private:
    float radius;
};