#include "object.hpp"


class Sphere : public Object
{
public:
    Sphere(Vec3 pos, float radius);
    Hit RayIntersect(const Ray3& ray) override;
private:
    float radius;
};