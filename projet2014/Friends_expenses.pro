#-------------------------------------------------
#
# Project created by QtCreator 2014-04-11T08:32:36
#
#-------------------------------------------------

QT       += core gui\
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Friends_expenses
TEMPLATE = app


SOURCES += main.cpp\
    Person.cpp \
    Group.cpp \
    Friends-expenses.cpp \
    email.cpp

HEADERS  += widget.h \
    Person.hpp \
    Group.hpp \
    email.hpp

FORMS    += widget.ui
