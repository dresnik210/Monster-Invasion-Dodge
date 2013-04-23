#include "bomber.h"

Bomber::Bomber(int x, int y, QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
	//monsterPic = new QGraphicsPixmapItem(pixmap);
	xCoor = x;
	yCoor = y;
	setPos(x,y);
	setScale(0.08);
}

void Bomber::move()
{

}

