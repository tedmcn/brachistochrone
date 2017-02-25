#ifndef physics_h
#define physics_h

#include "gameobject.h"


class Physics{

public:

	Physics();
	~Physics();

	void apply(Gameobject obj);
	void update();

protected:

	long int t;
	long int diff;
	struct timeval now;

private:

};

#endif