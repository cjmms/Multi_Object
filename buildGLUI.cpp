// --------------------------------
//
//  GLUI sample, Fall 2019
//  by C. M. Hoffmann

#include "stdafx.h"
//
// items for the buildGLUI.h file
//
GLUI *glui;
GLUI *glui_right;
GLUI *glui_bottom;
GLUI_Checkbox *checkbox;
GLUI_Spinner *spinner;
GLUI_RadioGroup *radio;
GLUI_Panel *panel;
GLUI_EditText *edittext;
//
// callback for the radio group
// variable systemState tells which button is on
//
void setSystemState(int r) {   // radio group call back
  printf("radio group system state %d\n   ", systemState);
  setState(systemState);
  switch (systemState) {
  case 0: 
    printf("0 moves");
    break;
	case 1:
		printf("1 moves");
		break;
	case 2:
		printf("2 moves");
		break;
	case 3:
		printf("3 moves");
		break;
	case 4:
		printf("4 moves");
		break;
	case 5:
		printf("5 moves");
		break;
	case 6:
		printf("6 moves");
		break;
  case 7:
    printf("7 moves");
    break;
  case 8:
    printf("GLOBAL MOVE");
    break;
  }

  printf("\n");
}
//
// call back for the panel of check boxes
// could be omitted when querying each associated variable
//
void lightSwitch(int r) {
  printf("checkbox lights panel %d\n", r);
  printf("   light switch 0 = %d\n", light0);
  printf("   light switch 1 = %d\n", light1);
  printf("   light switch 2 = %d\n", light2);
  printf("   light switch 3 = %d\n", light3);
}
//
// an action button.  Having a reset to the initial
// configuration comes in handy now and then
//
void resetAll(int) {
  // here you re-initialize your system as if it started anew
  GLUI_Master.sync_live_all();
  redrawAll();
}
//
void gotoExit(int) { exit(0);}
//
// You use spinners to set variable values.  The side controls
// are too fast, however; I have no use for it.  For A3 having
// a direct x,y,z input might not be terribly useful.
//
void objectPos(int select) {      // curve argument t
  printf("Object position, select = %d \n", select);
  printf("   Spinner value is %f in x \n", xCoord);
  printf("   Spinner value is %f in y \n", yCoord);
  printf("   Spinner value is %f in z \n", zCoord);
}
//
// this is the place where the UI is laid out and the respective
// semantic is created by the call-back routines
//
void buildGLUI(int displayWin) {
  GLUI_Master.set_glutReshapeFunc(reshapeDisplay);
  GLUI_Master.set_glutMouseFunc(mouseClickLeft);
  GLUI_Master.set_glutIdleFunc(idle);
  glui = GLUI_Master.create_glui_subwindow(displayWindow, GLUI_SUBWINDOW_RIGHT);

  // Program Name at top, no function
  glui->add_separator();
  glui->add_statictext("   Multiple Objects");
  glui->add_separator();
  
  // Radio group, exactly one button is active at any one time 
  GLUI_Panel *panelR1 = new GLUI_Panel(glui, "System State", GLUI_PANEL_EMBOSSED);
  GLUI_RadioGroup *actionGroup = new GLUI_RadioGroup(panelR1, &systemState, -1, setSystemState);
  new GLUI_RadioButton(actionGroup, "Move Object 0");
  new GLUI_RadioButton(actionGroup, "Move Object 1");
	new GLUI_RadioButton(actionGroup, "Move Object 2");
	new GLUI_RadioButton(actionGroup, "Move Object 3");
	new GLUI_RadioButton(actionGroup, "Move Object 4");
	new GLUI_RadioButton(actionGroup, "Move Object 5");
	new GLUI_RadioButton(actionGroup, "Move Object 6");
	new GLUI_RadioButton(actionGroup, "Move Object 7");
	new GLUI_RadioButton(actionGroup, "All  Together");
	// check box: each may be checked or unchecked
  GLUI_Panel *panelC1 = new GLUI_Panel(glui, "Lights", GLUI_PANEL_EMBOSSED);
  new GLUI_Checkbox(panelC1, "Light 0", &light0, 12, lightSwitch);
  new GLUI_Checkbox(panelC1, "Light 1", &light1, 12, lightSwitch);
  new GLUI_Checkbox(panelC1, "Light 2", &light2, 12, lightSwitch);
  new GLUI_Checkbox(panelC1, "Light 3", &light3, 12, lightSwitch);

  // parameter panel; input int or float; input of double not working
  GLUI_Panel *panelCoords = new GLUI_Panel(glui, "Object coordinates", GLUI_PANEL_EMBOSSED);
  GLUI_Spinner *objX = new GLUI_Spinner(panelCoords, "x  ", &xCoord, 1000, objectPos);
  objX->set_float_limits(-1.0, 1.0, GLUI_LIMIT_CLAMP);
  GLUI_Spinner *objY = new GLUI_Spinner(panelCoords, "y  ", &yCoord, 1001, objectPos);
  objY->set_float_limits(-1, 1, GLUI_LIMIT_CLAMP);
  GLUI_Spinner *objZ = new GLUI_Spinner(panelCoords, "z  ", &zCoord, 1002, objectPos);
  objZ->set_float_limits(-1, 1, GLUI_LIMIT_CLAMP);
	// two action button
  GLUI_Panel *panel4 = new GLUI_Panel(glui, "  ", GLUI_PANEL_NONE);
  new GLUI_Button(panel4, "Clear & Reset", 60, resetAll);
  new GLUI_Button(panel4, "EXIT", 70, gotoExit);
}