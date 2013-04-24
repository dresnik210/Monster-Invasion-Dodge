#include "bomber.h"

Bomber::Bomber(int x, int y, QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 0;
	yVelocity = 5;
	setPos(x,y);
	setScale(0.16);
	rotateCount = 0;
}

void Bomber::move()
{
	if(yCoor < 370)
	{
		yCoor = yCoor + yVelocity;
		setPos(xCoor,yCoor);
	}
	else if(yCoor >= 370 && rotateCount == 0)
	{
		setRotation(20);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 1)
	{
		setRotation(0);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 2)
	{
		setRotation(-20);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 3)
	{
		setRotation(0);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 4)
	{
		setRotation(20);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 5)
	{
		setRotation(0);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 6)
	{
		setRotation(-20);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 7)
	{
		setRotation(0);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 8)
	{
		yCoor = yCoor + yVelocity;
		setPos(xCoor,yCoor);
	}
}

