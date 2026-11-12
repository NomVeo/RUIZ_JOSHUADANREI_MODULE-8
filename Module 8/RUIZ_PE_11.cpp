#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2.5, 8, 0, 0, 0, 0, 1, 0);

    GLfloat lightPos[] = {0, 4, 3, 1};
    GLfloat spotDir[] = {0, -1, -0.7f};

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);

    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 15);

    glPushMatrix();
    glTranslatef(-2.5f, 0, 0);
    glutSolidSphere(0.7, 40, 30);
    glPopMatrix();

    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30);

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glutSolidSphere(0.7, 40, 30);
    glPopMatrix();

    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60);

    glPushMatrix();
    glTranslatef(2.5f, 0, 0);
    glutSolidSphere(0.7, 40, 30);
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat diffuse[] = {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q11");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
