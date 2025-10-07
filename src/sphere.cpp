#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(Vec3 pos, Color color, float radius) : Object(pos, color), radius(radius) { }

// where <xo, yo, zo> is the origin of the ray, and <xd, yd, yd> is camera ray's direction.
// <a, b, c> are spheres position vector
// (xo + xd*t - a)^2 + (yo + yd*t - b)^2 + (zo + zd*t - c)^2 = r^2
/*
    A = (xd^2 + yd^2 + zd^2)
    B = [2[xd * (xo - a) + yd * (yo - b) + zd *(zo - c)]]
    C = [(xo - a)^2 + (yo - b)^2 + (zo - c^)2 - r^2]
*/

// returns time on ray where the sphere intersects
Hit Sphere::RayIntersect(const Ray3& ray)
{
    // treat sphere as origin
    float ox = ray.pos.x - pos.x;
    float oy = ray.pos.y - pos.y;
    float oz = ray.pos.z - pos.z;

    float a = ray.dir * ray.dir;
    float b = 2*(ray.dir.x * ox + ray.dir.y * oy + ray.dir.z * oz);
    float c = ox * ox + oy * oy + oz * oz - radius * radius;
    
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return Hit();
    discriminant = std::sqrt(discriminant);

    // apply general quadratic formula
    // t = [-B +- sqrt(B^2 - 4AC)] / 2A
    // return smaller value (closer point)
    float t  = (-b - discriminant) / 2 * a;
    
    Vec3 hitPos = ray.PosAtTime(t);

    return Hit(true, t, hitPos, (hitPos - pos).Normalized());
}