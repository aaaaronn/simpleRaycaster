#include "types.hpp"
#include <algorithm>

Hit::Hit(bool hit, float time, Vec3 point, Vec3 normal) : hit(hit), time(time), point(point), normal(normal) { }

Color Color::operator*(float scalar) const
{
    return Color(std::clamp<int>(r * scalar, 0, 255), std::clamp<int>(g * scalar, 0, 255), std::clamp<int>(b * scalar, 0, 255));
}


const Color Color::red = Color(255, 0, 0);
const Color Color::green = Color(0, 255, 0);
const Color Color::blue = Color(0, 0, 255);
const Color Color::yellow = Color(255, 255, 0);
const Color Color::cyan = Color(0, 255, 255);
const Color Color::purple = Color(255, 0, 255);