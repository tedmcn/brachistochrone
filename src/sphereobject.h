#ifndef sphereobject_h
#define sphereobject_h


#include <GL/glut.h>
#include <stdlib.h> 
#include <stdio.h>

#include "gameobject.h"
#include "planeobject.h"

class Sphereobject : public Gameobject{

public:
	
	Sphereobject(float r);
	~Sphereobject();

	void apply(Physics p, Planeobject plane);
	void draw();
	bool intersect(Planeobject plane);

protected:
	float radius;
	float previous_diff;

};

#endif