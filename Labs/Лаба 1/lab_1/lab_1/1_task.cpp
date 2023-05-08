#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
void init();
void draw();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Лаба 1, Задание 1, Вариант 2");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}

void init()
{
    glClearColor(0.9, 0.9, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-8.0, 8.0, -2.0, 2.0);
}

void draw()
{
    GLfloat x, y, a = 1, b = 2;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glViewport(0, 0, 640, 480);

    glBegin(GL_LINES);
    glVertex2f(-8.0, 0.0); glVertex2f(8.0, 0.0);
    glVertex2f(0.0, 1.5); glVertex2f(0.0, -1.5);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (x = -2 * M_PI - 2; x <= 2 * M_PI + 2; x += M_PI / 45)
    {
        y = sin(a * x) * cos(b * x);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}