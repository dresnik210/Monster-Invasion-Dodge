#include "bouncer.h"

Bouncer::Bouncer(int x, int y, QPixmap& pixmap) : Monster(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 0;
	yVelocity = 10;
	setPos(x,y);
	setScale(0.08);
	bounceCheck = 0;
	playerXCoor = 0;
}

/** Moves monster for animation */
void Bouncer::move()
{
	yCoor = yCoor + yVelocity;
	xCoor = xCoor + xVelocity;
	if(yCoor == 380 && bounceCheck == 0)
	{
		yVelocity = -yVelocity;
		xVelocity = (playerXCoor-xCoor)/50;
		bounceCheck = 1;
	}
	if(yCoor == 200 && yVelocity < 0)
	{
		yVelocity = -yVelocity;
	}
	setPos(xCoor,yCoor);
}

/** Imports location of player */
void Bouncer::setPlayerXCoor(int x)
{
	playerXCoor = x;
}

