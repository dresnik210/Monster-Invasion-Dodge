#include "mainwindow.h"

MainWindow::MainWindow()  {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
   
    /**This sets the size of the window and gives it a title. */
    view->setFixedSize(402,402);
    
    scene->setSceneRect(0,0,400,400);
    
    background = new QPixmap("sky.jpg");
    scene->addPixmap((background->scaled(400,400)));
    
    /** Creates the start and pause buttons */
    start = new QPushButton("Start");
    pause = new QPushButton("Pause");
    
    /** Adds the start and pause buttons to horizontal box */
    buttonsRow = new QHBoxLayout;
    buttonsRow->addWidget(start);
    buttonsRow->addWidget(pause);
    
    /** Creates the quit and instructions buttons */
    quit = new QPushButton("Quit");
    instructions = new QPushButton("Instructions");
    
    /** Adds the quit and instructions buttons to horizontal box */
    buttonsRow2 = new QHBoxLayout;
    buttonsRow2->addWidget(quit);
    buttonsRow2->addWidget(instructions);
    
    /** Creates entry line for user name */
    nameEntry = new QLineEdit;
    
    /** Adds user name entry line to a QForm */
    nameRow = new QFormLayout;
    nameRow->addRow("Enter player's first name:", nameEntry);
    
    /** Creates name and score displays */
    name = new QLineEdit;
    score = new QLineEdit;
    lives = new QLineEdit;
    score->setText("0");
    lives->setText("1");
    name->setReadOnly(true);
    score->setReadOnly(true);
    lives->setReadOnly(true);
    score->setFixedWidth(40);
    lives->setFixedWidth(20);
    nameDisplay = new QFormLayout;
    nameDisplay->addRow("Player:", name);
    scoreDisplay = new QFormLayout;
	scoreDisplay->addRow("Score:", score);
	livesDisplay = new QFormLayout;
	livesDisplay->addRow("Lives:", lives);
	nameScoreRow = new QHBoxLayout;
	nameScoreRow->addLayout(nameDisplay);
	nameScoreRow->addLayout(scoreDisplay);
	nameScoreRow->addLayout(livesDisplay);
    
    
    /** Creates main vertical layout */
    mainLayout = new QVBoxLayout;
    
    /** Adds every row to vertical layout */
    mainLayout->addLayout(buttonsRow);
    mainLayout->addLayout(buttonsRow2);
    mainLayout->addLayout(nameRow);
    mainLayout->addWidget(view);
    mainLayout->addLayout(nameScoreRow);
    
    /** Creates elements for restart box */
    endGameMessage = new QLineEdit;
    endGameMessage->setReadOnly(true);
    endGameMessage->setText("Game over! Want to play again?");
    endGameMessage->setFixedWidth(222);
    restart = new QPushButton("Restart");
    quit2 = new QPushButton("Quit");
    highScores = new QPushButton("View High Scores");
    
    /** Creates instructions box */
    instructionsBox = new QTextEdit;
    instructionsBox->setReadOnly(true);
    instructionsBox->setText("Move the super hero left or right using the arrow keys to dodge the monsters. You only have one life so make it count!");
    
    /**Creates high scores box */
    highScoresBox = new QTextEdit;
    highScoresBox->setReadOnly(true);
    
    /** Creates restart box */
    restartLayout = new QVBoxLayout;
    restartLayout->addWidget(endGameMessage);
    restartLayout->addWidget(restart);
    restartLayout->addWidget(quit2);
    restartLayout->addWidget(highScores);
    restartBox = new QWidget;
    restartBox->setLayout(restartLayout);
    
    this->setLayout(mainLayout);
    
    /** Creates timer */
    timer = new QTimer(this);
    timerInterval = 100;
    timer->setInterval(timerInterval);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    timerCount = 0;
    
    /** Connects all buttons to slots */
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(startTimer()));
    QObject::connect(pause,SIGNAL(clicked()),this,SLOT(stopTimer()));
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(quitFunc()));
    QObject::connect(quit2,SIGNAL(clicked()),this,SLOT(quitFunc())); 
    QObject::connect(restart,SIGNAL(clicked()),this,SLOT(restartGame()));
    QObject::connect(instructions,SIGNAL(clicked()),this,SLOT(showInstructions()));
    QObject::connect(highScores,SIGNAL(clicked()),this,SLOT(showHighScores()));
    
    /** Creates pixmaps for all photos */
    bomberPic = new QPixmap("bomber.png");
    explosion = new QPixmap("explosion.png");
    rocketPic = new QPixmap("rocket.png");
	swerverPic = new QPixmap("swerver.png");
	flyerPic = new QPixmap("flyer.png");
	bouncerPic = new QPixmap("bouncer.png");
	userPic = new QPixmap("userplayer.png");
	
	/** Creates user player */
	user = new UserPlayer(*userPic);
	scene->addItem(user);
	
	scoreCount = 0;
	livesCount = 1;
	
	/** Reads in high scores */
	std::ifstream fin("highscores.txt");
	if (fin.is_open())
	{
		while(!fin.eof())
		{
			std::stringstream ss;
			std::stringstream convert;
			std::string name;
			std::string num;
			int numResult;
			getline(fin,name,' ');
			getline(fin,num);
			name.append(" ");
			name.append(num);
			convert << num; 
			convert >> numResult;
			highScorePair* newHighScore = new highScorePair;
			newHighScore->fullLine = name;
			newHighScore->score = numResult;
			highScoresList.push_back(newHighScore);
		}
	}
	fin.close();
	
	if(highScoresList.size() > 1)
	{
		highScoresList.pop_back();
		selectSort();
	}
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
	selectSort();
	std::ofstream output("highscores.txt",std::ofstream::out);
	for(unsigned int i=0;i<highScoresList.size();i++)
	{
		output << highScoresList[i]->fullLine << std::endl;
	}
	
	output.close();
	
	exit(EXIT_FAILURE);
}

