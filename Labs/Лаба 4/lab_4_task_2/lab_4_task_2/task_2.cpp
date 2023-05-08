#include <gl/glut.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>

GLfloat angle = 0, plusangle = 0;
GLfloat angle2 = 0, plusangle2 = 0;
int ch1 = 0, ch2 = 0;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay()
{
	glPushMatrix(); //Сохраняем VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //вместе с очисткой буфера предусмотреть очистку буфера глубины
	glEnable(GL_DEPTH_TEST); //включение режима удаления невидимых (проверка глубины)
	gluLookAt(3, 3, 7, 0, 0, 0, 0, 1, 0); // VM=Fwe // позиция наблюдателя

	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 }; // Источник света в CKw

	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция ис-точника света будет преобразована в CKe*/
	glEnable(GL_LIGHTING); // Включение расчета освещенности
	glEnable(GL_LIGHT0); // включаем этот конкретный источник
	GLfloat myDiffuse[] = { 0.50754, 0.50754, 0.50754, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse); // Источник света в CKw
	GLfloat myShininess[] = { 51.2 };
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
	GLfloat myAmbient[] = { 0.19225, 0.19225, 0.19225, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient);
	GLfloat mySpecular[] = { 0.508273, 0.508273, 0.508273, 1 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mySpecular);

	glPushMatrix(); //Сохраняем VM=Fwe
	glRotatef(angle2, 0, 1, 0); // вращаем источник света
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glPopMatrix(); // Восстанавливаем VM=Fwe

	glPushMatrix(); //Сохраняем VM=Fwe
	glRotatef(angle, 0, 1, 0); // VM=Fwe*R

	// грань f0 (основание)
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);
	glVertex3f(1, 0, 1); glVertex3f(0, 0, 1);
	glEnd();

	// грань f1 (задняя стенка)
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0, 0, 0); glVertex3f(0.5, 1, 0);
	glVertex3f(1, 1, 0); glVertex3f(1, 0, 0);
	glEnd();

	// грань f2 (передняя стенка)
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0, 0, 1); glVertex3f(0.5, 1, 1);
	glVertex3f(1, 1, 1); glVertex3f(1, 0, 1);
	glEnd();

	// грань f3 (верхушка)
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.5, 1, 0); glVertex3f(1, 1, 0);
	glVertex3f(1, 1, 1); glVertex3f(0.5, 1, 1);
	glEnd();

	// грань f4 (левая стенка)
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(0, 0, 0); glVertex3f(0.5, 1, 0);
	glVertex3f(0.5, 1, 1); glVertex3f(0, 0, 1);
	glEnd();

	// грань f1 (правая стенка)
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(1, 0, 0); glVertex3f(1, 1, 0);
	glVertex3f(1, 1, 1); glVertex3f(1, 0, 1);
	glEnd();

	glPopMatrix(); // Восстанавливаем VM=Fwe

	glDisable(GL_LIGHTING); //Выключаем освещение

	glBegin(GL_LINES); //Рисуем координатные оси разного цвета в CKe
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(3, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 3, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 3);
	glEnd();

	//Рисуем направление к источнику света в CKe
	//glBegin(GL_LINES); glColor3f(0,0,0); glVertex3f(1, 2, 2); glVertex3f(0.0, 0.0, 0.0); glEnd();

	glPopMatrix();
	glutSwapBuffers();
	// usleep(50000);
}

void myReshape(int width, int height)
{
	if (width / height < 1) glViewport(0, 0, width, width);
	else glViewport(0, 0, height, height);
}

void myIdle()
{
	angle += plusangle; if (angle > 360.0) angle = 0;
	angle2 += plusangle2; if (angle2 > 360.0) angle2 = 0;
	glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
	if (key == '0') {

		if (ch1 % 2 == 0) plusangle = 0.1;
		else plusangle = 0;
		ch1++;
	}
	else if (key == 'l') {
		if (ch2 % 2 == 0) plusangle2 = 0.1;
		else plusangle2 = 0;
		ch2++;
	}

	if (key == 'f') {
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}
	else if (key == 'b') {
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //устанавливая режим дисплея в функции main(), предусмотрено использование буфера глубины
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Лаба 4, Задание 2");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keys);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);

	init();
	glutMainLoop();
}