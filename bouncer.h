#ifndef BOUNCER_H
#define BOUNCER_H

#include "monster.h"

class Bouncer : public Monster
{
  public:
  	Bouncer(int x, int y, QPixmap& pixmap);
  	void move();
  	void setPlayerXCoor(int x);
  	int bounceCheck;
  private:

};

#endif
