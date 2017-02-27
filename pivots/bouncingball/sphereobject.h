/*
editted by CS Goh
23 Feb 2017
*/
#ifndef sphereobject_h
#define sphereobject_h

#include <iostream>

class sphereobject{
public:
	

sphereobject(float _radius, float *_position, float *_color);

/*
Prints positional, velocity, and accleration information.
*/
void print_info();

/*Draws the sphere
	Updates its velocity and position automatically before drawing. 
**Update accleration / velocity changes only after drawing as the positional change is based on its old velocity */
void draw();

/* Updates the velocity of sphere. 
 doesn't really matter if void or bool for now. */
bool update_velocity(double _velocity[3]);

/*Updates the accleration of sphere. 
 doesn't really matter if void or bool for now. */
bool update_accleration(double _accleration[3]);

bool intersect();

	float position[3];
	float color[3]; 
	float radius;
	float velocity[3];
	float accleration[3];
	int last_updated_time; // last updated time in milliseconds 
/*
	updates velocity and position of sphere based on the time now vs last updated time. 
*/
void update(float time_now);

};

#endif


