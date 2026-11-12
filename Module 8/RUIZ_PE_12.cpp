#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

float angle = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 6, 0, 0, 0, 0, 1, 0);

    glRotatef(angle, 0, 1, 0);

    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(-1.5f, -1.5f, 0);
        glVertex3f( 1.5f, -1.5f, 0);
        glVertex3f( 1.5f,  1.5f, 0);
        glVertex3f(-1.5f,  1.5f, 0);
    glEnd();

    glutSwapBuffers();
}

void timer(int value) {
    angle += 1.0f;

    if (angle >= 360)
        angle = 0;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    GLfloat lightPos[] = {2, 3, 4, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    GLfloat frontColor[] = {1, 0, 0, 1};
    GLfloat backColor[] = {0, 0, 1, 1};

    glMaterialfv(GL_FRONT, GL_DIFFUSE, frontColor);
    glMaterialfv(GL_BACK, GL_DIFFUSE, backColor);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q12");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
