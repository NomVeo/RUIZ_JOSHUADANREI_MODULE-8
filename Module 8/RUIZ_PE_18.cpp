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

void drawQuad(float x, GLint filter) {
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(x - 1.5f, -1.5f, 0);

        glTexCoord2f(1, 0);
        glVertex3f(x + 1.5f, -1.5f, 0);

        glTexCoord2f(1, 1);
        glVertex3f(x + 1.5f, 1.5f, 0);

        glTexCoord2f(0, 1);
        glVertex3f(x - 1.5f, 1.5f, 0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2.5, 7, 0, 0, 0, 0, 1, 0);

    glEnable(GL_TEXTURE_2D);

    // Left: GL_NEAREST
    drawQuad(-1.7f, GL_NEAREST);

    // Right: GL_LINEAR
    drawQuad(1.7f, GL_LINEAR);

    glutSwapBuffers();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

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

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, .1, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q18");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
