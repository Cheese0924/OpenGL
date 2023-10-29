#include <iostream>
#include <GL/freeglut.h>
using namespace std;
void keyboardDown(unsigned char key, int x, int y) {
	printf("Key %c pressed at (%d, %d)\n", key, x, y);
	if (key == 27 || key == 'q')
		exit(0);
}
void keyboardUp(unsigned char key, int x, int y) {
	printf("Key %c released at (%d, %d)\n", key, x, y);
}
void specialKeyDown(int key, int x, int y) {
	printf("Key %c pressed at (%d, %d)\n", key, x, y);
	switch (key) {
	case GLUT_KEY_F1:
		cout << "!!!!!!!!!!" << endl;
		break;
	case GLUT_KEY_UP:
		cout << "@@@@@@@@@@" << endl;
		break;
	case GLUT_KEY_HOME:
		cout << "##########" << endl;
		break;
	}
}
void specialKeyUp(int key, int x, int y) {
	printf("Key %c released at (%d, %d)\n", key, x, y);
}

void mouse(int button, int state, int x, int y) {
	printf("(%d, %d, %d, %d)\n", button, state, x, y);
	if (button == GLUT_LEFT_BUTTON)
		cout << "%%%%%%%%%%" << endl;
	if (state == GLUT_UP)
		cout << "^^^^^^^^^^" << endl;
}
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	// glFinish();
}
void main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Hello OpenGL!");
	// register callbacks
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyUp);
	glutMouseFunc(mouse);
	// enter GLUT event processing cycle
	glutMainLoop();
}