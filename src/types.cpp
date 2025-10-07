#include "types.hpp"

Hit::Hit(bool hit, float time, Vec3 point, Vec3 normal) : hit(hit), time(time), point(point), normal(normal) { }

Color::Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) { }

Color Color::operator*(float scalar)
{
    return Color(r * scalar, g * scalar, b * scalar);
}


const Color Color::red = Color(255, 0, 0);
const Color Color::green = Color(0, 255, 0);
const Color Color::blue = Color(0, 0, 255);
const Color Color::yellow = Color(255, 255, 0);
const Color Color::cyan = Color(0, 255, 255);
const Color Color::purple = Color(255, 0, 255);