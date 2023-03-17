#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

void init();
void draw();

//    Главная функция
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(240, 240);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Лаба 1, Задание 2, Вариант 2");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}

void init()
{
    glClearColor(1, 1, 1, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -5.0, 5.0);
}

void draw()
{
    GLint x = 0, y = 0, w = 60, h = 60;
    glClear(GL_COLOR_BUFFER_BIT);
    for (x = 0; x <= 180; x += w) {
        for (y = 0; y <= 180; y += h) {
            glViewport(x, y, w, h);
            glColor3f(1, 0.25, 0);
            glBegin(GL_POLYGON);
            glVertex2f(-1, 0);
            glVertex2f(3, -3);
            glVertex2f(1, 0);
            glVertex2f(3, 3);
            glEnd();
            glColor3f(0, 0, 0);
            glBegin(GL_LINE_STRIP);
            glVertex2f(-1, 0);
            glVertex2f(3, -3);
            glVertex2f(1, 0);
            glVertex2f(3, 3);
            glEnd();
        }
    }
    glFlush();
}