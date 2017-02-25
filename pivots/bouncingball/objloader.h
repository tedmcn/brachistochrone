#ifndef objloader_h
#define objloader_h

#include <iostream>
#include <GL/glut.h>
class objloader{

public:
	// constructor, processes input file *fname 
	objloader(char *fname, float _position[3]);
	
	//traces the outline of the vertex given by the fiiles. 
	void draw();	
	GLuint newobj;
//private: 
	// saves the object. 

	float position[3];
};

#endif

