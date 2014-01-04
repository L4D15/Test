#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>

#include "QuestionWidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add a QLabel to the status bar so we can display the test results there
    this->statusBarText = new QLabel(this->statusBar());

    QString style = "QLabel{ font-size: xx-small; }";
    this->statusBarText->setStyleSheet(style);
    this->statusBarText->setIndent(Qt::AlignRight);

    this->ui->statusBar->addPermanentWidget(this->statusBarText);
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
        // Check if another test is already showing
        if (this->testWidget != NULL)
        {
            disconnect(this->testWidget, SIGNAL(testResultsMustBeUpdate()), this, SLOT(updateTestView()));
            delete this->testWidget;
        }

        // Remove widgets
        //this->ui->mainLayout->removeWidget(this->ui->subtitleLabel);
        //this->ui->subtitleLabel->hide();

        this->testWidget = new TestWidget(filePath, this);
        this->ui->mainLayout->addWidget(this->testWidget);
        connect(this->testWidget, SIGNAL(testResultsMustBeUpdate()), this, SLOT(updateTestView()));

        // Make the first update
        updateTestView();
    }
}

void MainWindow::updateTestView()
{
    QString newStatusText;

    newStatusText = this->testWidget->getTestResults();

    this->statusBarText->setText(newStatusText);
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}
