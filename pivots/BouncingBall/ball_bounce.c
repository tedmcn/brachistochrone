/*
    bouncing balls animation using OpenGL and Glut
 */
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//#include <stream.h>
#include <strings.h>
//#include <GLUT/glut.h>
#include <GL/glut.h>


//using namespace std;

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif


double pi = 4 * atan(1.0);
const double g = 9.8;
const double L = 10.0;     // physical region: -L < x < L and 0 < y < L

struct BouncingBall {
     double x, vx, y, vy;

     void step(double dt) 
        x += vx * dt;
        y += vy * dt;
        vx = vx;
        vy -= g * dt;

        if (x >  L) vx = - abs(vx);      // bounce off right wall
        if (x < -L) vx = abs(vx);        // bounce off left wall
        if (y <  0) vy = abs(vy);        // bounce off floor
        if (y >  10) vy = -abs(vy);        // bounce off top wall
    

};

struct  BouncingBall(double x, double vx, double y, double vy) {
            this.x = x;
            this.vx = vx;
            this.y = y;
            this.vy = vy;
}



int N ;            // number of balls
float v_max;     // maximum initial speed
float dt ;     // time step for Euler method
float t;             // simulation time
int step_number;      // time step number

void get_input() {

    printf("Bouncing balls simulation\n");
    printf("=========================\n");
    printf("Enter the number of balls: \n");

    scanf("%i", &N);
    if (N < 1) 
        N = 2;
    printf("Enter maximum speed: \n");

    scanf("%f", &v_max);
    printf("Enter time step dt:\n");
    scanf("%f", &t);
    t = 0;
    step_number = 0;


    /**
    cout << "Bouncing balls simulation" << endl;
    cout << "-------------------------" << endl;
    cout << "Enter number of balls: " << flush;
    cin >> N;
    if (N < 1) N = 2;
    cout << "Enter maximum speed: " << flush;
    cin >> v_max;
    if (v_max < 0) v_max = - v_max;
    cout << "Enter time step dt: " << flush;
    cin >> dt;
    t = 0;
    step_number = 0;

    **/
}

BouncingBall *balls;    // pointer to and array of ball pointers

void create_balls() {
    int i;

    balls = new BouncingBall [N];

    for (i = 0; i < N; i++) {
        double theta = pi * rand() / double(RAND_MAX);
        balls[i] = new BouncingBall(0, v_max * cos(theta),
                                    0, v_max * sin(theta));
    }
}

// move each ball by one time step dt
void step() {

    int i;
    for (i = 0; i < N; i++)
        balls[i].step(dt);
    t += dt;
    ++step_number;
}

double frames_per_second = 30;   // for animation in real time

void animation_step() {
    double start = t;
    clock_t start_time = clock();
    step();
    double tau = 1.0 / frames_per_second;
    
    while (t - start < tau)
        step();
    while ((double(clock()) - start_time)/CLOCKS_PER_SEC < tau)
        ;
    glutPostRedisplay();
}

/**
void drawText(const string str, double x, double y) {
    
    int i;
    glRasterPos2d(x, y);
    int len = str.find('\0');
    for (i = 0; i < len; i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
}
**/
// Glut callback function to update the display
void display() {
    
    BouncingBall *balls; 

    glClear(GL_COLOR_BUFFER_BIT);

    static GLubyte color_table[6][3] =
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255},
         {0, 255, 255}, {255, 0, 255}, {255, 255, 0}};

    int i, j;

    for (i = 0; i < N; i++) {
        glColor3ubv(color_table[i%6]);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2d(balls[i].x, balls[i].y);
            double phi = 2 * pi / 24;

            for (j = 0; j < 25; j++) {
                glVertex2d(balls[i].x + 0.5 * cos(phi*j),
                           balls[i].y + 0.5 * sin(phi*j));
            }
        glEnd();
    }
    glColor3ub(0, 0, 0);
    //ostringstream os;
   // os + "Step No: " + step_number + "   Time t = " + t + ends;
    //drawText(os.str(), -L + L/50, L/20);
    //os.seekp(0);

     glutSwapBuffers();
}

// Glut callback function to reset the viewing transformation
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-L, L, 0, L/w*(2.0*h));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int running = 0;   // is the animation running

// Glut mouse callback function
void mouse(int button, int state, int x, int y) {
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) {
            if (running) {
                glutIdleFunc(NULL);
                running = 0;
            } else {
                glutIdleFunc(animation_step);
                running = 1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    get_input();
    create_balls();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bouncing Balls Animation");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
}