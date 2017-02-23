#ifndef vectorobject_h
#define vectorobject_h
#endif

//Averages two different vectors
//
//The average of {0,1,0} and {1,0,0} (a vector going straigh up and straight 
//on the x axis) should be {1,1,0} because it is going in between the straight
//up and straight to the side vectors, resulting in a x=y vector.
Vectorobject Vectorobject::average(Vectorobject v){
    
    float x = (v.coordinates[0]+coordinates[0])/2;
    float y = (v.coordinates[1]+coordinates[1])/2;
    float z = (v.coordinates[2]+coordinates[2])/2;
    
    return {x,y,z};
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

float* Vectorobject::getCoordinates(){
    return coordinates;
}

void Vectorobject::setCoordinates(float* c){
    coordinates=c;
}