#pragma once
#include "Helper.h"

class Enemy
{
public:
	Enemy();
	Enemy(int health, int damage);
	~Enemy();
	void render();
	void move();
	void scale();
	void rotate();
	
	inline int getHealth() const;
	inline int getDamage() const;
	inline GLfloat getShootArea() const;

	void setHealth();
	void setDamage();
	void setShootArea();
private:
	int m_health;
	int m_damage;
	GLfloat shootArea[4];
	Helper helper;
	GLfloat halfScreenWidth;
	GLfloat halfScreenHeight;
	GLfloat halfSideLenght;
};

