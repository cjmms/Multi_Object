#pragma once

extern GLUI *glui;
extern GLUI *glui_left;
extern GLUI *glui_bottom;
extern GLUI_Checkbox *checkbox;
extern GLUI_Spinner *spinner;
extern GLUI_RadioGroup *radio;
extern GLUI_Panel *panel;
extern GLUI_EditText *edittext;

void buildGLUI(int displayWin);

// -----------------------------------
// state variables and default values
// -----------------------------------
extern int systemState;   // all objects move in unison
extern int light0;        // on/off light 0
extern int light1;        // on/off light 1
extern int light2;        // on/off light 2
extern int light3;        // on/off light 3
extern float xCoord; 
extern float yCoord; 
extern float zCoord;