#include "bomber.h"

Bomber::Bomber(int x, int y, QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 0;
	yVelocity = 5;
	setPos(x,y);
	setScale(0.16);
}

void Bomber::move()
{
	yCoor = yCoor + yVelocity;
	setPos(xCoor,yCoor);
}

