#ifndef physics_h
#define physics_h

#include <sys/time.h>
#include <time.h>
#include <stdio.h>

class Physics{

public:

	Physics();
	~Physics();

	void update();
	long double getDiff();

protected:

	long double t;
	long double diff;
	struct timeval now;

private:

};

#endif