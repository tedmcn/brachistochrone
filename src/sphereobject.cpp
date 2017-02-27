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
	//Make sure distance starts at 0
	float distance=0;
	int i;
	float* temp_position= getP();
	float* normal = plane.getN().get();
	for(i=0;i<3;i++){
		distance = distance +(temp_position[i]*plane.getN().get()[i]);
		//	printf("%f\n",(distance));

	}

	return fabs(distance)<1.3;
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

	float normal_sum =0;
	float velocity_sum=0;

	//Next calculate velocity
	for(i=0;i<3;i++){

		
		

		//If no intersection nothing is special
		if(intersects==0){
				//Velocity equals acceleration times the difference in time
				temp_values2[i]=diff*temp_acceleration[i] + temp_velocity[i];
		}
		//If there was intersection
		else{
			//Return 2/5th of the energy in the postive y direction
			//since its a bouncy ball
			//temp_values2[1]=-2*(temp_velocity[1])/5;
			
			//Return the remaining 3/5th of energy in the x and z direction
			//relative to the normal

			//printf("NORMAL = %f | %f | %f\n",plane.getN().get()[0],plane.getN().get()[1],plane.getN().get()[2] );

			int j;
			
			normal_sum= plane.getN().get()[0] + plane.getN().get()[1]+ plane.getN().get()[2];
			velocity_sum= fabs(temp_velocity[0])+fabs(temp_velocity[1])+fabs(temp_velocity[2]);

			for(j=0;j<3;j++){
				float t = plane.getN().get()[i];
			}



			//Allocate for energy lost in collision
			velocity_sum= velocity_sum*0.6;

			//Divide the momentum by the normal vector sum
			velocity_sum= velocity_sum/normal_sum;

			for(j=0;j<3;j++){
				if(plane.getN().get()[i]!=0){
					temp_values2[i]=velocity_sum*plane.getN().get()[i];
				}
			}

		//	printf("%f | %f\n",normal_sum, velocity_sum );





		}
	}
	//Always account for gravity
	temp_values2[1]=diff*gravity + temp_values2[1];
	if(temp_values2[1]<-9.8){
		temp_values2[1]=-9.8;
	}

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