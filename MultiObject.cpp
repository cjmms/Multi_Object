// MultiObject.cpp : Defines the entry point for the console application.
//
// as globals, this might be a suitable place to define these variables
// or you could distribute them to where their primary use is
//
#include "stdafx.h"

// extern declared in file buildGLUI.h
int systemState = 8;   // all objects move in unison
int displayWindow = -1;// glut id
// more globals
int light0 = 1;
int light1 = 0;
int light2 = 0;
int light3 = 0;
float xCoord = 0;
float yCoord = 0;
float zCoord = 0;

int main(int argc, char **argv) {
	glutInit(&argc, argv);       // start with call to glutInit() or else...
															 //testSteps();                 // splice in the various tests
	// set up your objects here
	mkDisplayWindow(800, 600);
	buildGLUI(displayWindow);
	glutMainLoop();
	return 0;
}

