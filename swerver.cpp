#include "swerver.h"

Swerver::Swerver(int x, int y, QPixmap& pixmap) : Monster(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 8;
	yVelocity = 5;
	setPos(x,y);
	setScale(0.08);
}

void Swerver::move()
{
	if(xCoor >= 350)
	{
		xVelocity = -xVelocity;
	}
	if(xCoor <= 4)
	{
		xVelocity = -xVelocity;
	}
	xCoor = xCoor + xVelocity;
	yCoor = yCoor + yVelocity;
	setPos(xCoor,yCoor);
}

