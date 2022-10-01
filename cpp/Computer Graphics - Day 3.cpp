#include<stdlib.h>     
#include<glut.h>   
float x_pos = 0.0f;  float y_pos = 0.0f; float z_pos = -10.0f; float rot = 0.0f;
void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)width / (float)height, 1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void putaran(int id)
{
	rot += 10;
	glutPostRedisplay();
	glutTimerFunc(100, putaran, 0);
}

void myKeyboard(unsigned char key, int x, int y)
{
	if ((key == '<') || (key == ',')) z_pos -= 0.1f;
	if ((key == '>') || (key == '.')) z_pos += 0.1f;
	if ((key == 's') || (key == 'S')) y_pos -= 0.1f;
	if ((key == 'w') || (key == 'W')) y_pos += 0.1f;
	if ((key == 'a') || (key == 'A')) x_pos -= 0.1f;
	if ((key == 'd') || (key == 'D')) x_pos += 0.1f;
}
// Menggerakan obj

void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(x_pos, y_pos, z_pos);
	glRotatef(rot, 0, 1, 0);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);   
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLoadIdentity();
	gluPerspective(45, (GLdouble)500.0 / (GLdouble)500.0, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	return;
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Galang Aprilian Anarki");
	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(100, putaran, 0);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}
