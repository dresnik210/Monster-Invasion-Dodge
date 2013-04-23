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

#include "bomber.h"
#include "rocket.h"
#include "swerver.h"
#include "flyer.h"
#include "bouncer.h"

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    
private:
    QPushButton *start;
    QPushButton *pause;
    QPushButton *quit;
    QGraphicsScene *scene;
	QGraphicsView *view;
	QVBoxLayout *mainLayout;
	QHBoxLayout *buttonsRow;
	QTimer *timer;
	int timerCount;
	QPixmap* bomberPic;
	QPixmap* rocketPic;
	QPixmap* swerverPic;
	QPixmap* flyerPic;
	QPixmap* bouncerPic;
	
public slots:
	void quitFunc();
	void handleTimer();
	void spawnBomber();
	void spawnRocket();
	void spawnSwerver();
	void spawnFlyer();
	void spawnBouncer();
};

#endif // MAINWINDOW_H
