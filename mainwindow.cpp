#include "mainwindow.h"

MainWindow::MainWindow()  {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
   
    /**This sets the size of the window and gives it a title. */
    view->setFixedSize(402,402);
    
    scene->setSceneRect(0,0,400,400);
    
    background = new QPixmap("sky.jpg");
    scene->addPixmap((background->scaled(400,400)));
    
    start = new QPushButton("Start");
    pause = new QPushButton("Pause");
    quit = new QPushButton("Quit");

    mainLayout = new QVBoxLayout;
    
    buttonsRow = new QHBoxLayout;
    buttonsRow->addWidget(start);
    buttonsRow->addWidget(pause);
    buttonsRow->addWidget(quit);
    
    /** Adds every row to overall display */
    mainLayout->addLayout(buttonsRow);
    mainLayout->addWidget(view);
    
    this->setLayout(mainLayout);
    
    timer = new QTimer(this);
    timerInterval = 100;
    timer->setInterval(timerInterval);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    timerCount = 0;
    
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(startTimer()));
    QObject::connect(pause,SIGNAL(clicked()),this,SLOT(stopTimer()));
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(quitFunc())); 
    
    bomberPic = new QPixmap("bomber.png"); 
    rocketPic = new QPixmap("rocket.png");
	swerverPic = new QPixmap("swerver.png");
	flyerPic = new QPixmap("flyer.png");
	bouncerPic = new QPixmap("bouncer.png");
	userPic = new QPixmap("userplayer.png");
	
	user = new UserPlayer(*userPic);
	scene->addItem(user);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
	switch(e->key())
	{
		case Qt::Key_Left:
			std::cout << "LEFT" << std::endl;
			user->moveLeft();
			break;
		case Qt::Key_Right:
			std::cout << "RIGHT" << std::endl;
			user->moveRight();
			break;
	}
}

void MainWindow::quitFunc()
{
	exit(EXIT_FAILURE);
}

void MainWindow::startTimer()
{
	timer->start();	
	setFocus();
}

void MainWindow::stopTimer()
{
	timer->stop();
}

void MainWindow::handleTimer() /** Function for tile animation */
{
    //std::cout << timerCount << std::endl;
    if(timerCount == 30)
    {
    	timerCount = 0;
    	timerInterval = timerInterval - 2;
    	timer->setInterval(timerInterval);
    }
    if(timerCount == 0)
    {
    	switch(3/*rand() % 5*/){
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
    	if(monsterList[i]->getYCoor() >= 450)
    	{
    		monsterList.erase(monsterList.begin()+i);
    	}
    }
    timerCount++;
    std::cout << "List size: " << monsterList.size() << std::endl;
}

void MainWindow::spawnBomber()
{
	int xVal = rand() % 380;
	Bomber* newBomber = new Bomber(xVal,0,*bomberPic);
	scene->addItem(newBomber);
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
	
