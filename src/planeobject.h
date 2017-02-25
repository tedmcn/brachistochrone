
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

};