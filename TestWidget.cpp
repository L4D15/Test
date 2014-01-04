#include "TestWidget.h"
#include "ui_TestWidget.h"
#include "QuestionWidget.h"

TestWidget::TestWidget(QString testFilePath, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget),
    test(testFilePath)
{
    ui->setupUi(this);

    // Add question widgets to the ui
    for (int index = 0; index < this->test.questions.size(); ++index)
    {
        this->questionWidgets.push_back(new QuestionWidget(this->test.questions[index], this));
        this->ui->mainLayout->addWidget(this->questionWidgets[index]);

        connect(this->questionWidgets[index], SIGNAL(solutionChanged()), this, SLOT(questionSolutionChanged()));
    }
}

TestWidget::~TestWidget()
{
    for (int index = 0; index < this->questionWidgets.size(); ++index)
    {
        delete this->questionWidgets[index];
    }

    this->questionWidgets.clear();

    delete ui;
}

QString TestWidget::getTestResults()
{
    unsigned int correctAnswers = 0;
    for (int index = 0; index < this->questionWidgets.size(); ++index)
    {
        if (this->questionWidgets[index]->isCorrect() == true)
        {
            ++correctAnswers;
        }
    }

    QString message;

    message.append(QString("%1 / %2 = %3"). arg(correctAnswers).
                                            arg(this->questionWidgets.size()).
                                            arg((static_cast<float>(correctAnswers) / static_cast<float>(this->questionWidgets.size()) * 10.0f), 0, 'g', 2));

    return message;
}

void TestWidget::questionSolutionChanged()
{
    emit testResultsMustBeUpdate();
}
