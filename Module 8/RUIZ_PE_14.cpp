#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/glext.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

GLuint textureID;

void drawQuad(float x, GLint wrapMode) {
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(x - 1.3f, -1.3f, 0);

        glTexCoord2f(3, 0);
        glVertex3f(x + 1.3f, -1.3f, 0);

        glTexCoord2f(3, 3);
        glVertex3f(x + 1.3f, 1.3f, 0);

        glTexCoord2f(0, 3);
        glVertex3f(x - 1.3f, 1.3f, 0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2.5, 7, 0, 0, 0, 0, 1, 0);

    glEnable(GL_TEXTURE_2D);

    // Left: GL_REPEAT
    drawQuad(-1.5f, GL_REPEAT);

    // Right: GL_CLAMP_TO_EDGE
    drawQuad(1.5f, GL_CLAMP_TO_EDGE);

    glutSwapBuffers();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);
    glEnable(GL_DEPTH_TEST);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

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
    glutCreateWindow("Ruiz_Q14");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
