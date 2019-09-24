#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>


GLfloat** material;

void init() {
    glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
    // glEnable(GL_BLEND);
	// glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    // glEnable(GL_COLOR_MATERIAL);

	GLfloat white[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_pos[] = { 5, 5, 5, 1 };

	//glLightfv(GL_LIGHT0, GL_POSITION, light_pos);  // define the position of the light
	//glLightfv(GL_LIGHT0, GL_AMBIENT, white);  // specify the ambient RGBA intensity of the light
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, white);  // specify the ambient RGBA intensity of the light
	//glEnable(GL_LIGHT0);

    glShadeModel(GL_SMOOTH);

    glViewport(0, 0, 480, 480);  // define a viewport and display in this viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1, 1.0, 20.0);  // specify a viewing frustum
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // define a viewing matrix
}

// x axis is red, y axis is green, z axis is blue
void drawThreeAxises () {
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

void drawTeapot(double x, double y, double z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    //glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.85, 0.48, 0.47);
    glutSolidTeapot(.08);  // draw the teapot
    drawThreeAxises();
    glPopMatrix();
}

void draw_eight_objs() {
    drawTeapot(-0.3f, 0.3f, -0.3f);
    drawTeapot(0.3f, 0.3f, -0.3f);
    drawTeapot(-0.3f, -0.3f, -0.3f);
    drawTeapot(0.3f, -0.3f, -0.3f);
    drawTeapot(-0.3f, 0.3f, 0.3f);
    drawTeapot(0.3f, 0.3f, 0.3f);
    drawTeapot(-0.3f, -0.3f, 0.3f);
    drawTeapot(0.3f, -0.3f, 0.3f);
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gluSphere(gluNewQuadric(), 0.07f, 32, 32);

    draw_eight_objs();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);  // initialize the library
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(480, 480);  // define size of the window
	glutInitWindowPosition(0, 0);  // define position of the window
	glutCreateWindow("Multi_Object");

    init();

	glutDisplayFunc(draw);  // display callback
	glutMainLoop();  // enter event processing loop

	return 0;
}
