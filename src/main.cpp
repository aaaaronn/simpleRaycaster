#include <iostream>
#include <fstream>
#include <vector>

#include "sphere.hpp"
#include "camera.hpp"



// size of the output image, in pixels
#define sizeX 1920
#define sizeY 1080

// Cameras vertical FOV
#define FOV 50


int main()
{
    // light direction for lambertian shading
    Vec3 LightDir(0.0f, 2.0f, -1.0f);
    LightDir = LightDir.Normalized();

    std::vector<Sphere> objects;

    objects.emplace_back(Vec3(2, 4.5f,10), Color::green, 4);
    objects.emplace_back(Vec3(5, -0.5f,4), Color::purple, 3);
    objects.emplace_back(Vec3(0,0.55f,0), Color::red, 0.1);
    objects.emplace_back(Vec3(-6,0,5), Color::blue, 5);
    objects.emplace_back(Vec3(0,0,5), Color::yellow, 4);


    Camera cam(Vec3(0, 0, -10), FOV, float(sizeX)/sizeY, 10.0f);


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

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            Color col = Color();
            // flip y to render starting from top left (to support ppm)
            float yf = 1.0f - y / (sizeY-1.0f);
            // shoot ray from camera to current pixel
            Ray3 ray(cam.pos, (cam.LocalToWorld(x/(sizeX-1.0f), yf) - cam.pos).Normalized());

            Sphere* closestSphere = nullptr;
            float closestTime = 99999.0f;
            Vec3 closestNormal;

            // check for intersections with ray
            for (Sphere& obj : objects)
            {
                Hit hit = obj.RayIntersect(ray);
                if (hit.hit)
                {
                    // because ray is normalized we can use time which is faster than magnitude
                    if (hit.time < closestTime)
                    {
                        closestTime = hit.time;
                        closestSphere = &obj;
                        closestNormal = hit.normal;
                    }
                }
            }
            if (closestSphere != nullptr)
                // apply lambertian shading, set min brightness using std::max
                col = closestSphere->color * std::max(0.225f, closestNormal * LightDir);
            
            
            image.write(reinterpret_cast<char*>(&col), 3);
        }
    }

    image.close();
}