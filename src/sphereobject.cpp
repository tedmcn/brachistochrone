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
        glTranslated(0,1,-6);
        glutSolidSphere(1,50,50);
    glPopMatrix(); 
}


bool Sphereobject::intersect(){
}