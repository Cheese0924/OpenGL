#include <iostream>
#include <GL/freeglut.h>
#include <vector>
using namespace std;
#define WIDTH 640
#define HEIGHT 640

class MovingPoint {
public:
	float color[3];
	float position[2];
	float velocity[2];
	float size;
};
MovingPoint MP;
vector<vector<float>> quadVtx;

void initialize() {
	MP.color[0] = MP.color[1] = MP.color[2] = 1.0f;
	MP.position[0] = -0.8f;
	MP.position[1] = 0.5f;
	MP.velocity[0] = 0.0001f;
	MP.velocity[1] = -0.0001f;
	MP.size = 10.0f;
	
	quadVtx = { {-0.25, 0.1}, {0.25, 0.1}, {0.25, -0.1}, {-0.25, -0.1} };
}
void idle() {
	if (MP.position[0] < -1.0f || MP.position[0] > 1.0f)
		MP.velocity[0] = -MP.velocity[0];
	if (MP.position[1] < -1.0f || MP.position[1] > 1.0f)
		MP.velocity[1] = -MP.velocity[1];
	
	if (quadVtx[0][0] <= MP.position[0] <= quadVtx[1][0] && quadVtx[3][1] <= MP.position[1] <= quadVtx[0][1])
		MP.velocity[1] = -MP.velocity[1];
		MP.velocity[0] = -MP.velocity[0];

	MP.position[0] += MP.velocity[0];
	MP.position[1] += MP.velocity[1];
	glutPostRedisplay();
}
void drawPoint() {
	glPointSize(MP.size);
	glColor3f(MP.color[0], MP.color[1], MP.color[2]);
	glBegin(GL_POINTS);
	glVertex2f(MP.position[0], MP.position[1]);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(quadVtx[0][0], quadVtx[0][1]);
	glVertex2f(quadVtx[1][0], quadVtx[1][1]);
	glVertex2f(quadVtx[2][0], quadVtx[2][1]);
	glVertex2f(quadVtx[3][0], quadVtx[3][1]);
	glEnd();
}
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	drawPoint();
	glutSwapBuffers();
}
void specialKeyDown(int key, int x, int y) {
	/* Implement: move the selected vertex with arrow keys */
	switch (key) {
	case GLUT_KEY_UP:
		for (int i = 0; i < 4; i++) {
			quadVtx[i][1] += 0.03f;
		}
		break;
	case GLUT_KEY_DOWN:
		for (int i = 0; i < 4; i++) {
			quadVtx[i][1] -= 0.03f;
		}
		break;
	case GLUT_KEY_LEFT:
		for (int i = 0; i < 4; i++) {
			quadVtx[i][0] -= 0.03f;
		}
		break;
	case GLUT_KEY_RIGHT:
		for (int i = 0; i < 4; i++) {
			quadVtx[i][0] += 0.03f;
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
	glutIdleFunc(idle);
	// enter GLUT event processing cycle
	glutMainLoop();
}
