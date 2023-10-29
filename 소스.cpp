#include <iostream>	
#include <GL/freeglut.h>
#include <vector>
#include <random>
using namespace std;

random_device rd;

#define WIDTH 640
#define HEIGHT 640
#define SPACEBAR 32

class MovingPoint {
public:
	float color[3];
	float position[2];
	float velocity[2];
	float size;
};
MovingPoint MP;
vector<vector<float>> vtx;
vector<vector<float>> block[16 * 4];
bool pause;
bool blockSwitch[16 * 4];
int life;
int blockLeft;
vector<float> blockColor[16 * 4];
bool buttonSplit;

bool topCheckerPoly(vector<vector<float>> vtx) {
	if (buttonSplit) {
		if (((-1.0f <= MP.position[0] && MP.position[0] <= vtx[1][0]) || (vtx[0][0] <= MP.position[0] && MP.position[0] <= 1.0f)) && // scope from left to right
			vtx[0][1] - abs(MP.velocity[1]) <= MP.position[1] && MP.position[1] <= vtx[0][1]) // check whether the MP pointer contacts to the top side
			return true;
	}
	else if (vtx[0][0] <= MP.position[0] && MP.position[0] <= vtx[1][0] && // scope from left to right
		vtx[0][1] - abs(MP.velocity[1]) <= MP.position[1] && MP.position[1] <= vtx[0][1]) // check whether the MP pointer contacts to the top side
		return true;
	return false;
}
bool topChecker(vector<vector<float>> vtx) {
	if (vtx[0][0] <= MP.position[0] && MP.position[0] <= vtx[1][0] && // scope from left to right
		vtx[0][1] - abs(MP.velocity[1]) <= MP.position[1] && MP.position[1] <= vtx[0][1]) // check whether the MP pointer contacts to the top side
		return true;
	return false;
}
bool bottomChecker(vector<vector<float>> vtx) {
	if (vtx[3][0] <= MP.position[0] && MP.position[0] <= vtx[2][0] &&
		vtx[3][1] <= MP.position[1] && MP.position[1] <= vtx[3][1] + abs(MP.velocity[1])) // check whether the MP pointer contacts to the bottom side
		return true;
	return false;
}
bool leftChecker(vector<vector<float>> vtx) {
	if (vtx[3][1] <= MP.position[1] && MP.position[1] <= vtx[0][1] && // scope from bottom to top
		vtx[0][0] <= MP.position[0] && MP.position[0] <= vtx[0][0] + abs(MP.velocity[0])) // check whether the MP pointer contacts to the left side
		return true;
	return false;
}
bool rightChecker(vector<vector<float>> vtx) {
	if (vtx[2][1] <= MP.position[1] && MP.position[1] <= vtx[1][1] &&
		vtx[1][0] - abs(MP.velocity[1]) <= MP.position[0] && MP.position[0] <= vtx[1][0]) // check whether the MP pointer contacts to the right side
		return true;
	return false;
}

