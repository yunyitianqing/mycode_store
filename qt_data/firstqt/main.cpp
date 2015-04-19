
#include"main.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainWindow mywindow();


    return a.exec();
}


MainWindow::MainWindow():QObject()
{
    button=new QPushButton(this);

}

MainWindow::~MainWindow()
{
    delete button;
}
