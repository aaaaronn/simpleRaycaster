#include "math.hpp"
#include <cmath>


Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) { }

float Vec3::Magnitude() const
{
    return std::sqrt(x*x+y*y+z*z);
}
float Vec3::SqrMagnitude() const
{
    return x*x+y*y+z*z;
}

Vec3 Vec3::Normalized() const
{
    Vec3 norm = *this * this->Magnitude();
    return *this / this->Magnitude();
}

Vec3 Vec3::Cross(const Vec3& other) const
{
    return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
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

std::ostream& operator<<(std::ostream& os, const Vec3& obj)
{
    os << "<" << obj.x << ", " << obj.y << ", " << obj.z << ">";
    return os;
}

Ray3::Ray3(Vec3 origin, Vec3 dir) : origin(origin), dir(dir) { }

Vec3 Ray3::PosAtTime(float t) const
{
    return (dir * t) + origin;
}