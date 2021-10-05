#include"Header.h"

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("1718125 - Galang Aprilian");
	gluOrtho2D(-80, 80, -80, 80);
	glutDisplayFunc(transformasi);
	bangun1();
	bangun2();
	bangun3();
	bangun4();
	glutMainLoop();
}
