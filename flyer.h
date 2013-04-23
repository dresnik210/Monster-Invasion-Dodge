#ifndef FLYER_H
#define FLYER_H

#include "monster.h"

class Flyer : public Monster, public QGraphicsPixmapItem
{
  public:
  	Flyer(int x, int y, QPixmap& pixmap);
  	void move();
  private:

};

#endif
