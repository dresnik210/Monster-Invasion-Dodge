#include "rocket.h"

Rocket::Rocket(int x, int y, QPixmap& pixmap) : Monster(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 0;
	yVelocity = 12;
	setPos(x,y);
	setScale(0.08);
	playerXCoor = 0;
}

/** Moves monster for animation */
void Rocket::move()
{
	yCoor = yCoor + yVelocity;
	setPos(xCoor,yCoor);
}

/** Imports location of player */
void Rocket::setPlayerXCoor(int x)
{
	playerXCoor = x;
}

