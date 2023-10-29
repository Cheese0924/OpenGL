#include "Shape3D.h"

void Shape3D::setShape(SHAPE shp) {
	shape = shp;
}
void Shape3D::setPos(float x, float y, float z) {
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
}
void Shape3D::setAngleOfSpin(float ang) {
	angleOfSpin = ang;
}
void Shape3D::setAngleOfRevolution(float ang) {
	angleOfRevolution = ang;
}
void Shape3D::setSize(float s) {
	size = s;
}
void Shape3D::setMTL(const Material& m) {
	mtl = m;
}
void Shape3D::draw() const {
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_EMISSION, mtl. emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.shininess);

	glPushMatrix();
		glRotatef(angleOfRevolution, 0.0f, 1.0f, 0.0f);
		glTranslatef(pos[0], pos[1], pos[2]);
		glRotatef(angleOfSpin, 1.0f, 1.0f, 0.0f);
		switch (shape) {
		case SPHERE:
			glutSolidSphere(size, 10, 10);
			break;
		case CUBE:
			glutSolidCube(size);
			break;
		case TEAPOT:
			glutSolidTeapot(size);
			break;
		case CONE:
			glutSolidCone(size, 1.5f*size, 10, 10);
			break;
		case TORUS:
			glutSolidTorus(size, 2.0f*size, 10, 10);
			break;
		case DODECAHEDRON:
			glutSolidDodecahedron();
			break;
		case ICOSAHEDRON:
			glutSolidIcosahedron();
			break;
		case OCTAHEDRON:
			glutSolidOctahedron();
			break;
		}
	glPopMatrix();
}