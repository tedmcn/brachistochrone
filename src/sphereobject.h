#include <GL/glut.h>
#include <stdlib.h> 
#include <stdio.h>

#include "gameobject.h"

class Sphereobject : public Gameobject{

public:
	
	Sphereobject();
	~Sphereobject();


	void draw();
	bool intersect();

};