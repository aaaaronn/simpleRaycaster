#include "camera.hpp"
#include <cmath>

Camera::Camera(Vec3 pos, float fov, float aspect, float clipPlane) : pos(pos), fov(fov), aspect(aspect), clipPlane(clipPlane)
{
    // create right triangle with fov then convert to hight
    // fov/2 is the angle so get tan of it to get the ratio of halfhight the clipplane, multiply by clipplane and 2 to just get height
    planeHeight = std::tan(fov * 0.5f * degToRad) * clipPlane * 2;
    planeWidth = planeHeight * aspect;

    // bottom left of clipPlane, where to start rays
    bottomLeftLocal = Vec3(-planeWidth/2, -planeHeight/2, clipPlane);

    //std::cout << "height: " << planeHeight << "   width:" << planeWidth << "   bottleft: " << bottomLeftLocal << std::endl;
}

Vec3 Camera::LocalToWorld(float x, float y) const
{
    Vec3 pointLocal = bottomLeftLocal + Vec3(planeWidth * x, planeHeight * y);
    // convert back from local space
    return pos + pointLocal;
}