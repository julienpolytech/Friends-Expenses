/*
 * main.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Salim
 */


#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
