#include "bouncer.h"

Bouncer::Bouncer(int x, int y, QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 5;
	yVelocity = 10;
	setPos(x,y);
	setScale(0.06);
	bounceCheck = 0;
}

void Bouncer::move()
{
	yCoor = yCoor + yVelocity;
	if(yCoor == 320 && bounceCheck == 0)
	{
		yVelocity = -yVelocity;
		bounceCheck = 1;
	}
	if(yCoor == 200 && yVelocity < 0)
	{
		yVelocity = -yVelocity;
	}
	setPos(xCoor,yCoor);
}

