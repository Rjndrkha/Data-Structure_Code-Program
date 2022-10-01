//#include "Header.h" //fix
#include <stdio.h>
#include <glut.h> //fix
void gas()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0, 180);
	glVertex2d(-150, 130);
	glVertex2d(-190, 0);
	glVertex2d(-150, -140);
	glVertex2d(0, -180);
	glVertex2d(150, -130);
	glVertex2d(190, 0);
	glVertex2d(150, 140);
	glVertex2d(0, 180);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(-600, 0);
	glVertex2i(600, 0);
	glBegin(GL_LINES);
	glVertex2i(0, -600);
	glVertex2i(0, 600);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(0, 70);
	glVertex2d(-70, -70);
	glVertex2d(70, -70);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(-70, -60);
	glVertex2d(-90, -80);
	glVertex2d(-60, -80);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(70, -60);
	glVertex2d(90, -80);
	glVertex2d(60, -80);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(0, 80);
	glVertex2d(-40, 40);
	glVertex2d(40, 40);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(480, -480);
	glVertex2d(470, -460);
	glVertex2d(460, -470);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(-480, -480);
	glVertex2d(-470, -460);
	glVertex2d(-460, -470);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(480, 480);
	glVertex2d(470, 460);
	glVertex2d(460, 470);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(-480, 480);
	glVertex2d(-470, 460);
	glVertex2d(-460, 470);
	glEnd();
	glFlush();
}
void main()
{
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Galang Aprilian");
	gluOrtho2D(-600, 600, -600, 600);
	glutDisplayFunc(gas);
	glutMainLoop();
}