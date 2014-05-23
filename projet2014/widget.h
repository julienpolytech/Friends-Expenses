#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <fstream>
#include <iostream>
#include <QTcpSocket>
#include "Group.hpp"

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

#define Dona "Donnateur"

using namespace std;


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
    void GroupNumber();
    int FriendsExpenses();
    void Automatic();
    void Manual();
    void Manu();
    void Clear();
    void SaveAs();
    void SendMails();
    void Aide();


private:
    Ui::Widget *ui;
    int numberOfGroup;
    int numberOfPersons;
    string GroupName;
    QString m_configurationFilePath;
    const char* c;
};

#endif // WIDGET_H
