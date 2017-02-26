#ifndef planeobject_h
#define planeobject_h

#include <GL/glut.h>
#include <stdlib.h> 
#include <stdio.h>

#include "gameobject.h"


class Planeobject : public Gameobject{

public:
	
	Planeobject();
	~Planeobject();


	void draw();
	bool intersect();

	void setN(float* normal);
	Vectorobject getN();

protected:
	GLfloat *scale;
	Vectorobject normal;
};

#endif