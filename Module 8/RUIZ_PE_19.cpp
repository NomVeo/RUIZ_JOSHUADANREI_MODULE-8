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

    GLfloat light0[] = {-3, 3, 3, 1};
    GLfloat light1[] = {3, 3, 3, 1};

    glLightfv(GL_LIGHT0, GL_POSITION, light0);
    glLightfv(GL_LIGHT1, GL_POSITION, light1);

    // Dull sphere
    GLfloat dullDiffuse[] = {0.7f, 0.7f, 0.7f, 1};
    GLfloat dullSpecular[] = {0.2f, 0.2f, 0.2f, 1};

    glMaterialfv(GL_FRONT, GL_DIFFUSE, dullDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, dullSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, 8);

    glPushMatrix();
    glTranslatef(-1.5f, 0, 0);
    glutSolidSphere(1, 40, 30);
    glPopMatrix();

    // Shiny sphere
    GLfloat shinyDiffuse[] = {0.7f, 0.7f, 0.7f, 1};
    GLfloat shinySpecular[] = {1, 1, 1, 1};

    glMaterialfv(GL_FRONT, GL_DIFFUSE, shinyDiffuse);
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
    glEnable(GL_LIGHT1);

    GLfloat whiteLight[] = {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, whiteLight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q19");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
