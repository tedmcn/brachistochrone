/*
    bouncing balls animation using OpenGL and Glut
	g++ -o balls balls.cpp -lglut -lGLU -lGL -lm && ./balls
 */
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

class Ball
{
    public:
        double x;
        double y;
        double radius;
        double speedX;
        double speedY;
};


// std::vector<Ball> gAllBalls;  // a vector of balls with random positions and delta-values
double gGravity = 9.2;  // gravitational constant - I know it's 92 m/s^s, but I don't know how to apply that to deltaX and deltaY


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto &thisBall : gAllBalls)
    {
        // draw
        glColor3d(thisBall.red, thisBall.green, thisBall.blue);
        DrawCircle(thisBall.x, thisBall.y, thisBall.radius);

        // gravity 
        if (thisBall.y + thisBall.radius < gScreenHeight - gGravity)
        {
            thisBall.speedY -= gGravity;
        }

        // wall bouncing
        if (thisBall.y + thisBall.radius + thisBall.speedY >= gScreenHeight)  // up
        {
            thisBall.speedY = -thisBall.speedY;
        }

        if (thisBall.y + thisBall.speedY - thisBall.radius < 0)  // down
        {
            thisBall.speedY = -thisBall.speedY;
        }

        if (thisBall.x + thisBall.speedX - thisBall.radius < 0) // left
        {
            thisBall.speedX = -thisBall.speedX;
        }

        if (thisBall.x + thisBall.radius + thisBall.speedX >= gScreenWidth)  // right
        {
            thisBall.speedX = -thisBall.speedX;
        }

        // move
        thisBall.x += thisBall.speedX;
        thisBall.y += thisBall.speedY;
    }
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(800,400);
	glutCreateWindow("Bouncing Ball with Gravity");
	glutDisplayFunc(display);
	glutMainLoop();
}