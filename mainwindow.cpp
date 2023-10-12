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

    ui->octavia->hide();
    ui->zr7->hide();
    ui->lcdNumber->hide();
    ui->horizontalSlider->hide();

    this->monCompteur = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnMoins_clicked()
{
    this->monCompteur--;
    ui->lblAffichage->setText(QString::number(this->monCompteur));
    ui->lblAffichage->adjustSize();
}


void MainWindow::on_btnPlus_clicked()
{
    this->monCompteur++;
    ui->lblAffichage->setText(QString::number(this->monCompteur));
    ui->lblAffichage->adjustSize();

}

void MainWindow::on_pushButton_clicked()
{
    this->monCompteur = 0;
    ui->lblAffichage->setText(QString::number(this->monCompteur));
    ui->lblAffichage->adjustSize();

}


void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_3_clicked()
{
ui->octavia->show();
ui->zr7->hide();
}


void MainWindow::on_pushButton_5_clicked()
{
ui->zr7->show();
ui->octavia->hide();
ui->lcdNumber->show();
ui->horizontalSlider->show();

}

void MainWindow::on_pushButton_4_clicked()
{
ui->octavia->hide();
ui->zr7->hide();
ui->lcdNumber->hide();
ui->horizontalSlider->hide();

}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
}

