#include <iostream>
#include <fstream>
#include <vector>

#include "sphere.hpp"
#include "plane.hpp"
#include "camera.hpp"



// size of the output image, in pixels
#define sizeX 1920
#define sizeY 1080

// vertical FOV
#define FOV 50
#define CAM_POS Vec3(0, 0, -10)
#define CLIP_PLANE_DIST 10

#define BACKGROUND_COLOR Color(0,0,0)
#define LIGHT_POS Vec3(1.0f, 1.0f, -1.0f)
#define MIN_BRIGHTNESS 0.225f


int main()
{
    std::vector<std::shared_ptr<Object>> objects = {
        std::make_shared<Sphere>(Vec3(2, 4.5f,10), 4, Color::green),
        std::make_shared<Sphere>(Vec3(5, -0.5f,4), 3, Color::purple),
        std::make_shared<Sphere>(Vec3(0,0.55f,0), 0.1f, Color::red),
        std::make_shared<Sphere>(Vec3(-6,0,5), 5, Color::blue),
        std::make_shared<Sphere>(Vec3(0,0,5), 4, Color::yellow),
        std::make_shared<Plane>(Vec3(-7,0,0), 3, 3, Vec3(1, 0, -0.1f).Normalized(), Color::cyan),
        std::make_shared<Plane>(Vec3(-7,1.5f,0), 5, 5, Vec3(0.5f,-1, -0.1f).Normalized(), Color::red)
    };
    
    Camera cam(CAM_POS, FOV, float(sizeX)/sizeY, CLIP_PLANE_DIST);

    // light direction
    Vec3 LightPos = LIGHT_POS.Normalized();


    // create a ppm
    // using ppm file format (https://netpbm.sourceforge.net/doc/ppm.html)
    std::ofstream image("image.ppm", std::ios_base::binary);

    if (!image.is_open())
    {
        std::cerr << "Error opening image" << std::endl;
        return 1;
    }
    // ppm filetype magic number, width, height, maxval
    image << "P6 " << sizeX << " " << sizeY << " 255\n";

    // flip y to render starting from top left (to support .ppm format)
    for (int y = sizeY - 1; y >= 0; y--)
    {
        for (int x = 0; x < sizeX; x++)
        {
            Color col = BACKGROUND_COLOR;
            // shoot ray from camera towards current pixel
            Ray3 ray(cam.pos, (cam.LocalToWorld(x/(sizeX-1.0f), y/(sizeY-1.0f)) - cam.pos).Normalized());

            std::shared_ptr<Object> closestObj;
            float closestTime = 1.0E10f;
            Vec3 closestNormal;

            // check for intersections with ray
            for (auto&& obj : objects)
            {
                Hit hit = obj->RayIntersect(ray);
                if (hit.hit)
                {
                    // because ray is normalized we can use time which is faster than magnitude
                    if (hit.time < closestTime)
                    {
                        closestTime = hit.time;
                        closestObj = obj;
                        closestNormal = hit.normal;
                    }
                }
            }
            if (closestObj)
                // apply lambertian shading
                col = closestObj->color * std::max(MIN_BRIGHTNESS, closestNormal * LightPos);
            
            
            image.write(reinterpret_cast<char*>(&col), 3);
        }
    }
    image.close();
}