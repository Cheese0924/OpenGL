#include "BubbleBobble.h"

void specialKeyDown(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		keystates[LEFT] = 1;
		break;
	case GLUT_KEY_RIGHT:
		keystates[RIGHT] = 1;
		break;
	case GLUT_KEY_UP:
		keystates[UP] = 1;
		if (player.state == STAY) {
			player.state = JUMP;
			player.velocity = 0.08f;
		}
		break;
	case GLUT_KEY_DOWN:
		keystates[DOWN] = 1;
		break;
	}
	glutPostRedisplay();
}
void specialKeyUp(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		keystates[LEFT] = 0;
		break;
	case GLUT_KEY_RIGHT:
		keystates[RIGHT] = 0;
		break;
	case GLUT_KEY_UP:
		keystates[UP] = 0;
		break;
	case GLUT_KEY_DOWN:
		keystates[DOWN] = 0;
		break;
	}
	glutPostRedisplay();
}
void keyDown(unsigned char key, int x, int y) {
	switch (key) {
	case SPACEBAR:
		break;
	}
}