void MainWindow::startTimer()
{
	QString nameString;
	nameString = nameEntry->text();
	if(nameString == "")
	{
		nameString = "Unknown";
	}
	name->setText(nameString);
	timer->start();	
	setFocus();
}

void MainWindow::stopTimer()
{
	timer->stop();
}

/** Sets what timer does at certain intervals */
void MainWindow::handleTimer()
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
  			livesCount--;
  			lives->setText("0");
    		stopTimer();
    		
    		QString nameString;
			QString scoreString;
			std::string temp;
			nameString = name->text();
			scoreString = score->text();
			temp = nameString.toStdString();
			temp.append(" ");
			temp.append(scoreString.toStdString());
			highScorePair* newHighScore = new highScorePair;
			newHighScore->fullLine = temp;
			temp = scoreString.toStdString();
			std::stringstream convert;
			int numResult;
			convert << temp;
			convert >> numResult;
			newHighScore->score = numResult;
			highScoresList.push_back(newHighScore);
			
    		restartBox->show();
    	}
    	if(monsterList[i]->getYCoor() > 400)
    	{
    		scoreCount++;
    		QString scoreString;
    		scoreString = QString::number(scoreCount);
    		score->setText(scoreString);
    		scene->removeItem(monsterList[i]);
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

/** Resets game for new play session */
void MainWindow::restartGame()
{
	restartBox->hide();
	for(unsigned int i=0;i<monsterList.size();i++)
    {
    	monsterList[i]->setPos(0,401);
    } 
	monsterList.clear();
	timerInterval = 100;
	timerCount = 0;
	user->resetPos();
	nameEntry->setText("");
	name->setText("");
	scoreCount = 0;
    score->setText("0");
    livesCount = 1;
    lives->setText("1");
}

void MainWindow::showInstructions()
{
	instructionsBox->show();
}

void MainWindow::showHighScores()
{	
	highScoresBox->setText("");

	if(highScoresList.size() > 1)
	{
		selectSort();
	}
	
	highScoresBox->append("High Scores");
	highScoresBox->append("");
	
	for(unsigned int i=0;i<highScoresList.size();i++)
	{	
		QString qScore = QString::fromStdString(highScoresList[i]->fullLine);
		highScoresBox->append(qScore);
	}

	highScoresBox->show();
}

void MainWindow::selectSort()
{
	for(unsigned int i=0;i<highScoresList.size()-1;i++)
	{
		int max = i;
		for(unsigned int j=i+1;j<highScoresList.size();j++)
		{
			if((highScoresList[j]->score)>(highScoresList[max]->score))
			{
				max = j;
			}
		}
		std::swap(highScoresList[i],highScoresList[max]);
	}
}

