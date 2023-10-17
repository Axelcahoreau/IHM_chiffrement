#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

/**
 * @brief MainWindow::MainWindow Constructeur de la classe
 * @param parent
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MODESHA256->hide();
    ui->MODERSA->hide();
    ui->MODEAES->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Exit_clicked()
{
    this->close();
}


void MainWindow::on_SHA256_clicked()
{
    ui->MODESHA256->show();
    ui->MODERSA->hide();
    ui->MODEAES->hide();
    ui->RSAParcourir->hide();
    ui->SHA256Parcourir->show();
    ui->AESParcourir->hide();
}


void MainWindow::on_RSA_clicked()
{
    ui->MODESHA256->hide();
    ui->MODERSA->show();
    ui->MODEAES->hide();
    ui->RSAParcourir->show();
    ui->SHA256Parcourir->hide();
    ui->AESParcourir->hide();
}


void MainWindow::on_AES_clicked()
{
    ui->MODESHA256->hide();
    ui->MODERSA->hide();
    ui->MODEAES->show();
    ui->RSAParcourir->hide();
    ui->SHA256Parcourir->hide();
    ui->AESParcourir->show();
}

void MainWindow::on_RSAParcourir_clicked()
{
    QStringList SelectFichier = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    for (int i=0; i<SelectFichier.length(); i++)
    {
        qDebug() << "Fichier selectionné " << SelectFichier.at(i);
    }
}


void MainWindow::on_SHA256Parcourir_clicked()
{
    QStringList SelectFichier = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    for (int i=0; i<SelectFichier.length(); i++)
    {
        qDebug() << "Fichier selectionné " << SelectFichier.at(i);
    }
}


void MainWindow::on_RSAParcourir_2_clicked()
{
    QStringList SelectFichier = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    for (int i=0; i<SelectFichier.length(); i++)
    {
        qDebug() << "Fichier selectionné " << SelectFichier.at(i);
    }
}

