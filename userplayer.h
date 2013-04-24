#ifndef USER_PLAYER_H
#define USER_PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class UserPlayer : public QGraphicsPixmapItem
{
  public:
  	UserPlayer(QPixmap& pixmap);
  	void moveLeft();
  	void moveRight();
  private:
	int xCoor;
	int yCoor;
	
};

#endif
