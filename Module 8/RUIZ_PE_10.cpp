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
    gluLookAt(0, 2.5, 9, 0, 0, 0, 0, 1, 0);

    GLfloat lightPos[] = {0, 3, 2, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glPushMatrix();
    glTranslatef(-3, 0, 0);
    glutSolidSphere(0.8, 40, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glutSolidSphere(0.8, 40, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 0, 0);
    glutSolidSphere(0.8, 40, 30);
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

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.15f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.05f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q10");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
