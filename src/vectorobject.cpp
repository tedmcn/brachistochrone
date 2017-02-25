#include "vectorobject.h"
#include <stdlib.h>

Vectorobject::Vectorobject(float* c){
	coordinates = (float *)malloc(sizeof(float)*3);

	coordinates[0]=c[0];
	coordinates[1]=c[1];
	coordinates[2]=c[2];
}


Vectorobject::Vectorobject(){
	
	coordinates = (float *)malloc(sizeof(float)*3);

	coordinates[0]=0;
	coordinates[1]=0;
	coordinates[2]=0;
}

Vectorobject::~Vectorobject(){

}


//Returns the vector represented in degrees as 2 floats from 0-360
//
//The degree of a vector of {0,0,0} should be null because it is not pointing
//anywhere. 
//
//The first float representing degree should represent x and z axies 
//(ie the horozontal ring around a sphere) and the second float should
//represent the y and z axies (ie around the sphere vertically)
float* Vectorobject::toDegree(){

}

float* Vectorobject::get(){
    return coordinates;
}

void Vectorobject::set(float* c){
    coordinates[0]=c[0];
    coordinates[1]=c[1];
    coordinates[2]=c[2];
}

//Averages two different vectors
//
//The average of {0,1,0} and {1,0,0} (a vector going straigh up and straight 
//on the x axis) should be {1,1,0} because it is going in between the straight
//up and straight to the side vectors, resulting in a x=y vector.
Vectorobject Vectorobject::average(Vectorobject v){
    
    float x1 = (v.coordinates[0]+coordinates[0])/2;
    float y1 = (v.coordinates[1]+coordinates[1])/2;
    float z1 = (v.coordinates[2]+coordinates[2])/2;
    float coords[3]={x1,y1,z1};
    Vectorobject new_v = Vectorobject(coords);
    return new_v;
}
