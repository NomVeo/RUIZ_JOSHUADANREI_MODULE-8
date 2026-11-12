#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif

#include <iostream>
using namespace std;

GLuint textureID = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0.2f, 0.8f, 0.4f);

    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(.08f, .09f, .12f, 1);

    glGenTextures(1, &textureID);

    cout << "Generated Texture ID: " << textureID << endl;

    glBindTexture(GL_TEXTURE_2D, textureID);

    cout << "Texture successfully bound." << endl;

    glDeleteTextures(1, &textureID);

    cout << "Texture deleted." << endl;

    textureID = 0;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ruiz_Q07");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
