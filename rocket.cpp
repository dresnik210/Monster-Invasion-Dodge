#include "rocket.h"

Rocket::Rocket(int x, int y, QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 0;
	yVelocity = 12;
	setPos(x,y);
	setScale(0.08);
}

void Rocket::move()
{
	yCoor = yCoor + yVelocity;
	setPos(xCoor,yCoor);
}

