#pragma once
#include "Helper.h"

class Enviroment
{
public:
	Enviroment();
	~Enviroment();
	void init();
	void drawWalls();
	void drawWallsBorder();
	void drawFloor();
private:
	Helper helper;
	GLfloat halfScreenWidth;
	GLfloat halfScreenHeight;
	GLfloat halfSideLenght;
};

