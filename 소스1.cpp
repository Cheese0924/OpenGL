#include <iostream>
#include <GL/freeglut.h>

using namespace std;

enum MENU { QUIT = -1, CLEAR = 0, DRAW_POINTS, DRAW_LINES, DRAW_LINE_STRIP, DRAW_LINE_LOOP } popupMenu;

const int pointSize = 6;
const int pDim = 2;
const int cDim = 3;
float pts[pointSize][pDim];
float color[pointSize][cDim];

void drawPrimitives(int);

void createPoints() {
	pts[0][0] = -0.8f;	pts[0][1] = -0.8f;
	pts[1][0] = -0.2f;	pts[1][1] = -0.8f;
	pts[2][0] = -0.5f;	pts[2][1] = 0.8f;
	pts[3][0] = 0.2f;	pts[3][1] = 0.8f;
	pts[4][0] = 0.5f;	pts[4][1] = -0.8f;
	pts[5][0] = 0.8f;	pts[5][1] = 0.8f;

	color[0][0] = 1.0f;	color[0][1] = 0.0f;	color[0][2] = 0.0f;
	color[1][0] = 0.0f;	color[1][1] = 1.0f;	color[1][2] = 0.0f;
	color[2][0] = 0.0f;	color[2][1] = 0.0f;	color[2][2] = 1.0f;
	color[3][0] = 1.0f;	color[3][1] = 1.0f;	color[3][2] = 0.0f;
	color[4][0] = 0.0f;	color[4][1] = 1.0f;	color[4][2] = 1.0f;
	color[5][0] = 1.0f;	color[5][1] = 0.0f;	color[5][2] = 1.0f;
}

void sub_menu(int option) {
	popupMenu = (MENU)option;

	glutPostRedisplay();
}

void main_menu(int option) {
	if (option == QUIT)
		exit(0);

	popupMenu = (MENU)option;

	glutPostRedisplay();
}

void createPopupMenu() {
	/* Implement: create popup menu */
	int mainmenu, submenu1, submenu2;

	submenu2 = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Lines", DRAW_LINES);
	glutAddMenuEntry("Line Strip", DRAW_LINE_STRIP);
	glutAddMenuEntry("Line Loop", DRAW_LINE_LOOP);

	submenu1 = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Point", DRAW_POINTS);
	glutAddSubMenu("Line", submenu2);

	mainmenu = glutCreateMenu(main_menu);
	glutAddMenuEntry("Quit", QUIT);
	glutAddMenuEntry("Clear", CLEAR);
	glutAddSubMenu("Draw", submenu1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void drawPrimitives(int option) {
	/* Implement: draw primitives */
	if (option == DRAW_POINTS) {
		glPointSize(10.0f);
		glBegin(GL_POINTS);
		for (int i = 0; i < 6; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		glEnd();
	}
	else if (option == DRAW_LINES) {
		glLineWidth(5.0f);
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(3, 0xFFFF);
		glBegin(GL_LINES);
		for (int i = 0; i < 6; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		glEnd();
	}
	else if (option == DRAW_LINE_STRIP) {
		glLineWidth(5.0f);
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(3, 0xFFFF);
		glBegin(GL_LINES);
		for (int i = 0; i < 6; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		for (int i = 1; i < 5; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		glEnd();
	}
	else if (option == DRAW_LINE_LOOP) {
		glLineWidth(5.0f);
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(3, 0xFFFF);
		glBegin(GL_LINES);
		for (int i = 0; i < 6; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		for (int i = 1; i < 5; i++) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		for (int i = 0; i < 6; i += 5) {
			glColor3f(color[i][0], color[i][1], color[i][2]);
			glVertex2f(pts[i][0], pts[i][1]);
		}
		glEnd();
	}

}

void renderScene() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	drawPrimitives(popupMenu);

	//glFlush();
	glFinish();
}

int main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Draw primitives using popup menu");

	createPopupMenu();
	createPoints();

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
