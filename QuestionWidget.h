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

private:
    static QString correctStyle;
    static QString incorrectStyle;

public:
    explicit QuestionWidget(Question& question, QWidget *parent = 0);
    ~QuestionWidget();

    inline bool isCorrect() { return correct; }

private slots:
    void checkSolution(int buttonId);

signals:
    void solutionChanged();

private:
    Ui::QuestionWidget *ui;
    Question& question;
    QVector<Ui::AnswerWidget> answersWidgets;
    QButtonGroup* buttonGroup;
    bool correct;
};

#endif // QUESTIONWIDGET_H
