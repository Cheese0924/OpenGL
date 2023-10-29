#pragma once

enum MONSTER {ROBOT, CREATURE, GHOST};

class Monster {
public:
	Monster(MONSTER Type);

	void drawMonster();
	void drawPixel(float x, float y, int n);
	void leftCreature();
	void rightCreature();
	void setPosition(float x, float y);
	
	MONSTER type;
	KEY direction;
	float position[2];
};

