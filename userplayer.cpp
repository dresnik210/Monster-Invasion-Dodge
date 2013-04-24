#include "userplayer.h"

UserPlayer::UserPlayer(QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
	xCoor = 170;
	yCoor = 325;
	setPos(xCoor,yCoor);
	setScale(0.04);
}

void UserPlayer::moveLeft()
{
	xCoor = xCoor - 10;
	if(xCoor < -12)
	{
		xCoor = 350;
	}
	setPos(xCoor,yCoor);
}

void UserPlayer::moveRight()
{
	xCoor = xCoor + 10;
	if(xCoor > 350)
	{
		xCoor = -10;
	}
	setPos(xCoor,yCoor);
}

