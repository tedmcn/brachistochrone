#include "gameobject.h"

//Constructor
Gameobject::Gameobject(){
	v=Vectorobject();
	a=Vectorobject();

	//Always start with acceleration being standard gravity
	float acceleration[3] = {0,0,-9.8};
	a.set(acceleration);
}

//Deconstructor
Gameobject::~Gameobject(){

}



//Different for every child class
void Gameobject::draw(){
}


//
//POSITION
//

//Set the game objects main coordinates
void Gameobject::setP(float* position){
	p[0]=position[0];
	p[1]=position[1];
	p[2]=position[2];
}

//Read the game objects coordinates
float* Gameobject::getP(){
	return p;
}


//
//VELOCITY
//


//Set the velocity of the object
void Gameobject::setV(float* velocity){
	//Load the velocity into a vector object
	Vectorobject velocity_vector = Vectorobject(velocity);
	//Save it
	v = velocity_vector;
}

//Read the velocity of the object
Vectorobject Gameobject::getV(){
	return v;
}

//
//ACCELERATION
//


//Set the Direction of the object
void Gameobject::setA(float* acceleration){
	//Load the acceleration into a vector object
	Vectorobject acceleration_vector = Vectorobject(acceleration);
	//Save it
	a = acceleration_vector;
}

//Read the direction of the object
Vectorobject Gameobject::getA(){
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