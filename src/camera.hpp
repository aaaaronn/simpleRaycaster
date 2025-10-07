#pragma once
#include "math.hpp"

class Camera
{
public:
    Camera(Vec3 pos, float fov, float aspect, float clipPlane);
    // screen space, both x and y are between 0.0-1.0
    Vec3 LocalToWorld(float x, float y);
    Vec3 pos;
    
private:
    float planeHeight, planeWidth;
    Vec3 bottomLeftLocal;

    float fov;
    float aspect;
    float clipPlane;
};