# Simple Raycaster

A simple raycaster written entirely in C++, using only standard libraries.<br>
- Implements [lambertian shading](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/diffuse-lambertian-shading.html) and renders spheres and planes
- outputs images as [.ppm](https://netpbm.sourceforge.net/doc/ppm.html) files

![Sample render featuring multicolored spheres and some planes](/images/sampleRender.png)

# Building

Compile using g++ or the provided makefile

```
g++ -o raycast ./src/*.cpp
./raycast
```

Generates an `image.ppm` in the project directory.
- [Gimp](https://www.gimp.org/) can be used to view the .ppm

# Usage

Adjust the `#define`'s at the top of [main.cpp](src/main.cpp) to your desire<br>
Add/edit/remove objects with the [objects](src/main.cpp#L27) vector in main
