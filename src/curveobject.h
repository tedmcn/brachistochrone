#ifndef curveobject_h
#define curveobject_h

#include "gameobject.h"

class Curveobject: public Gameobject{

public:
	

	void draw();
	bool intersect();

protected:
	float *vertices;

};

#endif