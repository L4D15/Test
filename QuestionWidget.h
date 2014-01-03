#ifndef QUESTIONWIDGET_H
#define QUESTIONWIDGET_H

#include <QWidget>
#include "Question.h"
#include <QRadioButton>
#include <QLabel>
#include <QButtonGroup>

namespace Ui {

typedef struct {
    QRadioButton* radioButton;
    QLabel* text;
} AnswerWidget;

class QuestionWidget;
}

class QuestionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionWidget(Question& question, QWidget *parent = 0);
    ~QuestionWidget();

private slots:
    void checkSolution();

private:
    Ui::QuestionWidget *ui;
    Question& question;
    QVector<Ui::AnswerWidget> answersWidgets;
    QButtonGroup* buttonGroup;
};

#endif // QUESTIONWIDGET_H
