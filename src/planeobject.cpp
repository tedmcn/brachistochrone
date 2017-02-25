#include "planeobject.h"

//Constructor
Planeobject::Planeobject(){

}

//Deconstructor
Planeobject::~Planeobject(){

}


void Planeobject::draw(){
	GLfloat scale[] = {10,0.1,10};

	//Add a sphere 
    glPushMatrix();
    	glScalef(scale[0],scale[1],scale[2]);
        glTranslatef(p[0],p[1],p[2]);
        glutSolidCube(1);
    glPopMatrix(); 
}


bool Planeobject::intersect(){
}