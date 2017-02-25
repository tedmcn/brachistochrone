#include <sys/time.h>
#include <time.h>
#include <stdio.h>

#include "physics.h"

//Constructor
Physics::Physics(){

	gettimeofday(&now, NULL);
	t=now.tv_usec;
	diff=0;
}

//Deconstructor
Physics::~Physics(){
	
}

void Physics::apply(Gameobject obj){

}

//This function updates the current time in microseconds
// 1million microseconds to a second
//
void Physics::update(){

	//Save current time
	gettimeofday(&now, NULL);
	long int temp_time = now.tv_usec;

	//If somehow the new time is smaller than the old timer
	if(t>temp_time){
		//Add 1 million to the temp time
		temp_time=temp_time+1000000;
		//Calculate the difference between the previous and current time
		diff= temp_time - t;
		//Reset the temp time
		temp_time=temp_time-1000000;
	}
	//Otherwise simply calculate the difference
	else{
		diff=temp_time-t;
	}

	//Save the new time
	t=temp_time;

	//Print the time and difference for testing
	//printf("%ld - %ld \n", t, diff);

}