// --------------------------------
//
//  this stuff here is just meant to make the GLUI sample work
//  by C. M. Hoffmann, Fall 2019
//
#include "stdafx.h"
#include <vector>

using namespace std;


vector<bool> state(9, false);

// ----------------------------------------
// these functions have to be defined later
// ----------------------------------------

void reshapeDisplay(int w, int h) {}
void mouseClickLeft(int, int, int, int) {}
void mouseMoveLeft(int, int) {}
void goClear() {}

void idle(void)
{
	/* ... */
	if (glutGetWindow() != displayWindow)
		glutSetWindow(displayWindow);
	glutPostRedisplay();
}

void setState(int input_state) {
	if (input_state > 8 || input_state < 0)	return;		// check input
	fill(state.begin(), state.end(), false);	// reset state
	state[input_state] = true;
}


void init() {
	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, 480, 480);  // define a viewport and display in this viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1, 1.0, 20.0);  // specify a viewing frustum
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // define a viewing matrix
}

// x axis is red, y axis is green, z axis is blue
void drawThreeAxises() {
	double length = 0.15f;
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(length, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, length, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, length);
	glEnd();
}


void drawTeapot(double x, double y, double z, int num) {
	glPushMatrix();
	glTranslatef(x, y, z);
	if (state.at(num) || state.at(8))	// check state
		glColor3f(0.85, 0.48, 0.47);	// red 
	else
		glColor3f(1.00, 0.83, 0.27);	// gold
	glutSolidTeapot(.08);  // draw the teapot
	drawThreeAxises();
	glPopMatrix();
}


void draw_eight_objs() {
	drawTeapot(-0.3f, 0.3f, -0.3f, 0);		// left, top, back 
	drawTeapot(0.3f, 0.3f, -0.3f, 1);		// right, top, back
	drawTeapot(-0.3f, -0.3f, -0.3f, 2);		// left, bottom, back
	drawTeapot(0.3f, -0.3f, -0.3f, 3);		// right, bottom, back
	drawTeapot(-0.3f, 0.3f, 0.3f, 4);		// left, top, front 
	drawTeapot(0.3f, 0.3f, 0.3f, 5);		// right, top, front
	drawTeapot(-0.3f, -0.3f, 0.3f, 6);		// left, bottom, front
	drawTeapot(0.3f, -0.3f, 0.3f, 7);		// right, bottom, front
}


void draw_sphere() {
	glColor3f(1, 1, 1);
	gluSphere(gluNewQuadric(), 0.07f, 32, 32);
}


void redrawAll() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw_sphere();
	printf("draw\n");
	draw_eight_objs();
	glutSwapBuffers();
}


void clearGraphics() {}
// ---------------------------------------

  // set up the graphics window 
int mkDisplayWindow(int w, int h) {
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(w, h);
  glutInitWindowPosition(0, 0); 
  displayWindow = glutCreateWindow("Placeholder"); 

  init();

  clearGraphics();
  glutDisplayFunc(redrawAll);  
  //glutIdleFunc(redrawAll);
  glutReshapeFunc(reshapeDisplay);
  glutMouseFunc(mouseClickLeft);
  glutMotionFunc(mouseMoveLeft);
  return displayWindow;
}