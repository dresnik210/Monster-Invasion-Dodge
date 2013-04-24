#ifndef BOUNCER_H
#define BOUNCER_H

#include "monster.h"

class Bouncer : public Monster, public QGraphicsPixmapItem
{
  public:
  	Bouncer(int x, int y, QPixmap& pixmap);
  	void move();
  	int bounceCheck;
  private:

};

#endif
