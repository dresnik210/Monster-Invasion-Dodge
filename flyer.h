#ifndef FLYER_H
#define FLYER_H

#include "monster.h"

class Flyer : public Monster
{
  public:
  	Flyer(int x, int y, QPixmap& pixmap);
  	void move();
  	void setPlayerXCoor(int x);
  private:

};

#endif
