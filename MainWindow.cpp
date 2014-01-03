#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "QuestionWidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Test
    std::vector<std::string> options;

    options.push_back("Sí");
    options.push_back("No");

    Question* question;

    question = new Question("¿Esto se ve?", options, 1);
    QuestionWidget* widget;

    widget = new QuestionWidget(*question, this);

    this->ui->mainLayout->addWidget(widget);
    // ---
}

MainWindow::~MainWindow()
{
    delete ui;
}
