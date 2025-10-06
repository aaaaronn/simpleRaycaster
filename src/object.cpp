#include "object.hpp"
#include <cmath>

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) { }

float Vec3::Magnitude() const
{
    return std::sqrt(x*x+y*y+z*z);
}

Vec3 Vec3::Normalized() const
{
    Vec3 norm = *this * this->Magnitude();
    return *this / this->Magnitude();
}

float Vec3::operator*(const Vec3& other) const
{
    // dot product
    return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::operator*(float scalar) const
{
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(float scalar) const
{
    return Vec3(x / scalar, y / scalar, z / scalar);
}

Vec3 Vec3::operator+(const Vec3& other) const
{
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const
{
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Ray3::Ray3(Vec3 pos, Vec3 dir) : pos(pos), dir(dir) { }

Vec3 Ray3::PosAtTime(float t) const
{
    return (dir * t) + pos;
}

Hit::Hit(bool hit, float time, Vec3 point, Vec3 normal) : hit(hit), time(time), point(point), normal(normal) { }

Object::Object(Vec3 pos) : pos(pos) {}