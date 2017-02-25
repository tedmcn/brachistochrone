#ifndef cubeobject_h
#define cubeobject_h

#include <iostream>

class cubeobject{

public:
	cubeobject(float _size, float _position[3],float _color[3]);
	void draw();

	float position[3];
	float color[3]; 
	float size;
};

#endif

