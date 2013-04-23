#include "mainwindow.h"

MainWindow::MainWindow()  {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
   
    /**This sets the size of the window and gives it a title. */
    view->setFixedSize( 500, 500 );
    view->setWindowTitle( "Graphical 8-Tile Puzzle");
    
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
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    timerCount = 0;
    
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(spawnBomber()));
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(quitFunc())); 
    
    bomberPic = new QPixmap("bomber.jpg"); 
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

void MainWindow::handleTimer() /** Function for tile animation */
{
    timerCount++;
    if(timerCount == 3)
    {
    	timer->stop();	
    }
}

void MainWindow::spawnBomber()
{
	Bomber* newBomber = new Bomber(0,0,*bomberPic);
	scene->addItem(newBomber);
}


