#ifndef SWERVER_H
#define SWERVER_H

#include "monster.h"

class Swerver : public Monster
{
  public:
  	Swerver(int x, int y, QPixmap& pixmap);
  	void move();
  private:

};

#endif
