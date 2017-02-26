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

void Sphereobject::apply(Physics p, Planeobject plane){


	//Print things for testing
	float* saved_position = getP();
	float* saved_velocity = getV().get();
	float* saved_acceleration = getA().get();

	float* temp_position= getP();
	float* temp_velocity = getV().get();
	float* temp_acceleration = getA().get();


	int i;
	float temp_values1[3]={0,0,0};
	float temp_values2[3]={0,0,0};
	float temp_values3[3]={0,0,0};
	long double diff = p.getDiff();
	previous_diff=diff;

	//
	//POSITION
	//

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
	




	//
	//VELOCITY
	//


	//Next calculate velocity
	for(i=0;i<3;i++){
		if(intersects==0){
				//Velocity equals acceleration times the difference in time
				temp_values2[i]=diff*temp_acceleration[i] + temp_velocity[i];
		}else{
			temp_values2[1]=-1*(temp_velocity[1])/3;
		}
	}
	//Always account for gravity
	temp_values2[1]=diff*gravity + temp_values2[1];

	//Set the new Velocity
	setV(temp_values2);


	//
	//ACCELERATION
	//

	//Reduce acceleration a bit to simulate drag
	for(i=0;i<3;i++){
		temp_values3[i]=(saved_acceleration[i]*.9)+temp_values3[i];
	}

	//Set the new Acceleration
	setA(temp_values3);



}