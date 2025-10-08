#pragma once

#include "object.hpp"


class Plane : public Object
{
public:
    Plane(Vec3 pos = Vec3(0,0,0), float width = 9999, float height = 9999, Vec3 normal = Vec3(0,1,0), Color color = Color::green);
    Hit RayIntersect(const Ray3& ray) override;

private:
    float width, height;
    Vec3 normal;
    float d;
    Vec3 u, v;
};