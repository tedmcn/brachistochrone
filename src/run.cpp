#include <GL/glut.h>
#include <stdlib.h> 
#include <stdio.h>

#include "gameobject.h"
#include "vectorobject.h"
#include "physics.h"
#include "sphereobject.h"
#include "planeobject.h"
//#include "curveobject.h"


Sphereobject s= Sphereobject(1);
Planeobject plane;
Physics p;


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
 

//This function is used on every frame, it is used to draw the 3d environment onto the screen
static void display(void)
{ 
    s.print();


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the previous image

    //Reset the viewport to the standard camera angel
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(15.0,15.0,15.0,0.0,0.0,0.0,0.0,1.0,0.0);


    glColor3d(1,0,0); 	//Draw in red


    //Draw the sphere
    s.draw();

    glColor3d(0,0,0);   //Draw black plane

    //Draw the plane
    plane.draw();

    //Test the sphere's coordinates
    // printf("%f - %f - %f\n",s.getP()[0],s.getP()[1], s.getP()[2] );
 
    //Apply the time update
    p.update();
    //Update the sphere object
    s.apply(p);

    glutSwapBuffers(); //Send the new image to the buffer
} 


 
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
   
    //Start opengl, Create the window
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
 
    
    GLfloat sphere_coordinates[] = {0,10,0};
    GLfloat plane_coordinates[] = {0,0,0};

    p = Physics();
    plane = Planeobject();

    s.setP(sphere_coordinates);
    plane.setP(plane_coordinates);

    glutCreateWindow("B-Curve"); 
 
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

    glutMainLoop(); 
 
    return EXIT_SUCCESS;
}