void initialize() {
	MP.color[0] = MP.color[1] = MP.color[2] = 1.0f;
	MP.position[0] = 0.0f; MP.position[1] = 0.0f;
	MP.velocity[0] = 0.003f; MP.velocity[1] = -0.003f;
	MP.size = 10.0f;

	vtx = { {-0.25f, -0.9f}, {0.25f, -0.9f}, {0.25f, -1.0f}, {-0.25f, -1.0f} };

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 16; i++) {
			block[i + 16 * j] = { {-0.8f + i * 0.1f, 0.6f + j * 0.05f},
								  {-0.7f + i * 0.1f, 0.6f + j * 0.05f},
								  {-0.7f + i * 0.1f, 0.55f + j * 0.05f},
								  {-0.8f + i * 0.1f, 0.55f + j * 0.05f} };
		}
	}	
	pause = true;
	for (int i = 0; i < 16 * 4; i++) {
		blockSwitch[i] = true;
	}
	life = 5;

	mt19937_64 mt(rd());
	uniform_int_distribution<int> range(0, 1000);
	for (int i = 0; i < 64; i++) {
		float r = float(range(mt)) / 1000;
		float g = float(range(mt)) / 1000;
		float b = float(range(mt)) / 1000;
		blockColor[i] = { r, g, b };
	}
	
	blockLeft = 64;
	buttonSplit = false;
}
void idle() {
	
	if (pause) return;
	else {
		if (MP.position[0] < -1.0f || MP.position[0] > 1.0f)
			MP.velocity[0] = -MP.velocity[0];
		if (MP.position[1] > 1.0f)
			MP.velocity[1] = -MP.velocity[1];
		if (MP.position[1] < -1.0f) {
			MP.position[1] = 0.9f;
			life--;
			//if (life == 0) exit(0);
		}

		if (topCheckerPoly(vtx))
			MP.velocity[1] = -MP.velocity[1];
		if (leftChecker(vtx) || rightChecker(vtx))
			MP.velocity[0] = -MP.velocity[0];
		
		for (int i = 0; i < 16 * 4; i++) {
			if (blockSwitch[i] == true) {
				if (bottomChecker(block[i]) || topChecker(block[i])) {
					MP.velocity[1] = -MP.velocity[1];
					blockSwitch[i] = false;
					blockLeft--;
					if (blockLeft == 50 || blockLeft == 30 || blockLeft == 20 || blockLeft == 10 || blockLeft == 5) {
						MP.velocity[0] *= 0.8f;
						MP.velocity[1] *= 0.8f;
					}
				}
				if (leftChecker(block[i]) || rightChecker(block[i])) {
					MP.velocity[0] = -MP.velocity[0];
					blockSwitch[i] = false;
					blockLeft--;
					if (blockLeft == 50 || blockLeft == 30 || blockLeft == 20 || blockLeft == 10 || blockLeft == 5) {
						MP.velocity[0] *= 0.8f;
						MP.velocity[1] *= 0.8f;
					}
				}
			}
		}


		MP.position[0] += MP.velocity[0];
		MP.position[1] += MP.velocity[1];
		glutPostRedisplay();
	}
}
void drawPoint() {
	glPointSize(MP.size);
	glColor3f(MP.color[0], MP.color[1], MP.color[2]);
	glBegin(GL_POINTS);
	glVertex2f(MP.position[0], MP.position[1]);
	glEnd();
}
void drawPolygon() {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	if (buttonSplit) {
		glVertex2f(-1.0f, -0.9f);
		glVertex2f(vtx[1][0], vtx[1][1]);
		glVertex2f(vtx[2][0], vtx[2][1]);
		glVertex2f(-1.0f, -1.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(vtx[0][0], vtx[0][1]);
		glVertex2f(1.0f, -0.9f);
		glVertex2f(1.0f, -1.0f);
		glVertex2f(vtx[3][0], vtx[3][1]);
	}
	else {
		glVertex2f(vtx[0][0], vtx[0][1]);
		glVertex2f(vtx[1][0], vtx[1][1]);
		glVertex2f(vtx[2][0], vtx[2][1]);
		glVertex2f(vtx[3][0], vtx[3][1]);
	}
	glEnd();
}
void drawBlock() {
	for (int i = 0; i < 16 * 4; i++) {
		if (blockSwitch[i]) {
			glColor3f(blockColor[i][0], blockColor[i][1], blockColor[i][2]);
			glShadeModel(GL_SMOOTH);
			glBegin(GL_POLYGON);
			glVertex2f(block[i][0][0], block[i][0][1]);
			glVertex2f(block[i][1][0], block[i][1][1]);
			glVertex2f(block[i][2][0], block[i][2][1]);
			glVertex2f(block[i][3][0], block[i][3][1]);
			glColor3f(0.0f, 0.0f, 0.0f);
			glEdgeFlag(GL_TRUE);
			glEnd();
		}
	}
}
void drawLife() {
	for (int i = 0; i < life; i++) {
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex2f(-0.97f + i * 0.05f, 0.97f);
		glVertex2f(-0.94f + i * 0.05f, 0.97f);
		glVertex2f(-0.94f + i * 0.05f, 0.94f);
		glVertex2f(-0.97f + i * 0.05f, 0.94f);
		glEnd();
	}
}
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	drawPoint();
	drawPolygon();
	drawBlock();
	drawLife();

	glutSwapBuffers();
}

void keyDown(unsigned char key, int x, int y) {
	switch (key) {
	case SPACEBAR:
		pause = !pause;
	}
}
void specialKeyDown(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:	
		for (int i = 0; i < 4; i++) vtx[i][0] -= 0.05f;
		if (vtx[0][0] <= -1.0f) {
			vtx[0][0] += 2.0f;
			vtx[3][0] += 2.0f;
			buttonSplit = !buttonSplit;
		}
		if (vtx[1][0] <= -1.0f) {
			vtx[1][0] += 2.0f;
			vtx[2][0] += 2.0f;
			buttonSplit = !buttonSplit;
		}
		break;
	case GLUT_KEY_RIGHT:
		for (int i = 0; i < 4; i++) vtx[i][0] += 0.05f;
		if (vtx[1][0] >= 1.0f) {
			vtx[1][0] -= 2.0f;
			vtx[2][0] -= 2.0f;
			buttonSplit = !buttonSplit;
		}
		if (vtx[0][0] >= 1.0f) {
			vtx[0][0] -= 2.0f;
			vtx[3][0] -= 2.0f;
			buttonSplit = !buttonSplit;
		}
		break;
	}
	glutPostRedisplay();
}

void main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Draw a moving point");

	initialize();
	// register callbacks
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeyDown);
	glutKeyboardFunc(keyDown);
	glutIdleFunc(idle);

	glutMainLoop();
}