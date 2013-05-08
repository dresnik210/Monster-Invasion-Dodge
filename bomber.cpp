#include "bomber.h"

Bomber::Bomber(int x, int y, QPixmap& pixmap, QPixmap& explosionPixmap) : Monster(pixmap)
{
	xCoor = x;
	yCoor = y;
	xVelocity = 0;
	yVelocity = 5;
	setPos(x,y);
	setScale(0.16);
	rotateCount = 0;
	explosion = new QGraphicsPixmapItem(explosionPixmap);
	explosion->setPos(500,500);
	explosion->setScale(0.2);
	playerXCoor = 0;
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
		setScale(0.18);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 9)
	{
		setScale(0.20);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 10)
	{
		setScale(0.22);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 11)
	{
		explosion->setPos(xCoor,yCoor);
		yCoor = 400;
		setPos(xCoor,yCoor);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 12)
	{
		explosion->setScale(0.12);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 13)
	{
		explosion->setScale(0.08);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 14)
	{
		explosion->setScale(0.06);
		rotateCount++;
	}
	else if(yCoor >= 370 && rotateCount == 15)
	{
		explosion->setPos(xCoor,450);
		yCoor = 450;
		setPos(xCoor,yCoor);
	}
		
}

void Bomber::setPlayerXCoor(int x)
{
	playerXCoor = x;
}

