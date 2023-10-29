#include "BubbleBobble.h"
#include <ctime>

#define WINDOW_X 400
#define WINDOW_Y 100

#define WINDOW_WIDTH 640		// window's width
#define WINDOW_HEIGHT 640		// window's height

clock_t startTime = clock();
clock_t endTime;

Player player;
Map stage1(1);
bool keystates[5];

void initialize() {
}

void idle() {
	endTime = clock();
	if (endTime - startTime > 1000 / 30) {
		if (keystates[LEFT]) {
			if (player.direction == RIGHT) player.direction = LEFT; //  the player's direction change
			else {
				player.direction = LEFT;
				if (player.state == FALL) player.setPosition(-0.015f, 0.0f);
				else player.setPosition(-0.025f, 0.0f);
				stage1.checkLEFT();
			}
		}
		if (keystates[RIGHT]) {
			if (player.direction == LEFT) player.direction = RIGHT; //  the player's direction change
			else {
				player.direction = RIGHT;
				if (player.state == FALL) player.setPosition(0.015f, 0.0f);
				else player.setPosition(0.025f, 0.0f);
				stage1.checkRIGHT();
			}
		}
		if (keystates[DOWN]) {
			if (player.state != STAY) { //  if the player's state is JUMP or FALL
				player.state = FALL;
				player.setPosition(0.0f, -0.01f);
			}
		}
		
		if (player.state == STAY) {
			if (stage1.checkFALL()) {
				player.state = FALL;
			}
		}
		else if (player.state == JUMP) {
			if (player.velocity > 0) {
				player.setPosition(0.0f, player.velocity);
				stage1.checkJUMP();
				player.velocity -= 0.008f;
			}
			else {			
				player.position[1] -= 0.01f;
				player.state = FALL;
			}
		}
		else if (player.state == FALL) {
			if (stage1.checkFALL()) {
				player.setPosition(0.0f, -0.01f);
			}
		}
		startTime = endTime;
		glutPostRedisplay();
	}
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	stage1.drawMap();
	player.drawPlayer();

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Bubble Bobble");

	initialize();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyDown);
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyUp);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}