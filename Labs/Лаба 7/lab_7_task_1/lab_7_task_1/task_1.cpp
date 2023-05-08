#include <gl/glut.h>
#include <cmath>
#include <math.h>
void init();
void draw();
int count = 0;
float* X;
float* Y;
//Главная функция
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Лаба 7");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}
//Функция инициализации
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
//Функция рисования
void draw()
{
	GLfloat A = 100, B = 50, X = 0, Y = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(10, 10, 600, 400);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-100.0, 0.0); glVertex2f(100.0, 0.0);
	glVertex2f(0.0, 100.0); glVertex2f(0.0, -100.0);
	glEnd();
	GLfloat a = 100, X11 = -100, X22 = 100, Y11 = 0, Y22 = 0;
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(X11, Y11);
	while (X11 < X22) {
		X11 = X11 + 1;
		Y11 = a / (2 * X11);
		glVertex2f(X11, Y11);
	}
	glEnd();
	glFlush();
}