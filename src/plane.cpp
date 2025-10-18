#include "plane.hpp"

Plane::Plane(Vec3 pos, float width, float height, Vec3 normal, Color color)
     : Object(pos, color), width(width), height(height), normal(normal), d(-(normal * pos)), u(normal.Cross(Vec3(0,0,1)))
{
    v = normal.Cross(u);
}


// plane equation P * N + d = 0;
// p being point, N being normal, d being offset from known point
Hit Plane::RayIntersect(const Ray3& ray) const
{
    float den = ray.dir * normal;
    // exclude perpenducular
    if (den == 0) return Hit();

    // isolate t
    float t = -(ray.origin * normal + d) / den;

    // dont hit behind ray
    if (t < 0) return Hit();

    
    
    Vec3 relativePos = (ray.PosAtTime(t) - pos);
    float x = relativePos * u;
    float y = relativePos * v;

    // stay within bounds
    if (x > width/2 ||
        x < -width/2 ||
        y > height/2 ||
        y < -height/2
    ) return Hit();

    return Hit(true, t, ray.PosAtTime(t), normal);
}