#include "rocket.h"

Rocket::Rocket(int x, int y, QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
	xCoor = x;
	yCoor = y;
	setPos(x,y);
	setScale(0.08);
}

void Rocket::move()
{

}

