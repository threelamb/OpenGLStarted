// OpenGLStarted.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <GL111\glut.h>
#include "Matrix.h"
#pragma comment(lib,"glew.lib")
using namespace std;
Matrix* matrix;

void disponse();
void Display();

void disponse()
{
	delete matrix;
	matrix = NULL;
}

void Display()
{
	matrix->draw();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);//初始化GLUT库
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);
	glutCreateWindow(argv[0]);
	if(false)
	{
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		//exit(EXIT_FAILURE);
	}
	matrix = new Matrix();
	glutDisplayFunc(Display);

	atexit(disponse);
	glutMainLoop();
	return 0;
}

