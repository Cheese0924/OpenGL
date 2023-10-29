#include <iostream>
#include <GL/freeglut.h>

using namespace std;

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

// Point class
class Point {
public:
	float color[3];
	float center[2];
	float pointSize;
	float speed;
};

Point pt1;	// falling point 1
Point pt2;	// falling point 2
float mPos[2];	// mouse position at clipping plane
bool bLMBDown;	// state of whether LBM is down

void initialize() {
	/* Implement */
	pt1.color[0] = 1.0f;
	pt1.color[1] = 0.0f;
	pt1.color[2] = 1.0f;
	pt1.center[0] = -0.2f;
	pt1.center[1] = -0.3f;
	pt1.pointSize = 10.0f;
	pt1.speed = 0.0001f;

	pt2.color[0] = 1.0f;
	pt2.color[1] = 1.0f;
	pt2.color[2] = 0.0f;
	pt2.center[0] = +0.3f;
	pt2.center[1] = +0.1f;
	pt2.pointSize = 20.0f;
	pt2.speed = 0.0002f;

	mPos[0] = 0.0f;
	mPos[1] = 0.0f;
	bLMBDown = false;
}

void idle() {
	/* Implement */
	if (bLMBDown == false) {
		if (pt1.center[1] < -1.0f) pt1.center[1] = 1.0f;
		if (pt2.center[1] < -1.0f) pt2.center[1] = 1.0f;

		pt1.center[1] -= pt1.speed;
		pt2.center[1] -= pt2.speed;
		glutPostRedisplay();
	}
}

void drawPoints() {
	/* Implement */
	glColor3f(pt1.color[0], pt1.color[1], pt1.color[2]);
	glPointSize(pt1.pointSize);
	glBegin(GL_POINTS);
	glVertex2f(pt1.center[0], pt1.center[1]);
	glEnd();

	glColor3f(pt2.color[0], pt2.color[1], pt2.color[2]);
	glPointSize(pt2.pointSize);
	glBegin(GL_POINTS);
	glVertex2f(pt2.center[0], pt2.center[1]);
	glEnd();
}

void drawTriangle() {
	/* Implement */
	if (bLMBDown == false) {
		glBegin(GL_POLYGON);
		glColor3f(pt1.color[0], pt1.color[1], pt1.color[2]);
		glVertex2f(pt1.center[0], pt1.center[1]);
		glColor3f(pt2.color[0], pt2.color[1], pt2.color[2]);
		glVertex2f(pt2.center[0], pt2.center[1]);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(mPos[0], mPos[1]);
		glEnd();
	}
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	drawPoints();
	drawTriangle();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	/* Implement */
	printf("(%d, %d, %d, %d)\n", button, state, x, y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		bLMBDown = true;
		pt1.center[0] = ((float)x - 320.0) / 320.0;
		pt1.center[1] = -((float)y - 320.0) / 320.0;
		pt2.center[0] = ((float)x - 320.0) / 320.0;
		pt2.center[1] = -((float)y - 320.0) / 320.0;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		bLMBDown = false;
	}
	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	/* Implement */
	printf("Moved(% d, % d)\n", x, y);
	pt2.center[0] = ((float)x - 320.0) / 320.0;
	pt2.center[1] = -((float)y - 320.0) / 320.0;
	glutPostRedisplay();
}

void mousePassiveMove(int x, int y) {
	/* Implement */
	printf("Passively - moved(% d, % d)\n", x, y);
	mPos[0] = ((float)x - 320.0) / 320.0;
	mPos[1] = -((float)y - 320.0) / 320.0;
	glutPostRedisplay();
}

void main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Draw a triangle with two falling points");

	initialize();

	// register callbacks
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMove);
	glutPassiveMotionFunc(mousePassiveMove);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}