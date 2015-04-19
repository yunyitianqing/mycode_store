#ifndef IMG_SHOW_H
#define IMG_SHOW_H
#include<QObject>
#include<QLabel>
#include"img_pro.h"
class MyShowWidget:QWidget
{
    Q_OBJECT
public:
    MyShowWidget(QWidget*parent=0,const char*name=0);
};

class MyFilter :QWidget
{
    Q_OBJECT
public:
    MyFilter(QWidget*parent=0,const char*name=0);
};


class MyMainWidget :QWidget
{
    Q_OBJECT
    MyFilter *filter;
public:

};



#endif // IMG_SHOW_H
