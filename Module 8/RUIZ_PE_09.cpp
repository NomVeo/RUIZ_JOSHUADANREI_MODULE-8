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
    gluLookAt(0, 2.5, 6, 0, 0, 0, 0, 1, 0);

    GLfloat pos0[] = {-2, 3, 3, 1};
    GLfloat pos1[] = {2, 3, 3, 1};

    glLightfv(GL_LIGHT0, GL_POSITION, pos0);
    glLightfv(GL_LIGHT1, GL_POSITION, pos1);

    glutSolidSphere(1, 40, 30);

    glutSwapBuffers();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    GLfloat redLight[] = {1, 0.2f, 0.2f, 1};
    GLfloat blueLight[] = {0.2f, 0.2f, 1, 1};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, redLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, blueLight);

    GLfloat material[] = {1, 1, 1, 1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q09");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
