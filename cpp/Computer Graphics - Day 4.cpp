#include<stdlib.h>
#include<glut.h>
float n = 0.0f;
float kondisi = 0.0f;
float rot = 0.0f;
char key;
void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)width / (float)height, 1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
}
void putaran(int id)
{
	rot += n;
	glutPostRedisplay(); // request redisplay
	glutTimerFunc(100, putaran, 0); // request next timer event
}
void myKeyboard(unsigned char key, int x, int y)
{
	if (((key == 'x') || (key == 'X')) && (kondisi == 0.0f))
	{
		kondisi = 1.0f;
		n += 10.0f;
	}
	else if (((key == 'x') || (key == 'X')) && (kondisi == 1.0f))
	{
		kondisi = 0.0f;
		n = 0.0f;
	}
}
void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(rot, 0, 1, 0);
	glBegin(GL_QUADS);
	// kotak di bawah warna kuning
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	// segitiga di depan warna merah    
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	// segitiga di kanan warna cyan
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	// segitiga di belakang warna hijau
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	// segitiga di kiri warna magenta
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
	glClearColor(0.0, 0.0, 0.0, 1.0); // A Background Clear Color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLdouble)500.0 / (GLdouble)500.0, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	return;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode( GLUT_DOUBLE /*|GLUT_DEPTH* / );
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("1718125");
	// callbacks
	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(100, putaran, 0);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}
