#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "Test.h"

namespace Ui {
class TestWidget;
}

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestWidget(QString testFilePath, QWidget *parent = 0);
    ~TestWidget();

private:
    Ui::TestWidget *ui;
    Test test;
};

#endif // TESTWIDGET_H
