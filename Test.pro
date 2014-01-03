#-------------------------------------------------
#
# Project created by QtCreator 2014-01-03T18:28:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Question.cpp \
    QuestionWidget.cpp \
    Test.cpp \
    TestWidget.cpp

HEADERS  += MainWindow.h \
    Question.h \
    QuestionWidget.h \
    Test.h \
    TestWidget.h

FORMS    += MainWindow.ui \
    QuestionWidget.ui \
    TestWidget.ui
