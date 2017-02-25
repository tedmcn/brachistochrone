/*
edited by CS Goh
23 Feb 2017
*/
#include <GL/glut.h>
#include <stdlib.h> 
#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdio>
#include "sphereobject.h"
#include "objloader.h"
#include "cubeobject.h"

using namespace std;
GLuint elephant;
//float elephantrot;
//char ch='1';

sphereobject ball(0.5,(float [3]){0,0,0},(float [3]){1,1,0});
//sphereobject ball1(3,(float [3]){0,0,0},(float [3]){1,1,0});
cubeobject cube1(3, (float [3]){0,0,0}, (float [3]){1,2,0});
//objloader b("bcurve.obj", (float [3]){0,0,0});

void loadObj(char *fname)
{
int i=0;
    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;
    elephant=glGenLists(1);
    fp=fopen(fname,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(elephant, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            if(read==4&&ch=='v')
            {
//cout<<"noerr";
                glVertex3f(x,y,z);i++;
            }
	    else; //cout <<"error";
        }
cout <<"COUNT!!"<<i<<endl;
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}
//wavefront .obj loader code ends here

void drawElephant()
{
   glPushMatrix();
    glTranslatef(0,0,0);
    glColor3f(1.0,0,0.27);
   // glScalef(0.1,0.1,0.1);
    //glRotatef(elephantrot,0,1,0);
    glCallList(elephant);
    glPopMatrix();
return;
/*
    elephantrot=elephantrot+0.6;
    if(elephantrot>360)elephantrot=elephantrot-360;
*/
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height; 
 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0); 
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
} 


static void display(void);

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 
 
/* Program entry point */
 
int main(int argc, char *argv[])
{
	
    glutInit(&argc, argv);
    glutInitWindowSize(1200,768);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
 
    glutCreateWindow("Programming Techniques - 3D Spheres"); 
 
    glutReshapeFunc(resize);
    glutDisplayFunc(display); 
 
    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); 
 
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 
 
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 

    glutIdleFunc(display);

   // loadObj("bcurve.obj"); //replace elepham.obj withp orsche.obj or radar.obj or any other .obj to display it
    glutMainLoop(); 
 
    return EXIT_SUCCESS;
}

bool checkcollide(cubeobject cube,sphereobject sphere){

	for(int i=0;i<5;i++){
		if (sphere.position[i] + sphere.radius >= cube.position[i] + cube.size/2.0){
			//cout<<"coll"<<endl;
			ball.position[i] = cube.position[i] + cube.size/2.0 -ball.radius;
ball.velocity[i] *= -1;
			//ball.velocity[0] *= 0;			ball.velocity[1] *= 0;			ball.velocity[2] *= 0;
			return 1;	
		}

		if (sphere.position[i] - sphere.radius <= cube.position[i] - cube.size/2.0){	
			ball.position[i] = cube.position[i] - cube.size/2.0 + ball.radius;
			//cout<<"coll"<<endl;
			//ball.velocity[0] *= 0;			ball.velocity[1] *= 0;			ball.velocity[2] *= 0;
			ball.velocity[i] *= 1;
			return 1;	
		}
	}
	return 0;

}

//This function is used on every frame, it is used to draw the 3d environment onto the screen
static void display(void)
{ 
    glClearColor (0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the previous image
   

    //Reset the viewport to the standard camera angel
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	gluLookAt(	7, 7 , -7,
			0, 0,  0,
			0.0f, 1.0f,  0.0f);
    glColor3d(1,0,0); 	//Draw in red

    // drawElephant();

   //b.draw();
    ball.draw();
	//ball.draw();
	cube1.draw();
	
	checkcollide(cube1,ball);
	//ball.velocity[0] *= -1;
	//ball.velocity[1] *= -1;
	//ball.velocity[2] *= -1;
	
    glutSwapBuffers(); //Send the new image to the buffer
} 
