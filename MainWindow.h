#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TestWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void updateTestView();

private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    TestWidget* testWidget;
};

#endif // MAINWINDOW_H
