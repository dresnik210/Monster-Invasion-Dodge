#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Monster
{
  public:
	virtual ~Monster() { };
	virtual void move() = 0;
  
  protected:
  	int xCoor;
	int yCoor;
	int xVelocity;
	int yVelocity;
};

#endif
