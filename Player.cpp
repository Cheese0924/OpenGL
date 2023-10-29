#include "BubbleBobble.h"

Player::Player() : direction(RIGHT), state(STAY), height(0.18f) {
	//  initial position of the player
	position[0] = -0.9f; position[1] = -0.95f;
}

void Player::drawPlayer() {
	if (direction == LEFT) this->leftDragon();
	else this->rightDragon();
}
void Player::drawPixel(float x, float y, int n) {
	glBegin(GL_POLYGON);
	glVertex2f(position[0] + x, position[1] + y);
	glVertex2f(position[0] + x, position[1] + y + 0.01f);
	glVertex2f(position[0] + x + n * 0.01f, position[1] + y + 0.01f);
	glVertex2f(position[0] + x + n * 0.01f, position[1] + y);
	glEnd();
}
void Player::leftDragon() {
	// black
	glColor3f(0.0f, 0.0f, 0.0f);
	float y = 0.0f;
	drawPixel(0.01f, y, 15);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 2);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 2);
	drawPixel(0.14f, y, 2);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.14f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 3);
	drawPixel(0.06f, y, 3);
	drawPixel(0.13f, y, 2);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.13f, y, 2);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.12f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.05f, y, 2);
	drawPixel(0.10f, y, 4);

	y += 0.01f;
	drawPixel(0.07f, y, 1);
	drawPixel(0.09f, y, 1);

	y += 0.01f;
	drawPixel(0.08f, y, 1);

	// green pixel
	glColor3f(0.5f, 1.0f, 0.2f);
	y = 0.0f;;
	y += 0.01f;
	drawPixel(0.11f, y, 4);

	y += 0.01f;
	drawPixel(0.10f, y, 6);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.13f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.08f, y, 2);
	drawPixel(0.13f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 7);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 2);
	drawPixel(0.05f, y, 1);
	drawPixel(0.08f, y, 5);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.05f, y, 1);
	drawPixel(0.09f, y, 4);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.05f, y, 1);
	drawPixel(0.09f, y, 4);

	y += 0.01f;
	drawPixel(0.05f, y, 1);
	drawPixel(0.09f, y, 4);

	y += 0.01f;
	drawPixel(0.05f, y, 1);
	drawPixel(0.09f, y, 3);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.05f, y, 1);
	drawPixel(0.08f, y, 4);

	y += 0.01f;
	drawPixel(0.04f, y, 7);

	y += 0.01f;
	drawPixel(0.05f, y, 5);

	// white pixel
	glColor3f(1.0f, 1.0f, 1.0f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.04f, y, 3);

	y += 0.01f;
	drawPixel(0.03f, y, 5);

	y += 0.01f;
	drawPixel(0.03f, y, 6);

	y += 0.01f;
	drawPixel(0.04f, y, 4);

	y += 0.02f;
	drawPixel(0.05f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 2);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 2);

	// red pixel
	glColor3f(1.0f, 0.5f, 0.25f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.01f, y, 3);
	drawPixel(0.07f, y, 4);

	y += 0.01f;
	drawPixel(0.08f, y, 2);

	y += 0.01f;
	drawPixel(0.11f, y, 2);
	drawPixel(0.14f, y, 2);

	y += 0.01f;
	drawPixel(0.10f, y, 3);

	y += 0.01f;
	drawPixel(0.10f, y, 3);

	y += 0.01f;
	drawPixel(0.11f, y, 1);

	y += 0.01f;
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.13f, y, 2);

	y += 0.02f;
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.12f, y, 3);

	y += 0.02f;
	drawPixel(0.11f, y, 2);

	y += 0.01f;
	drawPixel(0.10f, y, 4);

	y += 0.01f;
	drawPixel(0.07f, y, 3);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
}
void Player::rightDragon() {
	// black pixel
	glColor3f(0.0f, 0.0f, 0.0f);
	float y = 0.0f;
	drawPixel(0.02f, y, 15);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.15f, y, 2);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.02f, y, 2);
	drawPixel(0.14f, y, 2);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.03f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 2);
	drawPixel(0.09f, y, 3);
	drawPixel(0.13f, y, 3);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 2);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.05f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 4);
	drawPixel(0.11f, y, 2);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.1f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 1);

	// green pixel
	glColor3f(0.5f, 1.0f, 0.2f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.03f, y, 4);

	y += 0.01f;
	drawPixel(0.02f, y, 6);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.08f, y, 2);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.08f, y, 7);

	y += 0.01f;
	drawPixel(0.05f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.05f, y, 5);
	drawPixel(0.12f, y, 1);
	drawPixel(0.14f, y, 2);

	y += 0.01f;
	drawPixel(0.05f, y, 4);
	drawPixel(0.12f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.05f, y, 4);
	drawPixel(0.12f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.05f, y, 4);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.06f, y, 3);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.06f, y, 4);
	drawPixel(0.12f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.07f, y, 7);

	y += 0.01f;
	drawPixel(0.08f, y, 5);

	// white pixel
	glColor3f(1.0f, 1.0f, 1.0f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.11f, y, 3);

	y += 0.01f;
	drawPixel(0.1f, y, 5);

	y += 0.01f;
	drawPixel(0.09f, y, 6);

	y += 0.01f;
	drawPixel(0.1f, y, 4);

	y += 0.02f;
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.1f, y, 2);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.1f, y, 2);
	drawPixel(0.13f, y, 1);

	// red pixel
	glColor3f(1.0f, 0.5f, 0.25f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.07f, y, 4);
	drawPixel(0.14f, y, 3);

	y += 0.01f;
	drawPixel(0.08f, y, 2);

	y += 0.01f;
	drawPixel(0.02f, y, 2);
	drawPixel(0.05f, y, 2);

	y += 0.01f;
	drawPixel(0.05f, y, 3);

	y += 0.01f;
	drawPixel(0.05f, y, 3);

	y += 0.01f;
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 2);

	y += 0.02f;
	drawPixel(0.04f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 3);

	y += 0.02f;
	drawPixel(0.05f, y, 2);

	y += 0.01f;
	drawPixel(0.04f, y, 4);

	y += 0.01f;
	drawPixel(0.08f, y, 3);

	y += 0.01f;
	drawPixel(0.09f, y, 1);
}
void Player::setPosition(float x, float y) {
	position[0] += x;
	position[1] += y;
	//  when the player is out of the window, change the position of the player
	//  the left side
	if ((direction == LEFT) && (position[0] + 0.01f < -1.2f)) {
		player.position[0] = 1.05f;
	}
	//  the right side
	else if ((direction == RIGHT) && (position[0] + 0.16f > 1.2f)) {
		player.position[0] = -1.18f;
	}

	//  when the player is dropped in the bottom hole
	if (player.position[1] < -1.2f) {
		player.position[1] = 1.0f;
	}
}