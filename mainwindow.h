#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QPushButton>
#include <vector>
#include <QTextEdit>
#include <QLineEdit>
#include <QRadioButton>
#include <QListView>
#include <QString>
#include <QFormLayout>
#include <QBoxLayout>
#include <QGroupBox>
#include <QColor>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <QRectF>
#include <QPixmap>
#include <QKeyEvent>

#include "bomber.h"
#include "rocket.h"
#include "swerver.h"
#include "flyer.h"
#include "bouncer.h"
#include "userplayer.h"

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    
protected:
	void keyPressEvent(QKeyEvent *e);
    
private:
    QPushButton *start;
    QPushButton *pause;
    QPushButton *quit;
    QLineEdit *nameEntry;
    QLineEdit *name;
    QLineEdit *score;
    QFormLayout *nameRow;
    QFormLayout *nameDisplay;
    QFormLayout *scoreDisplay;
    QGraphicsScene *scene;
	QGraphicsView *view;
	QVBoxLayout *mainLayout;
	QHBoxLayout *buttonsRow;
	QHBoxLayout *nameScoreRow;
	QTimer *timer;
	int timerCount;
	int timerInterval;
	QPixmap* background;
	QPixmap* bomberPic;
	QPixmap* explosion;
	QPixmap* rocketPic;
	QPixmap* swerverPic;
	QPixmap* flyerPic;
	QPixmap* bouncerPic;
	QPixmap* userPic;
	UserPlayer* user;
	std::vector<Monster*> monsterList;
	int scoreCount;
	
public slots:
	void quitFunc();
	void startTimer();
	void stopTimer();
	void handleTimer();
	void spawnBomber();
	void spawnRocket();
	void spawnSwerver();
	void spawnFlyer();
	void spawnBouncer();
};

#endif // MAINWINDOW_H
