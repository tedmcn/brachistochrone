#include "gameobject.h"
#include "planeobject.h"
//Constructor
Gameobject::Gameobject(){
	gravity=-9.8;
}

//Deconstructor
Gameobject::~Gameobject(){

}



//Different for every child class
void Gameobject::draw(){
}


void Gameobject::print(){
	float* temp_position= getP();
	float* temp_velocity = getV().get();
	float* temp_acceleration = getA().get();
	printf("\n");
	printf("position = %f - %f - %f\n", temp_position[0],temp_position[1],temp_position[2]);
	printf("velocity = %f - %f - %f\n", temp_velocity[0],temp_velocity[1],temp_velocity[2]);
	printf("acceleration = %f - %f - %f\n", temp_acceleration[0],temp_acceleration[1],temp_acceleration[2]);
	
	// printf("%p - %p - %p\n",&temp_position[0],&temp_velocity[0],&temp_acceleration[0]);
	// printf("%p - %p - %p\n",&temp_position[1],&temp_velocity[1],&temp_acceleration[1]);
	// printf("%p - %p - %p\n",&temp_position[2],&temp_velocity[2],&temp_acceleration[2]);

	printf("\n");
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

void Gameobject::setP(float x, float y, float z){
	p[0]=x;
	p[1]=y;
	p[2]=z;
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


void Gameobject::apply(Physics p){
}



// //Return true if the two objects have points where they overlap
// bool Gameobject::intersect(Gameobject obj){
// 	return false;
// }

// //Returns the object that is directly below this object (any distance)
// Gameobject Gameobject::below(){
// 	return null;
// }