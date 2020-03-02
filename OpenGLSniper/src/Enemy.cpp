#include "Enemy.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


Enemy::Enemy() :
	m_health(1), m_damage(1) {
	this->helper = Helper();
	this->halfScreenWidth = SCREEN_WIDTH / 2;
	this->halfScreenHeight = SCREEN_HEIGHT / 2;
	this->halfSideLenght = 100;
}

Enemy::Enemy(int health, int damage) :
	m_health(health), m_damage(damage) {
	this->helper = Helper();
	this->halfScreenWidth = SCREEN_WIDTH / 2;
	this->halfScreenHeight = SCREEN_HEIGHT / 2;
	this->halfSideLenght = 100;
}

Enemy::~Enemy() {}

void Enemy::render() {
	GLfloat body[]{
		halfScreenWidth - 20, halfScreenHeight + halfSideLenght + 20, 0,
		halfScreenWidth - 20, halfScreenHeight + halfSideLenght, 0,
		halfScreenWidth - 10, halfScreenHeight + halfSideLenght, 0,
		halfScreenWidth - 10, halfScreenHeight + halfSideLenght - 50, 0,

		halfScreenWidth + 40, halfScreenHeight + halfSideLenght - 50, 0,
		halfScreenWidth + 40, halfScreenHeight + halfSideLenght, 0,
		halfScreenWidth + 50, halfScreenHeight + halfSideLenght, 0,
		halfScreenWidth + 50, halfScreenHeight + halfSideLenght+ 20, 0,
	};

	this->helper.drawPolygon(body, 8);
}