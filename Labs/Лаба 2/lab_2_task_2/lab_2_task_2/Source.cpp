#include <GL/glut.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
GLfloat R = 640.0 / 480;
GLfloat w = 40, h; 
GLfloat l, r, b, t;
GLfloat f = 0.0;
GLfloat angle = 0;

void init(void) 
{
	h = w / R; l = -w / 2; r = w / 2; b = -h / 2; t = h / 2;
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(l, r, b, t);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void reshape(GLsizei W, GLsizei H)
{
	if (R > W / H) glViewport(0, 0, W, W / R);
	else glViewport(0, 0, H * R, H);
}
void showAxis(void)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, t);
	glVertex2f(0, 0);
	glVertex2f(r, 0);
	glEnd();
}
void fig0(float x, float y, float r, int amountSegments)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < amountSegments; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.0, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(2.5, -1.5);
	glVertex2f(2.5, 3.0);
	glEnd();
}
void drawCircle(float x, float y, float r, int amountSegments)
{

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < amountSegments; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
}
void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawCircle(0, 0, 5, 100);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0); 
	glRotatef(f, 0.0, 0.0, 1.0);
	glTranslatef(-10.0, 0.0, 0.0);
	glScalef(1.0, -1.0, 1.0);
	fig0(2.5, 0, 2.5, 200);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	Sleep(20);
}
void timer(int value)
{
	f += 90;
	if (f >= 360) { f = 0; }
	glutPostRedisplay();
	glutTimerFunc(500, timer, 0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Myprog");
	glutReshapeFunc(reshape);

	glutDisplayFunc(scene);
	glutTimerFunc(500, timer, 0);
	glutIdleFunc(scene);
	init();
	glutMainLoop();
	return 0;
}