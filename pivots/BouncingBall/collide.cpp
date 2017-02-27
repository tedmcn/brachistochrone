
#ifdef __APPLE__
#include<GLUT/glut.h>
#include<openGL/openGL.h>

#else
#include<GL/glut.h>
#endif

float x1=-2.0,x2 =2.0, x3= 4.0, x4 = 4.0;
static int flag=1;

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(45,w/h,1,200);

}

void keyPressed(int key,int x,int y)
{
    if(key==GLUT_KEY_LEFT)
    {}
}

void drawBall1()
{
    glColor3f(1.0,0.0,0.0);

    glPushMatrix();

    glTranslatef(x1,0.0,-5.0);

    glutSolidSphere(0.4,20,20);

    glPopMatrix();
}

void drawBall2()
{
    glColor3f(0.0,0.0,1.0);

    glPushMatrix();

    glTranslatef(x2,0.0,-5.0);

    glutSolidSphere(0.4,20,20);

    glPopMatrix();



}

//added balls
void drawBall3()
{
    glColor3f(0.0,1.0,0.0);

    glPushMatrix();

    glTranslatef(x3,0.0, -5.0);

    glutSolidSphere(0.4,10,20);

    glPopMatrix();
}

void drawBall4() {
    glColor3f(1.0,0.0,1.0);

    glPushMatrix();

    glTranslatef(x4,0.0,5.0);

    glutSolidSphere(0.4,10,10);

    glPopMatrix();



}

void update()
{
    if(flag)
        {
            x1+=0.04;
            x2-=0.04;
            //x3+=0.002;
           // x4-=0.01;
            if(x1>-0.35)
                flag=0;
        }
    if(!flag)
    {
        x1-=0.04;
        x2+=0.04;
       // x3+=0.002;
        //x4-=0.01;
        if(x1<-2.0)
            flag=1;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //glShadeModel(GL_SMOOTH);
    drawBall1();

    drawBall2();

    drawBall3();

    drawBall4();

    update();

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(400,400);

    glutCreateWindow("Collision Window");

    initRendering();

    glutDisplayFunc(display);

    glutIdleFunc(display);

    glutReshapeFunc(reshape);

    glutSpecialFunc(keyPressed);

    glutMainLoop();

    return(0);
}

