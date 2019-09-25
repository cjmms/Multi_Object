#pragma once

extern int displayWindow;


void setState(int input_state);
int  mkDisplayWindow(int w, int h);
void clearGraphics(void);
void redrawAll(void);
void reshapeDisplay(int, int);
void mouseClickLeft(int, int, int, int);
void idle(void);