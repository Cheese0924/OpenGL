#include "OBJ.h"

// Vertex member function
void Vertex::setPos(float x, float y, float z) {
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
};

// Face member function
void Face::setVertices(const Vertex& v1, const Vertex& v2, const Vertex& v3) {
	vtx[0] = v1;
	vtx[1] = v2;
	vtx[2] = v3;
};
void Face::draw() const {
	glBegin(GL_TRIANGLES);
		glVertex3f(vtx[0].pos[0], vtx[0].pos[1], vtx[0].pos[2]);
		glVertex3f(vtx[1].pos[0], vtx[1].pos[1], vtx[1].pos[2]);
		glVertex3f(vtx[2].pos[0], vtx[2].pos[1], vtx[2].pos[2]);
	glEnd();
};

// OBJ member function
void OBJ::draw() const {
	float color;
	for (int i = 0; i < 12; i++) {
		color = 1.8f / float(i / 2);
		glColor3f(color, color, color);
		vFace[i].draw();
	}
};
void OBJ::ReadOBJFile(string filename) {
	vector<Vertex> vertices;
	ifstream input(filename);
	char sub;
	while (input >> sub) {
		if (sub == 'v') {
			/* read vertex data */
			Vertex vertex;
			float x, y, z;
			input >> x; input >> y; input >> z;
			vertex.setPos(x, y ,z);
			vertices.push_back(vertex);
		}
		else if (sub == 'f') {
			/* read face data */
			Face face;
			int a, b, c;
			input >> a; input >> b; input >> c;
			face.setVertices(vertices[a - 1], vertices[b - 1], vertices[c - 1]);
			vFace.push_back(face);
		}
	}
};
