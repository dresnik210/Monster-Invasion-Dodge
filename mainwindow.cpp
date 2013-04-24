#include "mainwindow.h"

MainWindow::MainWindow()  {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
   
    /**This sets the size of the window and gives it a title. */
    view->setFixedSize(402,402);
    
    scene->setSceneRect(0,0,400,400);
    
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
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    timerCount = 0;
    
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(startTimer()));
    QObject::connect(pause,SIGNAL(clicked()),this,SLOT(stopTimer()));
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(quitFunc())); 
    
    bomberPic = new QPixmap("bomber.jpg"); 
    rocketPic = new QPixmap("rocket.png");
	swerverPic = new QPixmap("swerver.jpg");
	flyerPic = new QPixmap("flyer.png");
	bouncerPic = new QPixmap("bouncer.jpg");
}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
}

void MainWindow::quitFunc()
{
	exit(EXIT_FAILURE);
}

void MainWindow::startTimer()
{
	timer->start();	
}

void MainWindow::stopTimer()
{
	timer->stop();
}

void MainWindow::handleTimer() /** Function for tile animation */
{
    //std::cout << timerCount << std::endl;
    if(timerCount == 50)
    {
    	timerCount = 0;
    }
    if(timerCount == 0)
    {
    	spawnBomber();
    }
    if(timerCount == 10)
    {
    	spawnRocket();
    }
    if(timerCount == 20)
    {
    	spawnSwerver();
    }
    if(timerCount == 30)
    {
    	spawnFlyer();
    }
    if(timerCount == 40)
    {
    	spawnBouncer();
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
	int xVal = rand() % 380;
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
	
