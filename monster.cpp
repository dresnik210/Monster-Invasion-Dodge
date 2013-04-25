#include "monster.h"

Monster::Monster(QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{

}

Monster::~Monster()
{
	delete this;
}
