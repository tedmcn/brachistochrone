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
