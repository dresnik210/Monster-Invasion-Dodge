#ifndef ROCKET_H
#define ROCKET_H

#include "monster.h"

class Rocket : public Monster
{
  public:
  	Rocket(int x, int y, QPixmap& pixmap);
  	void move();
  private:

};

#endif
