#pragma once
#include <iostream>

struct Vec3
{
    Vec3(float x = 0, float y = 0, float z = 0);
    float Magnitude() const;
    Vec3 Normalized() const;

    
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
    Ray3(Vec3 pos = Vec3(), Vec3 dir = Vec3(0,0,1));
    Vec3 PosAtTime(float t) const;

    Vec3 pos;
    Vec3 dir;

};

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
    Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0);
    unsigned char r, g, b;
};

class Object
{
public:
    Object(Vec3 pos, Color color);
    virtual Hit RayIntersect(const Ray3& ray) = 0;

    Color color;
protected:
    Vec3 pos;
};


class Camera
{
public:
    Camera(Vec3 pos, Vec3 rot, float fov, float aspect, float clipPlane);
    // screen space, both x and y are between 0.0-1.0
    Vec3 LocalToWorld(float x, float y);
    Vec3 pos;
    Vec3 rot;

private:
    float planeHeight, planeWidth;
    Vec3 bottomLeftLocal;

    float fov;
    float aspect;
    float clipPlane;
};