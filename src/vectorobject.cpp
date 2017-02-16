//A vector is a one directional line with finite length
//we are using it to represent the direction of a given object in 3D space
//
//The direction is derived by caluclating the angel from the origin
//to the float[] of coordinates...
//
//IE A vector of values {0,1,0} is representing straight up because
//From the origin {0,0,0} to {0,1,0} is a move of 1 up in the y direction.
//
//More complex vectors can be represented with coordinates further from the origin
//such as {1,2,0} (x=2y graph) which is different from {1,1,0} (which is x=y graph)


class Vectorobject {

public:
	
	Vectorobject average(Vectorobject v);
    float* toDegree();

protected:
    
    float coordinates[3];
    
private:
    
}

//Averages two different vectors
//
//The average of {0,1,0} and {1,0,0} (a vector going straigh up and straight 
//on the x axis) should be {1,1,0} because it is going in between the straight
//up and straight to the side vectors, resulting in a x=y vector.
Vectorobject Vectorobject::average(Vectorobject v){
    
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