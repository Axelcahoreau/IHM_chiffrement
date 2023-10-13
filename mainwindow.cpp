#include "mainwindow.h"
#include "ui_mainwindow.h"


/**
 * @brief MainWindow::MainWindow Constructeur de la classe
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Exit_clicked()
{
    this->close();
}

