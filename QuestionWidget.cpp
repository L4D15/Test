#include "QuestionWidget.h"
#include "ui_QuestionWidget.h"

QuestionWidget::QuestionWidget(Question &question, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionWidget),
    question(question)
{
    ui->setupUi(this);

    // Setup UI elements with question data
    this->buttonGroup = new QButtonGroup(this);

    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(checkSolution(int)));

    this->ui->descriptionLabel->setText(QString(this->question.description.c_str()));

    // Create answer widgets
    for (unsigned int i = 0; i < this->question.options.size(); ++i)
    {
        Ui::AnswerWidget widget;

        widget.radioButton = new QRadioButton(this);
        widget.text = new QLabel(QString(this->question.options[i].c_str()), this);

        this->answersWidgets.push_back(widget);

        this->ui->answersLayout->addRow(this->answersWidgets[i].radioButton, widget.text);
        this->buttonGroup->addButton(this->answersWidgets[i].radioButton);
    }
}

QuestionWidget::~QuestionWidget()
{
    delete ui;
}

void QuestionWidget::checkSolution(int buttonId)
{
    // If the button clicked is the same as the solution
    if (this->buttonGroup->button(buttonId) == this->answersWidgets[this->question.solution - 1].radioButton)
    {
        this->ui->solutionLabel->setText("<span style='color:#00b7a4'>Correct!</span>");
    }
    else
    {
        this->ui->solutionLabel->setText("<span style='color:#ff0000'>Incorrect!</span>");
    }
}
