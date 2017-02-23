#include "gameobject.h"

//Constructor
Gameobject::Gameobject(){

}

//Deconstructor
Gameobject::~Gameobject(){

}

//Set the velocity of the object
void Gameobject::setV(float velocity){
	v = velocity;
}

//Read the velocity of the object
float Gameobject::getV(){
	return v;
}

//Set the game objects main coordinates
void Gameobject::setP(float x1, float y1, float z1){
	p[0]=x1;
	p[1]=y1;
	p[2]=z1;
}

//Read the game objects coordinates
float* Gameobject::getP(){
	return p;
}

//Set the Direction of the object
void Gameobject::setD(float x, float y, float z){
	d[0]=x;
	d[1]=y;
	d[2]=z;
}

//Read the direction of the object
float* Gameobject::getD(){
	return d;
}

//Different for every child class
void Gameobject::draw(){
}

//Set the Direction of the object
void Gameobject::setA(float x, float y, float z){
	a[0]=x;
	a[1]=y;
	a[2]=z;
}

//Read the direction of the object
float* Gameobject::getA(){
	return a;
}



// //Return true if the two objects have points where they overlap
// bool Gameobject::intersect(Gameobject obj){
// 	return false;
// }

// //Returns the object that is directly below this object (any distance)
// Gameobject Gameobject::below(){
// 	return null;
// }