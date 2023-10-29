#include <vector>

#include "Shape3D.h"
#include "Light.h"

using namespace std;

#define WINDOW_X 300
#define WINDOW_Y 300

#define WINDOW_WIDTH 640		// window's width
#define WINDOW_HEIGHT 640		// window's height

vector<Shape3D> shape3d;
vector<Light> lights;

float angle = 0.0f;

void initialize() {
	/* Implement: create lights and shape3d */
	// lights setting
	Light light0;
	Light light1;

	light0.setLightID(GL_LIGHT0);
	light0.setPosition(0.0f, 50.0f, 0.0f);
	light0.setAmbient(0.4f, 0.5f, 0.5f, 0.5f);
	light0.setDiffuse(0.8f, 0.5f, 0.5f, 0.5f);
	light0.setSpecular(0.8f, 0.5f, 0.5f, 0.5f);
	light0.enableLight(0);

	light1.setLightID(GL_LIGHT1);
	light1.setPosition(50.0f, 0.0f, 0.0f);
	light1.setAmbient(0.5f, 0.5f, 0.5f, 0.5f);
	light1.setDiffuse(0.1f, 0.5f, 0.5f, 0.5f);
	light1.setSpecular(0.1f, 0.5f, 0.5f, 0.5f);
	light1.enableLight(0);

	lights.push_back(light0);
	lights.push_back(light1);

	// material setting
	Material copper;
	Material brass;
	Material red;

	copper.setEmission(0.05f, 0.05f, 0.05f, 1.0f);
	copper.setAmbient(0.19125f, 0.0735f, 0.0225f, 1.0f);
	copper.setDiffuse(0.7038f, 0.27048f, 0.0828f, 1.0f);
	copper.setSpecular(0.256777f, 0.137622f, 0.086014f, 1.0f);
	copper.setShininess(12.8f);

	brass.setEmission(0.05f, 0.05f, 0.05f, 1.0f);
	brass.setAmbient(0.329412f, 0.223529f, 0.027451f, 1.0f);
	brass.setDiffuse(0.780392f,	0.568627f, 0.113725f, 1.0f);
	brass.setSpecular(0.992157f, 0.941176f, 0.807843f, 1.0f);
	brass.setShininess(27.89743616f);

	red.setEmission(0.05f, 0.05f, 0.05f, 1.0f);
	red.setAmbient(0.0f, 0.0f, 0.0f, 1.0f);
	red.setDiffuse(0.55f, 0.55f, 0.55f, 1.0f);
	red.setSpecular(0.7f, 0.7f, 0.7f, 1.0f);
	copper.setShininess(32.0f);


	// 3D objects setting
	Shape3D torus;
	Shape3D icosahedron;
	Shape3D teapot;

	torus.setShape(TORUS);
	torus.setPos(0.0f, 0.0f, 0.0f);
	torus.setAngleOfSpin(angle);
	torus.setAngleOfRevolution(0);
	torus.setSize(0.5f);
	torus.setMTL(copper);

	icosahedron.setShape(ICOSAHEDRON);
	icosahedron.setPos(2.0f, 3.0f, 4.0f);
	icosahedron.setAngleOfSpin(angle);
	icosahedron.setAngleOfRevolution(angle);
	icosahedron.setSize(0.5f);
	icosahedron.setMTL(brass);

	teapot.setShape(TEAPOT);
	teapot.setPos(5.0f, 1.0f, 0.0f);
	teapot.setAngleOfSpin(angle);
	teapot.setAngleOfRevolution(angle);
	teapot.setSize(0.5f);
	teapot.setMTL(red);

	shape3d.push_back(torus);
	shape3d.push_back(icosahedron);
	shape3d.push_back(teapot);
}

void idle() {
	angle += 0.01f; // slow
	//angle += 1.0f;	// fast
	
	shape3d[0].setAngleOfSpin(2*angle);
	shape3d[0].setAngleOfRevolution(angle);
	shape3d[1].setAngleOfSpin(3*angle);
	shape3d[1].setAngleOfRevolution(2*angle);
	shape3d[2].setAngleOfSpin(5*angle);
	shape3d[2].setAngleOfRevolution(angle);

	glutPostRedisplay();
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10.0, 10.0, 10.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	/* Implement: draw lights and shape3d */
	if (lights[0].isLightOn()) glEnable(lights[0].lightID);
	if (lights[1].isLightOn()) glEnable(lights[1].lightID);

	if (lights[0].isLightOn()) lights[0].draw();
	if (lights[1].isLightOn()) lights[1].draw();

	shape3d[0].draw();
	shape3d[1].draw();
	shape3d[2].draw();

	if (lights[1].isLightOn()) glDisable(lights[1].lightID);
	if (lights[0].isLightOn()) glDisable(lights[0].lightID);

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

void keyboardDown(unsigned char key, int x, int y) {
	/* Implement: turn on/off lights */
	switch (key) {
	case '1':
		if (lights[0].isLightOn()) lights[0].enableLight(0);
		else lights[0].enableLight(1);
		break;
	case '2':
		if (lights[1].isLightOn()) lights[1].enableLight(0);
		else lights[1].enableLight(1);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Draw three 3D-shapes with 2 lights");

	initialize();

	// register callbacks
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardDown);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
