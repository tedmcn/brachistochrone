#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
 
float ang,x,y;
float ty=-.8,sx=.1,sy=.1;
int flag=0,cnt=0;
 
 
 void display()  
{
      int i;
 glClear(GL_COLOR_BUFFER_BIT);
    
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glTranslatef(0,ty,0);
 glScalef(sx,sy,0);
          for(i=0;i<=360;i++)
        {
            glBegin(GL_POINTS);
            ang=i*((6.28)/360);
            x=.1 * cos(ang);
            y=.1 * sin(ang);
            glVertex2f(x,y);
            glEnd();
         }
         if(cnt==50){flag=1;}
 if(cnt==0){flag=0;
 glLoadIdentity();
 glColor3f(1,.4,0); 
 glBegin(GL_QUADS);
 glVertex2f(-.4,-1);
 glVertex2f(-.3,-.7);
 glVertex2f(.3,-.7);
 glVertex2f(.4,-1);
 glEnd();
 }
 glColor3f(0,1,1);
 if(flag==0)
 {
  ty=ty+.03;
  sx=sx+.03;
  sy=sy+.03;
  cnt++;
 }
 else
 {
  ty=ty-.03;
  sx=sx-.03;
  sy=sy-.03;
  cnt--;
 }
 //slep();
 glLoadIdentity();
 glBegin(GL_LINE_LOOP);
 glVertex2f(-.4,-1);
 glVertex2f(-.3,-.7);
 glVertex2f(.3,-.7);
 glVertex2f(.4,-1);
 glEnd();
 glutPostRedisplay();
    glFlush();
       
}
 
int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize(700,700);
  glutInitWindowPosition(10,10);
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
  glutCreateWindow("Bouncing BAll ");
 
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}