#ifndef BOMBER_H
#define BOMBER_H

#include "monster.h"

class Bomber : public Monster, public QGraphicsPixmapItem
{
  public:
  	Bomber(int x, int y, QPixmap& pixmap, QPixmap& explosionPixmap);
  	void move();
  	QGraphicsPixmapItem* explosion;
  private:
  	int rotateCount;
};

#endif
