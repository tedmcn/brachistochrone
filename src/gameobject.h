#include "vectorobject.h"
#include "physics.h"

#ifndef gameobject_h
#define gameobject_h

class Gameobject{

//Everything in here is public
public:

	//Constructor
	Gameobject();

	//Deconstructor
	~Gameobject();

	void draw();
	void apply(Physics p);
	bool intersect();	
	Gameobject below();

	//Position represented with a array of floats
	void setP(float* positon);
	void setP(float x, float y, float z);
	float* getP();

	//Acceleration represented with a vector
	void setV(float* velocity);
	Vectorobject getV();

	//Acceleration represented with a vector
	void setA(float* accelation);
	Vectorobject getA();

//Everything here can only be used within the class
protected:

	float p[3];	//Position represented with 3 coordinates

	Vectorobject v;	//Velocity
			
	Vectorobject a; //Acceleration of the ball
	

};
#endif