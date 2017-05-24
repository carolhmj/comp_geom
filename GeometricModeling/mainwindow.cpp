#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_actionSave_triggered()
{
    ui->widget->saveArchive();
}

void MainWindow::on_actionOpen_triggered()
{
    ui->widget->openArchive();
}

void MainWindow::on_generateHull_clicked()
{
    ui->widget->generateHulls();
}
