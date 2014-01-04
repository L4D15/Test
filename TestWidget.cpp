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
