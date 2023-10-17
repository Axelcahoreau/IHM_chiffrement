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

//--------------------------------------
    ui->SHA256fichier->hide();

    ui->AESchiffrer->hide();
    ui->AESdechiffrer->hide();

    ui->RSAchiffrer->hide();
    ui->RSAdechiffrer->hide();

//--------------------------------------

    ui->AESchargementclepv->hide();
    ui->AESgenerer->hide();

    ui->RSAchargementclepv->hide();
    ui->RSAchargementclepu->hide();
    ui->RSAgenerer->hide();
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

    ui->SHA256fichier->show();

    ui->AESchiffrer->hide();
    ui->AESdechiffrer->hide();

    ui->RSAchiffrer->hide();
    ui->RSAdechiffrer->hide();


    ui->AESchargementclepv->hide();
    ui->AESgenerer->hide();

    ui->RSAchargementclepv->hide();
    ui->RSAchargementclepu->hide();
    ui->RSAgenerer->hide();
}


void MainWindow::on_RSA_clicked()
{
    ui->MODESHA256->hide();
    ui->MODERSA->show();
    ui->MODEAES->hide();

    ui->SHA256fichier->hide();

    ui->AESchiffrer->hide();
    ui->AESdechiffrer->hide();

    ui->RSAchiffrer->show();
    ui->RSAdechiffrer->show();


    ui->AESchargementclepv->hide();
    ui->AESgenerer->hide();

    ui->RSAchargementclepv->hide();
    ui->RSAchargementclepu->hide();
    ui->RSAgenerer->hide();
}


void MainWindow::on_AES_clicked()
{
    ui->MODESHA256->hide();
    ui->MODERSA->hide();
    ui->MODEAES->show();

    ui->SHA256fichier->hide();

    ui->AESchiffrer->show();
    ui->AESdechiffrer->show();

    ui->RSAchiffrer->hide();
    ui->RSAdechiffrer->hide();


    ui->AESchargementclepv->hide();
    ui->AESgenerer->hide();

    ui->RSAchargementclepv->hide();
    ui->RSAchargementclepu->hide();
    ui->RSAgenerer->hide();
}


//SHA256---------------------------------------------------------------------------------------------------------------------
void MainWindow::on_SHA256fichier_clicked()
{
    QStringList SelectFichierSHA256 = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierSHA256;
}




//AES----------------------------------------------------------------------------------------------------------------------
void MainWindow::on_AESchiffrer_clicked()
{
    QStringList SelectFichierAES = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierAES;

    ui->AESchargementclepv->show();
    ui->AESgenerer->show();

    ui->RSAchargementclepv->hide();
    ui->RSAchargementclepu->hide();
    ui->RSAgenerer->hide();
}


void MainWindow::on_AESdechiffrer_clicked()
{
    QStringList SelectFichierAES = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierAES;


    ui->AESchargementclepv->show();
    ui->AESgenerer->show();

    ui->RSAchargementclepv->hide();
    ui->RSAchargementclepu->hide();
    ui->RSAgenerer->hide();
}

void MainWindow::on_AESchargementclepv_clicked()
{

}

void MainWindow::on_AESgenerer_clicked()
{

}


//RSA----------------------------------------------------------------------------------------------------------------------
void MainWindow::on_RSAchiffrer_clicked()
{
    QStringList SelectFichierRSA = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSA;


    ui->AESchargementclepv->hide();
    ui->AESgenerer->hide();

    ui->RSAchargementclepv->show();
    ui->RSAchargementclepu->show();
    ui->RSAgenerer->show();
}

void MainWindow::on_RSAdechiffrer_clicked()
{
    QStringList SelectFichierRSA = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSA;


    ui->AESchargementclepv->hide();
    ui->AESgenerer->hide();

    ui->RSAchargementclepv->show();
    ui->RSAchargementclepu->show();
    ui->RSAgenerer->show();
}

void MainWindow::on_RSAchargementclepv_clicked()
{

}

void MainWindow::on_RSAchargementclepu_clicked()
{

}

void MainWindow::on_RSAgenerer_clicked()
{

}






