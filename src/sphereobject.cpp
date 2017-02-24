#include "sphereobject.h"

//Constructor
Sphereobject::Sphereobject(){

}

//Deconstructor
Sphereobject::~Sphereobject(){

}


void Sphereobject::draw(){
	//Add a sphere 
    glPushMatrix();
        glTranslatef(p[0],p[1],p[2]);
        glutSolidSphere(1,50,50);
    glPopMatrix(); 
}


bool Sphereobject::intersect(){
}