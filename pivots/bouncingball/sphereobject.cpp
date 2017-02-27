/*
editted by CS Goh
23 Feb 2017
*/
#include <iostream>
#include <cstring>
#include "sphereobject.h"
#include <GL/glut.h>
using namespace std;

sphereobject::sphereobject(float _radius, float *_position, float *_color){
	//memcpy to cpy array(destination,source,bytes)
    	memcpy(position, _position, sizeof(position));
	memcpy(color, _color, sizeof(color));
	radius = _radius;  
	float a[3] = {7,3,1};
	float b[3] = {2,0,0};
	//optional paramters to 0;	
	memcpy(velocity, a, 3*sizeof(float));
	memcpy(accleration, b, 3*sizeof(float));
	cout << accleration[0] << "- "<<accleration[1]<<"-" <<accleration[2] <<endl;
	cout <<"sphere of radius "<< radius << "created"<<endl;
}

void sphereobject::draw(){
	print_info(); 	
	update(glutGet(GLUT_ELAPSED_TIME)); //need to verify whether the time is always consistent from within this object.

	//Draw in red
	glColor3d(color[0],color[1],color[2]); 	

	//Add a sphere 
	glPushMatrix();
		glTranslated(position[0], position[1], position[2]);
		glutSolidSphere(radius,50,50); // 50,50 by default, not important in our code. 
	glPopMatrix();
}


bool sphereobject::update_velocity(double _velocity[3]){
	memcpy(velocity, _velocity, 3*sizeof(float));
	return 1;
}

bool sphereobject::update_accleration(double _accleration[3]){
	memcpy(accleration, _accleration, 3*sizeof(float));
	return 1;
}

void sphereobject::print_info(){
	cout << "Positional info:	" << position[0] << " : "<< position[1]<< ":" <<position[2] <<endl;
	cout << "Velocity info:		" << velocity[0] << " : "<< velocity[1]<< ":" <<velocity[2] <<endl;
	cout << "Accleration info:	" << accleration[0] << " : "<< accleration[1]<< ":" <<accleration[2] <<endl <<endl;;
}

bool sphereobject::intersect(){

}

void sphereobject::update(float time_now){
	
	float time_difference = (time_now - last_updated_time) / 1000.0; // time difference in seconds
	last_updated_time = time_now; 

	for(int i=0;i<3;i++){
		position[i] += velocity[i] * time_difference; // update position

		velocity[i] += accleration[i] * time_difference; // update accleration
		cout<<"update"<<time_difference<<endl;	
	}
}












