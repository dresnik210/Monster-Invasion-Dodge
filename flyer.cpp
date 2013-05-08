#include "flyer.h"

Flyer::Flyer(int x, int y, QPixmap& pixmap) : Monster(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = -8;
	yVelocity = 8;
	setPos(x,y);
	setScale(0.10);
	playerXCoor = 0;
}

void Flyer::move()
{
	switch(rand() % 2)
	{
		case 0:
			xCoor = xCoor + xVelocity;
			break;
		case 1:
			yCoor = yCoor + yVelocity;
			break;
	}
	if(xCoor <= -5)
	{
		xCoor = 368;
	}
	setPos(xCoor,yCoor);
}

void Flyer::setPlayerXCoor(int x)
{
	playerXCoor = x;
}

