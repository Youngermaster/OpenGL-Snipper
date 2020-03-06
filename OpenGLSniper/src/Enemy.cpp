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
	// this->shootArea[] = { 0, 0, 0, 0 };
}

Enemy::~Enemy() {}

void Enemy::render() {
	GLfloat colorRed[]{
		255, 0, 0,
		255, 0, 0,
		255, 0, 0,
		255, 0, 0,
		255, 0, 0,
		255, 0, 0,
		255, 0, 0,
		255, 0, 0,
	};

	GLfloat body[]{
		halfScreenWidth - 30, halfScreenHeight + halfSideLenght + 20, 0,
		halfScreenWidth - 20, halfScreenHeight + halfSideLenght - 50, 0,

		halfScreenWidth + 30, halfScreenHeight + halfSideLenght - 50, 0,
		halfScreenWidth + 40, halfScreenHeight + halfSideLenght + 20, 0,
	};

	GLfloat head[]{
		halfScreenWidth - 30, halfScreenHeight + halfSideLenght + 20, 0,
		halfScreenWidth - 20, halfScreenHeight + halfSideLenght - 50, 0,

		halfScreenWidth + 30, halfScreenHeight + halfSideLenght - 50, 0,
		halfScreenWidth + 40, halfScreenHeight + halfSideLenght + 20, 0,
	};

	this->helper.drawPolygon(body, 4, colorRed);
}