#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


#include <QTcpSocket>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <cstdlib>
#include <iomanip>
#include <QPushButton>
#include <QFile>
#include <QList>
#include <QString>
#include <QRadioButton>

#include <QFileDialog>



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void Browse();
    int FriendsExpenses();
    void Automatic();
    void Manual();
    void Clear();

private:
    Ui::Widget *ui;
    QString m_configurationFilePath;
    const char* c;

};

#endif // WIDGET_H
