#ifndef planeobject_h
#define planeobject_h

#include <GL/glut.h>
#include <stdlib.h> 
#include <stdio.h>

#include "gameobject.h"


class Planeobject : public Gameobject{

public:
	
	Planeobject(float* n, float* s, float* r);
	~Planeobject();


	void draw();
	bool intersect();

	void setN(float* normal);
	Vectorobject getN();

protected:
	GLfloat *scale;
	float *rotate;
	Vectorobject normal;
};

#endif