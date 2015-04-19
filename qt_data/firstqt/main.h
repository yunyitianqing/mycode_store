#ifndef MAIN_H
#define MAIN_H
#include <QtCore/QCoreApplication>
#include <QtGui/QPushButton>
class MainWindow : public QObject
{
    Q_OBJECT
	public:
    QPushButton *button;
    MainWindow();
    ~MainWindow();

};


#endif // MAIN_H
