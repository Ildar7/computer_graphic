#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
GLfloat R = 640.0 / 480; //Форматное соотношение
GLfloat w = 40;  //Ширина мирового окна
GLfloat h; //Высота мирового окна
GLfloat l, r, b, t; //Параметры мирового окна
GLfloat f = 0;

void init(void)
{
	h = w / R; l = -w / 2; r = w / 2; b = -h / 2; t = h / 2; //Расчет параметров миро-вого окна
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

void fig0(void)
{
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-3.0, -3.0);
	glVertex2f(-3.0, 3.0);
	glVertex2f(5.0, 3.0);
	glVertex2f(5.0, -3.0);
	glEnd();
}

void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glScalef(f, -f, f);
	fig0();
	glPopMatrix( );
	glFlush();
	glutSwapBuffers();
	f+=0.5; if(f==2.0) f=0;
	Sleep(50);
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Myprog");
	glutReshapeFunc(reshape);
	glutDisplayFunc(scene);
	glutIdleFunc(scene);
	init();
	glutMainLoop();
}
