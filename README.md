# Simple Raycaster

A simple raycaster written entirely in C++, only using standard libraries.<br>
Implements [lambertian shading](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/diffuse-lambertian-shading.html) and renders spheres<br>
outputs images as [.ppm](https://netpbm.sourceforge.net/doc/ppm.html) files

![Sample render](/images/sampleRender.png)

# Building

Compile using g++ or the provided makefile

```
g++ -o raycast ./src/*.cpp
./raycast
```

Generates an `image.ppm` in the project directory.
 - [Gimp](https://www.gimp.org/) can be used to view the .ppm