/*
Writtern by CS Goh
23 Feb 2017
Imports file into opengl
*/
#include <iostream>
#include <cstring>
#include <stdlib.h> 
#include <GL/glut.h>
#include "objloader.h"
#include <cstdio>
using namespace std;

objloader::objloader(char *fname, float _position[3])
{ 
int i=0;
    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;
    newobj=glGenLists(1);
    fp=fopen(fname,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(newobj, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
		//printf("ch - %c \n",ch);
		//printf("read - %d\n", read);
		//if (read == 1 ) printf (" READ 1   %c",ch);
            if(read==4&&ch=='v')
            {
                glVertex3f(x,y,z);
            i++;}
	  
        }
cout <<"COUNT!!!!!!!!"<<i<<endl;
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
	memcpy(position, _position, sizeof(position)); // not used yet 
}

// not loading any accleration information in yet. 
void objloader::draw(){   
//cout<<"drawing b"<<endl;
	 // pushing and poping allows u to determine transformation to be done to the matrix. 
   glPushMatrix();
    //glTranslatef(0,0,0);
    //glColor3f(1.0,0,0);
   // glScalef(1,1,1);
   // glRotatef(newobj,0,1,0);
     glCallList(newobj);
    glPopMatrix();
}



