#include <iostream>
#include <vector>
#include <GL/freeglut.h>

using namespace std;

enum SELECT_VERTEX { VTX1 = 0, VTX2, VTX3, VTX4, POINT_SIZE };

SELECT_VERTEX selVtx(VTX1);	// selected vertex
vector<vector<float>> quadVtx;	// 4 vertices of quadrangle -> ((x1, y1), (x2, y2), (x3, y3), (x4, y4))
vector<vector<float>> colors;	// colors of 4 vertices

void createVertices() {
	/* Implement: add 4 vertex positions and colors */
	quadVtx = { {-0.25, 0.1}, {0.25, 0.1}, {0.25, -0.1}, {-0.25, -0.1} };
}

void drawQuadrangle() {
	/* Implement: draw a quadrangle and selected vertex */
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

	drawQuadrangle();

	//glFlush();
	glFinish();
}

void keyboardDown(unsigned char key, int x, int y) {
	/* Implement: select a vertex (1~4) */
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
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Select and move a vertex of quadrangle.");

	createVertices();

	// register callbacks
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardDown);
	glutSpecialFunc(specialKeyDown);

	// enter GLUT event processing cycle
	glutMainLoop();
}
