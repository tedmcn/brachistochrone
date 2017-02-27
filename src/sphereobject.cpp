#include "planeobject.h"
#include "sphereobject.h"
#include <math.h>

//Constructor
Sphereobject::Sphereobject(float r){
	radius=r;
}

//Deconstructor
Sphereobject::~Sphereobject(){

}


void Sphereobject::draw(){
	//Add a sphere 
    glPushMatrix();
        glTranslatef(p[0],p[1],p[2]);
        glutSolidSphere(radius,50,50);
    glPopMatrix(); 
}


bool Sphereobject::intersect(Planeobject plane){
	float distance;
	int i;
	float* temp_position= getP();
	float* normal = plane.getN().get();
	for(i=0;i<3;i++){
		distance = distance +(temp_position[i]*normal[i]);
	}

	//	printf("%i\n",fabs(distance)<1);

	return fabs(distance)<1;
}


//Moves a sphere with collision detection for a plane
//
//p - physics object
//plane - plane to detect collision with
void Sphereobject::apply(Physics p, Planeobject plane){

	//Save values in case of detection and need rollback
	float* saved_position = getP();
	float* saved_velocity = getV().get();
	float* saved_acceleration = getA().get();

	//Create temp values we will overwrite/modify
	float* temp_position= getP();
	float* temp_velocity = getV().get();
	float* temp_acceleration = getA().get();

	//Used for loops
	int i;

	//Create empty arrays we can write into 
	float temp_values1[3]={0,0,0};
	float temp_values2[3]={0,0,0};
	float temp_values3[3]={0,0,0};

	//Calculate how long it has been since the last frame was drawn and save it
	long double diff = p.getDiff();

	//***********************************************************************//
	//POSITION
	//***********************************************************************//

	//First calculate displacment
	for(i=0;i<3;i++){
		//Distance equals velocity times the difference in time
		temp_values1[i]=diff*temp_velocity[i];
	}


	//Next change the position based on the displacment
	for(i=0;i<3;i++){
		temp_values1[i]= temp_position[i]+ temp_values1[i];
	}


	bool intersects= intersect(plane);

	//If it doesn't intersect , Finally save the new position
	if(intersects==0){
		setP(temp_values1);
	}
	//Otherwise
	else{
		//Move the sphere so it doesn't intersect
		for(i=0;i<3;i++){
			temp_values1[i]= previous_diff*temp_velocity[i];
			temp_values1[i]= temp_position[i]-temp_values1[i];

		}
		setP(temp_values1);
	}
		

	//***********************************************************************//
	//VELOCITY
	//***********************************************************************//


	//Next calculate velocity
	for(i=0;i<3;i++){
		//If no intersection nothing is special
		if(intersects==0){
				//Velocity equals acceleration times the difference in time
				temp_values2[i]=diff*temp_acceleration[i] + temp_velocity[i];
		}
		//If there was intersection
		else{
			temp_values2[1]=-2*(temp_velocity[1])/5;
			
			//

		}
	}
	//Always account for gravity
	temp_values2[1]=diff*gravity + temp_values2[1];

	//Set the new Velocity
	setV(temp_values2);


	//***********************************************************************//
	//ACCELERATION
	//***********************************************************************//

	//Reduce acceleration a bit to simulate drag
	for(i=0;i<3;i++){
		temp_values3[i]=(saved_acceleration[i]*.9)+temp_values3[i];
	}

	//Set the new Acceleration
	setA(temp_values3);


	previous_diff=diff;

}