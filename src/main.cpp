#include <QApplication>
#include <QDebug>
#include <QWidget>
#include "mainWindow.hpp"
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	MainWindow wndw;
//	QWidget wndw;
	wndw.setObjectName("IP Camera Control Utility");
	qDebug() << "name is set\n";
	wndw.show();
	return app.exec();
}
