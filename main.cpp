#include <QtGui/QApplication>
#include <iostream>
#include <cstdlib>
#include <deque>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
	//const int RESTART_CODE = -1;
	
	//do{ 
		QApplication app(argc, argv);
		MainWindow w;
		w.show();	
	//}while(app.exec() == RESTART_CODE);
	
    //return out_of_loop_code;
    return app.exec();
}
