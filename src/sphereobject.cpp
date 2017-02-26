#include "sphereobject.h"

//Constructor
Sphereobject::Sphereobject(float r){
	radius=r;
}

//Deconstructor
Sphereobject::~Sphereobject(){

}


void Sphereobject::draw(){
	//Add a sphere 
    glPushMatrix();
        glTranslatef(p[0],p[1],p[2]);
        glutSolidSphere(radius,50,50);
    glPopMatrix(); 
}


bool Sphereobject::intersect(){
}