#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

float lightX = 2.0f;
float lightY = 3.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2.5, 7, 0, 0, 0, 0, 1, 0);

    GLfloat pos[] = {lightX, lightY, 3, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

    glPushMatrix();
    glTranslatef(-1.5f, 0, 0);
    glutSolidSphere(0.8, 40, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, 0, 0);
    glutSolidSphere(0.8, 40, 30);
    glPopMatrix();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT)
        lightX -= 0.3f;
    else if (key == GLUT_KEY_RIGHT)
        lightX += 0.3f;
    else if (key == GLUT_KEY_UP)
        lightY += 0.3f;
    else if (key == GLUT_KEY_DOWN)
        lightY -= 0.3f;

    glutPostRedisplay();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

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
    glutCreateWindow("Ruiz_Q08");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
