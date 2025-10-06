#include <iostream>
#include <fstream>
#include "sphere.hpp"

// using ppm file format (https://netpbm.sourceforge.net/doc/ppm.html)



#define sizeX 255
#define sizeY 255

#define cameraPos vec3(sizeX/2, sizeY/2, -10)


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
    image << "P6 " << sizeX+1 << " " << sizeY+1 << " 255\n";


    for (int y = 0; y <= sizeY; y++)
    {
        for (int x = 0; x <= sizeX; x++)
        {
            unsigned char rgb[3] = {
                static_cast<unsigned char>((x * 255.0f) / sizeX),
                static_cast<unsigned char>((y * 255.0f) / sizeY),
                0
            };
            image.write(reinterpret_cast<char*>(rgb), 3);
        }
    }

    image.close();
}