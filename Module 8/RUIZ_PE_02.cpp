#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

float ambientValue = 0.1f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2.5, 5, 0, 0, 0, 0, 1, 0);

    glutSolidSphere(1, 40, 30);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '1')
        ambientValue = 0.1f;
    else if (key == '4')
        ambientValue = 0.4f;
    else if (key == '8')
        ambientValue = 0.8f;

    GLfloat ambient[] = {
        ambientValue, ambientValue, ambientValue, 1
    };

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
    glutPostRedisplay();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat ambient[] = {0.1f, 0.1f, 0.1f, 1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    GLfloat diffuse[] = {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q02");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
