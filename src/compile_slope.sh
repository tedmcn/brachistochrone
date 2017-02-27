#Ted McNulty
#2/27/17
#ENGR 2535
##
##Compiles and runs the sloped simulation
##

#include each .cpp file in the line below

g++ -o slope vectorobject.cpp physics.cpp planeobject.cpp gameobject.cpp sphereobject.cpp slope.cpp -lglut -lGLU -lGL -lm && ./slope