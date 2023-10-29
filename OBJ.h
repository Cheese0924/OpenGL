#pragma once

#include <iostream>
#include <GL/freeglut.h>
#include <vector>
#include <fstream>
using namespace std;

class Vertex {
public:
	void setPos(float x, float y, float z);
		
	float pos[3];
};

class Face {
public:
	void setVertices(const Vertex& v1, const Vertex& v2, const Vertex& v3);
	void draw() const;

	Vertex vtx[3];
};

class OBJ {
public:
	void draw() const;
	void ReadOBJFile(string filename);

	vector<Face> vFace;
};