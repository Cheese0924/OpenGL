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
	quadVtx = { {-0.5, 0.5}, { 0.5, 0.5 }, { 0.5, -0.5 }, { -0.5, -0.5 } };
	colors = { {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f} };
}

void drawQuadrangle() {
	/* Implement: draw a quadrangle and selected vertex */
	glPushMatrix();
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
			glBegin(GL_QUADS);
				glVertex2f(quadVtx[VTX1][0], quadVtx[VTX1][1]);
				glVertex2f(quadVtx[VTX2][0], quadVtx[VTX2][1]);
				glVertex2f(quadVtx[VTX3][0], quadVtx[VTX3][1]);
				glVertex2f(quadVtx[VTX4][0], quadVtx[VTX4][1]);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glPointSize(20.0f);
			glColor3f(colors[selVtx][0], colors[selVtx][1], colors[selVtx][2]);
				glBegin(GL_POINTS);
					glVertex2f(quadVtx[selVtx][0], quadVtx[selVtx][1]);
				glEnd();
		glPopMatrix();
	glPopMatrix();
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
	switch (key) {
	case '1':
		selVtx = VTX1;
		break;
	case '2':
		selVtx = VTX2;
		break;
	case '3':
		selVtx = VTX3;
		break;
	case '4':
		cout << selVtx << endl;
		selVtx = VTX4;
		break;
	}
	glutPostRedisplay();
}

void specialKeyDown(int key, int x, int y) {
	/* Implement: move the selected vertex with arrow keys */
	switch (key) {
	case GLUT_KEY_UP:
		quadVtx[selVtx][1] += 0.1f;
		break;
	case GLUT_KEY_DOWN:
		quadVtx[selVtx][1] -= 0.1f;
		break;
	case GLUT_KEY_LEFT:
		quadVtx[selVtx][0] -= 0.1f;
		break;
	case GLUT_KEY_RIGHT:
		quadVtx[selVtx][0] += 0.1f;
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
