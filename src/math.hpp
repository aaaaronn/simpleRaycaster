#pragma once
#include <iostream>

#define M_PI 3.141592f
#define degToRad (M_PI / 180.f)

struct Vec3
{
    Vec3(float x = 0, float y = 0, float z = 0);

    float Magnitude() const;
    float SqrMagnitude() const;
    Vec3 Normalized() const;
    Vec3 Cross(const Vec3& other) const;

    
    float operator*(const Vec3& other) const;

    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;
    
    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Vec3& obj);
    
    float x, y, z;
};

struct Ray3
{
    Ray3(Vec3 origin = Vec3(), Vec3 dir = Vec3(0,0,1));
    Vec3 PosAtTime(float t) const;

    Vec3 origin;
    Vec3 dir;
};