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
    
    
    
    float x, y, z;
};

struct Ray3
{
    Ray3(Vec3 pos = Vec3(), Vec3 dir);
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

class Object
{
public:
    Object(Vec3 pos);
    virtual Hit RayIntersect(const Ray3& ray) = 0;
protected:
    Vec3 pos;
};