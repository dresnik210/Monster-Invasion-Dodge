#ifndef BOMBER_H
#define BOMBER_H

#include "monster.h"

class Bomber : public Monster
{
  public:
  	Bomber(int x, int y, QPixmap& pixmap, QPixmap& explosionPixmap);
  	void move();
  	void setPlayerXCoor(int x);
  	QGraphicsPixmapItem* explosion;
  private:
  	int rotateCount;
};

#endif
