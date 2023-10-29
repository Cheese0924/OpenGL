#include "BubbleBobble.h"

Monster::Monster(MONSTER Type) {
	type = Type;
}

void Monster::drawMonster() {
	if (type == CREATURE) {
		if (direction == LEFT) this->leftCreature();
		else this->rightCreature();
	}
}
void Monster::drawPixel(float x, float y, int n) {
	glBegin(GL_POLYGON);
	glVertex2f(position[0] + x, position[1] + y);
	glVertex2f(position[0] + x, position[1] + y + 0.01f);
	glVertex2f(position[0] + x + n * 0.01f, position[1] + y + 0.01f);
	glVertex2f(position[0] + x + n * 0.01f, position[1] + y);
	glEnd();
}
void Monster::leftCreature() {

}
void Monster::rightCreature() {

}
void Monster::setPosition(float x, float y) {
	position[0] += x;
	position[1] += y;
}