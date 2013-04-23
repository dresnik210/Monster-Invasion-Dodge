#ifndef BOMBER_H
#define BOMBER_H

#include "monster.h"

class Bomber : public Monster, public QGraphicsPixmapItem
{
  public:
  	Bomber(int x, int y, QPixmap& pixmap);
  	void move();
  private:

};

#endif
