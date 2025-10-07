#include <iostream>
#include <fstream>
#include "sphere.hpp"

// using ppm file format (https://netpbm.sourceforge.net/doc/ppm.html)



#define sizeX 120
#define sizeY 120


int main()
{
    // create a ppm
    std::ofstream image("image.ppm", std::ios_base::binary);

    if (!image.is_open())
    {
        std::cerr << "Error opening image" << std::endl;
        return 1;
    }
    // ppm filetype magic number, width, height, maxval
    image << "P6 " << sizeX << " " << sizeY << " 255\n";


    Sphere obj(Vec3(0,0,0), Color(255,0,0), 3);


    Camera cam(Vec3(0, 0, -10), Vec3(), 70, sizeX/sizeY, 10.0f);

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            Color col = Color();
            // flip y to render top left
            float yf = 1.0f - y / (1.0f * (sizeY-1));
            Vec3 rayPos = cam.LocalToWorld(x/(1.0f*(sizeX-1)), yf);
            //std::cout << rayPos << std::endl;
            Ray3 ray(rayPos, (rayPos - cam.pos).Normalized());
            //std::cout << ray.dir << std::endl;

            Hit hit = obj.RayIntersect(ray);
            if (hit.hit)
            {
                col = obj.color;
            }
            
            image.write(reinterpret_cast<char*>(&col), 3);
        }
    }

    image.close();
}