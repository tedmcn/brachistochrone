//A vector is a one directional line with finite length
//we are using it to represent the direction of a given object in 3D space
//
//The direction is derived by caluclating the angel from the origin
//to the float[] of coordinates...
//
//IE A vector of values {0,1,0} is representing straight up because
//From the origin {0,0,0} to {0,1,0} is a move of 1 up in the y direction.
//
//More complex vectors can 


class Vectorobject {

public:
	
	Vectorobject average(Vectorobject v);

protected:
    
    float coordinates[3];
    
}

//Averages two different vectors
Vectorobject Vectorobject::average(Vectorobject v){
    
}