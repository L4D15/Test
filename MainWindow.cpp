#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>

#include "QuestionWidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filePath;

    filePath = QFileDialog::getOpenFileName(this,"Select the test file", NULL, "Test (*.json)");

    if (filePath.isEmpty() == false)
    {
        this->testWidget = new TestWidget(filePath, this);
        this->ui->mainLayout->addWidget(this->testWidget);
    }
}

void MainWindow::updateTestView()
{

}
