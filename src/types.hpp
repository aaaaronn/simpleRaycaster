#pragma once
#include "math.hpp"

struct Hit
{
    Hit(bool h = false, float t = -1.f, Vec3 point = Vec3(), Vec3 normal = Vec3());
    
    bool hit;
    float time;
    Vec3 point;
    Vec3 normal;
};

struct Color
{
    // store as a char instead of a float/int to use with ppm file (only accepts one byte)
    constexpr Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0) : r(r), g(g), b(b) { }
    unsigned char r, g, b;

    constexpr Color operator*(float scalar) const;


    static const Color red;
    static const Color green;
    static const Color blue;
    static const Color yellow;
    static const Color cyan;
    static const Color purple;
};