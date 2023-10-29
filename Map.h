#pragma once
#include <vector>
using namespace std;

class Map {
public:
	Map(int n);
	void drawMap();
	void drawBlock(float x, float y, float width, float height);
	void drawHard(float x, float y, float width, float height);
	void drawStage1();
	void setBorder(float x, float y, float width);
	void setHard(float x, float y, float width, float height);
	bool checkFALL();
	void checkJUMP();
	void checkLEFT();
	void checkRIGHT();

	int stage;
	vector<vector<float>> border;
	vector<vector<float>> borderHard;
};

