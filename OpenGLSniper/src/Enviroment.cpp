#include "Enviroment.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

Enviroment::Enviroment() {

	this->helper = Helper();
	this->halfScreenWidth = SCREEN_WIDTH / 2;
	this->halfScreenHeight = SCREEN_HEIGHT / 2;
	this->halfSideLenght = 100;
}

Enviroment::~Enviroment() {}

void Enviroment::init() {
	/*
	GLfloat quadVertices[]
	{
		SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 * 2, 0.0,
		SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT / 3 * 2, 0.0,
		SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT / 3, 0.0,
		SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, 0.0
	};


	GLfloat triangleVertices[]{
		this->halfScreenWidth, this->halfScreenHeight + this->halfSideLenght, 0.0,
		this->halfScreenWidth - this->halfSideLenght, this->halfScreenHeight, 0.0,
		this->halfScreenWidth + this->halfSideLenght, this->halfScreenHeight, 0.0,
	};

	GLfloat test[]{
		20, 100, 0,
		40, 40, 0,
		500, 50, 0,
		320, 10, 0,
		100, 100, 0,
	};
	this->helper.drawQuad(quadVertices);
	this->helper.drawLineStripLoop(triangleVertices, 3, true);
	this->helper.drawPolygon(test, 5, true);
	*/
	drawWallsBorder();
	drawWalls();
	drawFloor();
}

void Enviroment::drawWalls() {
	GLfloat colorBlue[]{
		190, 60, 0,
		190, 60, 0,
		190, 60, 0,
		190, 60, 0,
	};

	GLfloat frontWall[] {
		this->halfScreenWidth - this->halfSideLenght, this->halfScreenHeight + (this->halfSideLenght * 2.3), 0.0,
		this->halfScreenWidth - this->halfSideLenght, this->halfScreenHeight + this->halfSideLenght, 0.0,
		this->halfScreenWidth + this->halfSideLenght, this->halfScreenHeight + this->halfSideLenght, 0.0,
		this->halfScreenWidth + this->halfSideLenght, this->halfScreenHeight + (this->halfSideLenght * 2.3), 0.0,
	};

	GLfloat rightWall[] {
		this->halfScreenWidth + this->halfSideLenght + 1, this->halfScreenHeight + (this->halfSideLenght * 2.3), 0.0,
		this->halfScreenWidth + this->halfSideLenght + 1, this->halfScreenHeight + this->halfSideLenght, 0.0,
		SCREEN_WIDTH * 3 / 2, -SCREEN_HEIGHT, 0,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0
	};

	GLfloat leftWall[] {
		this->halfScreenWidth - this->halfSideLenght - 1, this->halfScreenHeight + (this->halfSideLenght * 2.3), 0.0,
		this->halfScreenWidth - this->halfSideLenght - 1, this->halfScreenHeight + this->halfSideLenght, 0.0,
		-this->halfScreenWidth, -SCREEN_HEIGHT, 0,
		0, SCREEN_HEIGHT, 0
	};

	this->helper.drawPolygon(frontWall, 4, colorBlue);
	this->helper.drawPolygon(rightWall, 4, colorBlue);
	this->helper.drawPolygon(leftWall, 4, colorBlue);
}

void Enviroment::drawFloor() {
	GLfloat colorGreen[]{
		0, 255, 0,
		0, 255, 0,
		0, 255, 0,
		0, 255, 0,
	};

	GLfloat floor[] {
		this->halfScreenWidth - this->halfSideLenght + 1, this->halfScreenHeight + this->halfSideLenght - 1, 0.0,
		-this->halfScreenWidth, -SCREEN_HEIGHT, 0,
		SCREEN_WIDTH * 3 / 2, -SCREEN_HEIGHT, 0,
		this->halfScreenWidth + this->halfSideLenght - 1, this->halfScreenHeight + this->halfSideLenght - 1, 0.0,
	};

	this->helper.drawPolygon(floor, 4, colorGreen);
}

void Enviroment::drawWallsBorder() {
	GLfloat frontWall[] {
		this->halfScreenWidth - this->halfSideLenght - 1, 1 + this->halfScreenHeight + (this->halfSideLenght * 2.3), 0.0,
		this->halfScreenWidth - this->halfSideLenght - 1, this->halfScreenHeight + this->halfSideLenght - 1, 0.0,
		this->halfScreenWidth + this->halfSideLenght + 1, this->halfScreenHeight + this->halfSideLenght - 1, 0.0,
		this->halfScreenWidth + this->halfSideLenght + 1, 1 + this->halfScreenHeight + (this->halfSideLenght * 2.3), 0.0,
	};

	GLfloat rightWall[] {
		this->halfScreenWidth + this->halfSideLenght - 1, this->halfScreenHeight + (this->halfSideLenght * 2.3) + 1, 0.0,
		this->halfScreenWidth + this->halfSideLenght - 1, this->halfScreenHeight + this->halfSideLenght - 1, 0.0,
		SCREEN_WIDTH * 3 / 2 + 1, -SCREEN_HEIGHT - 1, 0,
		SCREEN_WIDTH + 1, SCREEN_HEIGHT + 1, 0
	};

	GLfloat leftWall[] {
		this->halfScreenWidth - this->halfSideLenght + 1, this->halfScreenHeight + (this->halfSideLenght * 2.3) + 1, 0.0,
		this->halfScreenWidth - this->halfSideLenght + 1, this->halfScreenHeight + this->halfSideLenght - 1, 0.0,
		-this->halfScreenWidth - 1, -SCREEN_HEIGHT + 1, 0,
		-1, SCREEN_HEIGHT + 1 , 0
	};

	this->helper.drawPolygon(frontWall, 4);
	this->helper.drawPolygon(rightWall, 4);
	this->helper.drawPolygon(leftWall, 4);
}