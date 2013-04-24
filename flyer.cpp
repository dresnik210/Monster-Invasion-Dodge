#include "flyer.h"

Flyer::Flyer(int x, int y, QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 8;
	yVelocity = 8;
	setPos(x,y);
	setScale(0.08);
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
	if(xCoor >= 370)
	{
		xCoor = -10;
	}
	setPos(xCoor,yCoor);
}

