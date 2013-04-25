#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <stdlib.h>

class Monster : public QGraphicsPixmapItem
{
  public:
  	Monster(QPixmap& pixmap);
	virtual ~Monster();
	virtual void move() = 0;
	virtual int getYCoor() { return yCoor; };
  
  protected:
  	int xCoor;
	int yCoor;
	int xVelocity;
	int yVelocity;
};

#endif
