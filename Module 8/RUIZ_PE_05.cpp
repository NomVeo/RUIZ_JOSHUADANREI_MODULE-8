
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
    gluLookAt(0, 2.5, 7, 0, 0, 0, 0, 1, 0);

    GLfloat dullSpecular[] = {1, 1, 1, 1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, dullSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, 8);

    glPushMatrix();
    glTranslatef(-1.5f, 0, 0);
    glutSolidSphere(1, 40, 30);
    glPopMatrix();

    GLfloat shinySpecular[] = {1, 1, 1, 1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, shinySpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, 96);

    glPushMatrix();
    glTranslatef(1.5f, 0, 0);
    glutSolidSphere(1, 40, 30);
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightPos[] = {2, 3, 4, 1};
    GLfloat lightSpecular[] = {1, 1, 1, 1};

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q05");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
