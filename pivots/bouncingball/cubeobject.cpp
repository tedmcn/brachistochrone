/*
	Creates a cube 
	Fixed postion 
*/
#include <iostream>
#include <cstring>
#include "cubeobject.h"
#include <GL/glut.h>
cubeobject::cubeobject(float _size, float _position[3],float _color[3]){
	size =_size;
	memcpy(position, _position, sizeof(position));
	memcpy(color, _color, sizeof(color));
}


void cubeobject::draw(){
	//Draw in red
	//glColor3d(color[0],color[1],color[2]); 	
	glPushMatrix();
     	glEnable (GL_BLEND); 
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 	
	glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
	//glDisable(GL_BLEND);
	//Add a sphere 

		glTranslated(position[0], position[1], position[2]);
		glutSolidCube(size); 


	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);	
glPopMatrix();
}
/*
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
glutSolidSphere(0.10, 50, 50);
 
glDisable(GL_BLEND);

glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);*/
