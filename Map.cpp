#include "BubbleBobble.h"
#include <iostream>

Map::Map(int n) : stage(n) {}

void Map::drawMap() {
	if (stage == 1) drawStage1();
}
void Map::drawBlock(float x, float y, float width, float height) {
	setBorder(x, y, width);

	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y - height);
	glVertex2f(x, y - height);
	glEnd();
}
void Map::drawHard(float x, float y, float width, float height) {
	setHard(x, y, width, height);

	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y - height);
	glVertex2f(x, y - height);
	glEnd();
}
void Map::drawStage1() {
	//  the bottom layer
	glColor3f(0.0f, 1.0f, 1.0f);
	drawHard(-1.2f, -0.95f, 1.0f, 0.25f);
	drawHard(0.2f, -0.95f, 1.0f, 0.25f);

	//  the top layer
	drawHard(-1.2f, 1.2f, 1.0f, 0.25f);
	drawHard(0.2f, 1.2f, 1.0f, 0.25f);

	//  the first layer
	glColor3f(0.5f, 0.5f, 0.5f);
	drawBlock(-1.2f, -0.53f, 0.5f, 0.05f);
	drawBlock(0.7f, -0.53f, 0.5f, 0.05f);
	drawBlock(-0.4f, -0.53f, 0.8f, 0.05f);
	
	//  the second layer
	drawBlock(-1.2f, -0.11f, 0.5f, 0.05f);
	drawBlock(0.7f, -0.11f, 0.5f, 0.05f);
	drawBlock(-0.4f, -0.11f, 0.8f, 0.05f);

	//  the third layer
	drawBlock(-1.2f, 0.31f, 0.5f, 0.05f);
	drawBlock(0.7f, 0.31f, 0.5f, 0.05f);

	//  the middle object
	glColor3f(0.7f, 0.3f, 0.3f);
	drawHard(-0.4f, 0.36f, 0.8f, 0.10f);
	drawHard(-0.4f, 0.66f, 0.10f, 0.35f);
	drawHard(0.3f, 0.66f, 0.10f, 0.35f);

	glColor3f(0.0f, 1.0f, 1.0f);
	drawHard(-1.2f, 1.0f, 0.25f, 1.16f);
	drawHard(-1.2f, -0.53f, 0.25f, 0.47f);
	drawHard(0.95f, 1.0f, 0.25f, 1.16f);
	drawHard(0.95f, -0.53f, 0.25f, 0.47f);


}
//  set the border of block to distinguish the player's state
void Map::setBorder(float x, float y, float width) { 
	border.push_back(vector<float>());
	border.back().push_back(x);
	border.back().push_back(y);
	border.back().push_back(width);
}
void Map::setHard(float x, float y, float width, float height) {
	setBorder(x, y, width);

	borderHard.push_back(vector<float>());
	borderHard.back().push_back(x);
	borderHard.back().push_back(y);
	borderHard.back().push_back(width);
	borderHard.back().push_back(height);
}

bool Map::checkFALL() {
	float x, y, width;
	float pos[2]; 
	/*  
		the player's x coordinate range
		pos[0] means the left side of the player's bottom
		pos[1] means the right side of the player's bottom
	*/ 
	if (player.direction == RIGHT) {
		pos[0] = player.position[0] + 0.02f; 
		pos[1] = player.position[0] + 0.16f;
	}
	else {
		pos[0] = player.position[0] + 0.01f;
		pos[1] = player.position[0] + 0.15f;
	}
	for (auto i = 0; i < border.size(); i++) {
		x = border[i][0];
		y = border[i][1];
		width = border[i][2];
		//  check whether the player's left side or right side in the border's x coordinate range
		if ((x <= pos[0] && pos[0] <= x + width) ||
			(x <= pos[0] + 0.07f && pos[0] + 0.07f <= x + width) ||
			(x <= pos[1] && pos[1] <= x + width)) {
			//  check whether the player's y coordinate contacts the border's y coordinate
			if (y - 0.02f <= player.position[1] && player.position[1] <= y) {
				player.position[1] = y;
				player.state = STAY;
				return false;
			}
		}
	}
	return true;
}
void Map::checkJUMP() {
	float x, y, width, height;
	float pos[2];
	/*
	the player's x coordinate range
	pos[0] means the left side of the player's bottom
	pos[1] means the right side of the player's bottom
	*/
	if (player.direction == RIGHT) {
		pos[0] = player.position[0] + 0.02f;
		pos[1] = player.position[0] + 0.16f;
	}
	else {
		pos[0] = player.position[0] + 0.01f;
		pos[1] = player.position[0] + 0.15f;
	}
	for (auto i = 0; i < borderHard.size(); i++) {
		x = borderHard[i][0];
		y = borderHard[i][1];
		width = borderHard[i][2];
		height = borderHard[i][3];
		//  check whether the player's left side or right side in the borderHard's x coordinate range
		if ((x <= pos[0] && pos[0] <= x + width) || (x <= pos[1] && pos[1] <= x + width)) {
			//  check whether the player's height contacts the borderHard's y coordinate - height
			if (y - height <= player.position[1] + player.height && player.position[1] + player.height <= y - height + 0.08f) {
				player.position[1] = y - height - player.height;
			}
		}
	}
}
void Map::checkLEFT() {
	float x, y, width, height;
	float pos[2];
	/*
	the player's x coordinate range
	pos[0] means the left side of the player's bottom
	pos[1] means the right side of the player's bottom
	*/
	pos[0] = player.position[0] + 0.01f;
	pos[1] = player.position[0] + 0.15f;
	for (auto i = 0; i < borderHard.size(); i++) {
		x = borderHard[i][0];
		y = borderHard[i][1];
		width = borderHard[i][2];
		height = borderHard[i][3];
		//  check whether the player's height is in the borderHard's y coordinate range
		if ((y - height <= player.position[1] && player.position[1] < y) ||
			(y - height <= player.position[1] + 0.09f && player.position[1] + 0.09f <= y) ||
			(y - height < player.position[1] + player.height && player.position[1] + player.height <= y)) {
			//  check whether the player's left side contacts the borderHard's x coordinate + width
			if (x + width - 0.025f <= pos[0] && pos[0] <= x + width) {
				player.position[0] = x + width;
			}
		}
	}
}
void Map::checkRIGHT() {
	float x, y, width, height;
	float pos[2];
	/*
	the player's x coordinate range
	pos[0] means the left side of the player's bottom
	pos[1] means the right side of the player's bottom
	*/
	pos[0] = player.position[0] + 0.02f;
	pos[1] = player.position[0] + 0.16f;
	for (auto i = 0; i < borderHard.size(); i++) {
		x = borderHard[i][0];
		y = borderHard[i][1];
		width = borderHard[i][2];
		height = borderHard[i][3];
		//  check whether the player's height is in the borderHard's y coordinate range
		if ((y - height <= player.position[1] && player.position[1] < y) ||
			(y - height <= player.position[1] + 0.09f && player.position[1] + 0.09f <= y) ||
			(y - height < player.position[1] + player.height && player.position[1] + player.height <= y)) {
			//  check whether the player's left side contacts the borderHard's x coordinate + width
			if (x <= pos[1] && pos[1] <= x + 0.025f) {
				player.position[0] = x - 0.17f;
			}
		}
	}
}
