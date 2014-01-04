#include "QuestionWidget.h"
#include "ui_QuestionWidget.h"

// --- Static variables ---
QString QuestionWidget::correctStyle("QLabel#solutionLabel {"
                                     "border: 1px solid #ccc;"
                                     "border-radius: 5px;"
                                     "background-color: #008500;"
                                     "color: #fff;"
                                     "padding: 3px;"
                                 "}");
QString QuestionWidget::incorrectStyle("QLabel#solutionLabel {"
                                       "border: 1px solid #ccc;"
                                       "border-radius: 5px;"
                                       "background-color: #a60800;"
                                       "color: #fff;"
                                       "padding: 3px;"
                                   "}");
// ---

QuestionWidget::QuestionWidget(Question &question, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionWidget),
    question(question)
{
    ui->setupUi(this);

    // Solution check box is hiden at first
    this->ui->solutionLabel->hide();

    this->correct = false;

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
        widget.text->setWordWrap(true);
        widget.text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

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
        this->ui->solutionLabel->setStyleSheet(correctStyle);
        this->ui->solutionLabel->setText("Correct");
        this->correct = true;
    }
    else
    {
        this->ui->solutionLabel->setStyleSheet(incorrectStyle);
        this->ui->solutionLabel->setText("Incorrect");
        this->correct = false;
    }

    this->ui->solutionLabel->show();

    emit solutionChanged();
}
