#include "mainwindow.h"

MainWindow::MainWindow()  {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
   
    /**This sets the size of the window and gives it a title. */
    view->setFixedSize(402,402);
    
    scene->setSceneRect(0,0,400,400);
    
    background = new QPixmap("sky.jpg");
    scene->addPixmap((background->scaled(400,400)));
    
    /** Creates the start, pause, and quit buttons */
    start = new QPushButton("Start");
    pause = new QPushButton("Pause");
    quit = new QPushButton("Quit");
    
    /** Adds the start, pause, and quit buttons to horizonal box */
    buttonsRow = new QHBoxLayout;
    buttonsRow->addWidget(start);
    buttonsRow->addWidget(pause);
    buttonsRow->addWidget(quit);
    
    /** Creates entry line for user name */
    nameEntry = new QLineEdit;
    
    /** Adds user name entry line to a QForm */
    nameRow = new QFormLayout;
    nameRow->addRow("Enter player name:", nameEntry);
    
    /** Creates name and score displays */
    name = new QLineEdit;
    score = new QLineEdit;
    score->setText("0");
    name->setReadOnly(true);
    score->setReadOnly(true);
    nameDisplay = new QFormLayout;
    nameDisplay->addRow("Player:", name);
    scoreDisplay = new QFormLayout;
	scoreDisplay->addRow("Score:", score);
	nameScoreRow = new QHBoxLayout;
	nameScoreRow->addLayout(nameDisplay);
	nameScoreRow->addLayout(scoreDisplay);
    
    
    /** Creates main vertical layout */
    mainLayout = new QVBoxLayout;
    
    /** Adds every row to vertical layout */
    mainLayout->addLayout(buttonsRow);
    mainLayout->addLayout(nameRow);
    mainLayout->addWidget(view);
    mainLayout->addLayout(nameScoreRow);
    
    endGameMessage = new QLineEdit;
    endGameMessage->setReadOnly(true);
    endGameMessage->setText("Game over! Want to play again?");
    endGameMessage->setFixedWidth(223);
    restart = new QPushButton("Restart");
    quit2 = new QPushButton("Quit");
    
    restartLayout = new QVBoxLayout;
    restartLayout->addWidget(endGameMessage);
    restartLayout->addWidget(restart);
    restartLayout->addWidget(quit2);
    restartBox = new QWidget;
    restartBox->setLayout(restartLayout);
    
    this->setLayout(mainLayout);
    
    timer = new QTimer(this);
    timerInterval = 100;
    timer->setInterval(timerInterval);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    timerCount = 0;
    
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(startTimer()));
    QObject::connect(pause,SIGNAL(clicked()),this,SLOT(stopTimer()));
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(quitFunc()));
    QObject::connect(quit2,SIGNAL(clicked()),this,SLOT(quitFunc())); 
    QObject::connect(restart,SIGNAL(clicked()),this,SLOT(restartGame()));
    
    bomberPic = new QPixmap("bomber.png");
    explosion = new QPixmap("explosion.png");
    rocketPic = new QPixmap("rocket.png");
	swerverPic = new QPixmap("swerver.png");
	flyerPic = new QPixmap("flyer.png");
	bouncerPic = new QPixmap("bouncer.png");
	userPic = new QPixmap("userplayer.png");
	
	user = new UserPlayer(*userPic);
	scene->addItem(user);
	
	scoreCount = 0;
}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
	if(timer->isActive())
	{
		switch(e->key())
		{
			case Qt::Key_Left:
				user->moveLeft();
				break;
			case Qt::Key_Right:
				user->moveRight();
				break;
		}
	}
}

void MainWindow::quitFunc()
{
	exit(EXIT_FAILURE);
}

void MainWindow::startTimer()
{
	QString nameString;
	nameString = nameEntry->text();
	name->setText(nameString);
	timer->start();	
	setFocus();
}

void MainWindow::stopTimer()
{
	timer->stop();
}

void MainWindow::handleTimer() /** Function for tile animation */
{
    if(timerCount == 30)
    {
    	timerCount = 0;
    	timerInterval = timerInterval - 2;
    	timer->setInterval(timerInterval);
    }
    if(timerCount == 0)
    {
    	switch(rand() % 5){
		case 0:
			spawnBomber();
			break;
		case 1:
			spawnRocket();
			break;
		case 2:
			spawnSwerver();
			break;
		case 3:
			spawnFlyer();
			break;
		case 4:
			spawnBouncer();
			break;
		}
    }
    for(unsigned int i=0;i<monsterList.size();i++)
    {
    	monsterList[i]->move();
    	if(monsterList[i]->collidesWithItem(user))
    	{
    		stopTimer();
    		restartBox->show();
    	}
    	if(monsterList[i]->getYCoor() > 400)
    	{
    		scoreCount++;
    		QString scoreString;
    		scoreString = QString::number(scoreCount);
    		score->setText(scoreString);
    		monsterList.erase(monsterList.begin()+i);	
    	}
    }
    timerCount++;
}

void MainWindow::spawnBomber()
{
	int xVal = rand() % 380;
	Bomber* newBomber = new Bomber(xVal,0,*bomberPic,*explosion);
	scene->addItem(newBomber);
	scene->addItem(newBomber->explosion);
	monsterList.push_back(newBomber);
}

void MainWindow::spawnRocket()
{
	int xVal = rand() % 380;
	Rocket* newRocket = new Rocket(xVal,0,*rocketPic);
	scene->addItem(newRocket);
	monsterList.push_back(newRocket);
}

void MainWindow::spawnSwerver()
{
	int xVal = rand() % 349+5;
	Swerver* newSwerver = new Swerver(xVal,0,*swerverPic);
	scene->addItem(newSwerver);
	monsterList.push_back(newSwerver);
}

void MainWindow::spawnFlyer()
{
	int xVal = rand() % 380;
	Flyer* newFlyer = new Flyer(xVal,0,*flyerPic);
	scene->addItem(newFlyer);
	monsterList.push_back(newFlyer);
}

void MainWindow::spawnBouncer()
{
	int xVal = rand() % 380;
	Bouncer* newBouncer = new Bouncer(xVal,0,*bouncerPic);
	scene->addItem(newBouncer);
	monsterList.push_back(newBouncer);
}

void MainWindow::restartGame()
{
	exit(EXIT_CODE_REBOOT);
}

