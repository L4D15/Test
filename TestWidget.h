#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "Test.h"
#include "QuestionWidget.h"

namespace Ui {
class TestWidget;
}

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestWidget(QString testFilePath, QWidget *parent = 0);
    ~TestWidget();

    QString getTestResults();

private slots:
    void questionSolutionChanged();

signals:
    void testResultsMustBeUpdate();

private:
    Ui::TestWidget *ui;
    Test test;
    QVector<QuestionWidget*> questionWidgets;
};

#endif // TESTWIDGET_H
