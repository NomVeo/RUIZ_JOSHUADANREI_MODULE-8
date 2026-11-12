#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

GLuint textureID;

void drawCube() {
    glBegin(GL_QUADS);

    // Front
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1, 0); glVertex3f( 1, -1, 1);
    glTexCoord2f(1, 1); glVertex3f( 1,  1, 1);
    glTexCoord2f(0, 1); glVertex3f(-1,  1, 1);

    // Back
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0); glVertex3f( 1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f(-1,  1, -1);
    glTexCoord2f(0, 1); glVertex3f( 1,  1, -1);

    // Left
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f(-1, -1,  1);
    glTexCoord2f(1, 1); glVertex3f(-1,  1,  1);
    glTexCoord2f(0, 1); glVertex3f(-1,  1, -1);

    // Right
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(1, -1,  1);
    glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f(1,  1, -1);
    glTexCoord2f(0, 1); glVertex3f(1,  1,  1);

    // Top
    glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-1, 1,  1);
    glTexCoord2f(1, 0); glVertex3f( 1, 1,  1);
    glTexCoord2f(1, 1); glVertex3f( 1, 1, -1);
    glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);

    // Bottom
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f( 1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f( 1, -1,  1);
    glTexCoord2f(0, 1); glVertex3f(-1, -1,  1);

    glEnd();
}

void drawFloor() {
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);

        glTexCoord2f(0, 0);
        glVertex3f(-6, -1.2f, -6);

        glTexCoord2f(4, 0);
        glVertex3f(6, -1.2f, -6);

        glTexCoord2f(4, 4);
        glVertex3f(6, -1.2f, 6);

        glTexCoord2f(0, 4);
        glVertex3f(-6, -1.2f, 6);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 4, 8, 0, 0, 0, 0, 1, 0);

    // Point light
    GLfloat pointPos[] = {2, 4, 3, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, pointPos);

    // Directional light
    GLfloat directionalPos[] = {-1, 1, 1, 0};
    glLightfv(GL_LIGHT1, GL_POSITION, directionalPos);

    glBindTexture(GL_TEXTURE_2D, textureID);

    // Floor
    drawFloor();

    // First textured cube
    glPushMatrix();
    glTranslatef(-2, 0, 0);
    drawCube();
    glPopMatrix();

    // Second textured cube
    glPushMatrix();
    glTranslatef(2, 0, 0);
    glScalef(0.7f, 0.7f, 0.7f);
    drawCube();
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_TEXTURE_2D);

    GLfloat pointDiffuse[] = {1, 1, 1, 1};
    GLfloat directionalDiffuse[] = {0.5f, 0.5f, 0.7f, 1};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, pointDiffuse);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, directionalDiffuse);

    GLfloat material[] = {1, 1, 1, 1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char pixels[] = {
        255, 255, 255,   0, 0, 0,
        0, 0, 0,         255, 255, 255
    };

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGB,
        2, 2, 0, GL_RGB,
        GL_UNSIGNED_BYTE, pixels
    );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q20");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
