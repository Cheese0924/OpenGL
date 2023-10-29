#pragma once
#include "Material.h" 

enum SHAPE { SPHERE, CUBE, TEAPOT, CONE, TORUS, DODECAHEDRON, ICOSAHEDRON, OCTAHEDRON };

class Shape3D {
public:		
	void setShape(SHAPE shp);
	void setPos(float x, float y, float z);
	void setAngleOfSpin(float ang);
	void setAngleOfRevolution(float ang);
	void setSize(float s);
	void setMTL(const Material& m);
	void draw() const;
	
	SHAPE shape;
	float pos[3];
	float angleOfSpin;
	float angleOfRevolution;
	float size;
	Material mtl;
};

