#include "object.hpp"
#include <cmath>
#define degToRad (3.141592f / 180.f)


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

std::ostream& operator<<(std::ostream& os, const Vec3& obj)
{
    os << "<" << obj.x << ", " << obj.y << ", " << obj.z << ">";
    return os;
}

Ray3::Ray3(Vec3 pos, Vec3 dir) : pos(pos), dir(dir) { }

Vec3 Ray3::PosAtTime(float t) const
{
    return (dir * t) + pos;
}

Hit::Hit(bool hit, float time, Vec3 point, Vec3 normal) : hit(hit), time(time), point(point), normal(normal) { }

Object::Object(Vec3 pos, Color color) : pos(pos), color(color) { }

Camera::Camera(Vec3 pos, Vec3 rot, float fov, float aspect, float clipPlane) : pos(pos), rot(rot), fov(fov), aspect(aspect), clipPlane(clipPlane)
{
    // create right triangle with fov then convert to hight
    // fov/2 is the angle so get tan of it to get the ratio of halfhight the clipplane, multiply by clipplane and 2 to just get height
    planeHeight = std::tan(fov * 0.5f * degToRad) * clipPlane * 2;
    planeWidth = planeHeight * aspect;

    // bottom left of clipPlane, where to start rays
    bottomLeftLocal = Vec3(-planeWidth/2, -planeHeight/2, clipPlane);
    std::cout << "hight: " << planeHeight << "   width:" << planeWidth << "   bottleft: " << bottomLeftLocal << std::endl;
}

Vec3 Camera::LocalToWorld(float x, float y)
{
    Vec3 pointLocal = bottomLeftLocal + Vec3(planeWidth * x, planeHeight * y);
    return pos + pointLocal;
}

Color::Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) { }