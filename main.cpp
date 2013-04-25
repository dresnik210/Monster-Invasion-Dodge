#include <QtGui/QApplication>
#include <iostream>
#include <cstdlib>
#include <deque>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow w;
	w.show();

    return app.exec();
}
