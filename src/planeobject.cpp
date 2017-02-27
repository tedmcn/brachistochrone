#include "planeobject.h"

//Constructor
Planeobject::Planeobject(float* n, float* s, float* r){

	int i;
	float temp[3];

	scale = (float *)malloc(sizeof(GLfloat)*3);
	rotate = (float *)malloc(sizeof(float)*3);

	for(i=0;i<3;i++){
		scale[i]=s[i];
		temp[i]=n[i];
		rotate[i]=r[i];
	}

	Vectorobject norm = Vectorobject(temp);
	normal=norm;
}

//Deconstructor
Planeobject::~Planeobject(){

}


void Planeobject::setN(float* n){
	Vectorobject normal_vector = Vectorobject(n);
	//Save it
	normal = normal_vector;
}

Vectorobject Planeobject::getN(){
	return normal;
}

void Planeobject::draw(){

	//Add a spher0
    glPushMatrix();
    	glRotatef(45,rotate[0],rotate[1],rotate[2]);
    	glScalef(scale[0],scale[1],scale[2]);	//Scale it from a cube into a plane (size)
        glTranslatef(p[0],p[1],p[2]);			//Move it to where it needs to be
        glutSolidCube(1);						// Make the cube (size 1);
    glPopMatrix(); 
}


bool Planeobject::intersect(){
}