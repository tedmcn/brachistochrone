## OpenGL Physics Engine

### Description

  This code is a physics engine written in C++, which handels gravity, terminal velocity, collision between a plane and a sphere, kinematic physics and projectile motion. It is written to work with OpenGL and GL Utility Toolkit. There are two simulations prebuilt in the src folder. One, flat.cpp, is a ball bouncing on a flat plane, and the other, slope.cpp, is a ball bouncing down a slope. 

### Authors

[Ted McNulty](tedmcnulty.com)

Cleophas Kalekem

Chong Swee

Jiaxuan (Amy) Wu

Help from [OpenGL](https://www.opengl.org) and [GLUT](https://www.opengl.org/resources/libraries/glut/).

### Getting Started
You will need to have GLUT installed on your machine:

                      freeglut3-dev
                      freeglut3
       
To install the dependecies you will need, run
                     
                      ./install_libraries.sh

### Usage

Next you can run either the flat simluation or the slope simulation with:

                      ./compile_flat.sh
or
                      
                      ./compile_slope.sh

Which will both compile and run the program for you.

### License

MIT License

Copyright (c) [2017] [Ted McNulty]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
