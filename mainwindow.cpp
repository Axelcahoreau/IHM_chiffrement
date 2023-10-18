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

    //---------------------------------------
    ui->SHA256label->hide();
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

    ui->SHA256label->hide();
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

    ui->SHA256label->hide();
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

    ui->SHA256label->hide();
}


//SHA256---------------------------------------------------------------------------------------------------------------------
void MainWindow::on_SHA256fichier_clicked()
{
    QStringList SelectFichierSHA256 = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    //std::cout << "Fichier selectionne " << typeid(SelectFichierSHA256.at(0).toLocal8Bit().constData())<<std::endl;

   ui->SHA256label->show();
   std::string SelectFichierSHA256s= SelectFichierSHA256.at(0).toStdString();
   std::cout << SelectFichierSHA256s << std::endl;
   HashGestion SHA;
   //QString SHA2 = SHA.CalculateFileSHA256(SelectFichierSHA256s);
   QString SHA2 = QString::fromStdString(SHA.CalculateFileSHA256(SelectFichierSHA256s));


   ui->SHA256label->setText(SHA2);
   ui->SHA256label->setTextInteractionFlags(Qt::TextSelectableByMouse);

    //a faire pour copier le hashage
    //#############################################################################################################################################################################################################
}




//AES----------------------------------------------------------------------------------------------------------------------
void MainWindow::on_AESchiffrer_clicked()
{
    QStringList SelectFichierAES = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierAES;


    this ->Aesfich = SelectFichierAES.at(0).toStdString();
    this -> AESCH = 1;
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

    this ->Aesfich = SelectFichierAES.at(0).toStdString();
    this -> AESCH = 0;
    ui->AESchargementclepv->show();
    ui->AESgenerer->show();

    ui->RSAchargementclepv->hide();
    ui->RSAchargementclepu->hide();
    ui->RSAgenerer->hide();

}

void MainWindow::on_AESchargementclepv_clicked()
{
    QStringList SelectFichierAESc = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierAESc;

    this ->Aesfichc = SelectFichierAESc.at(0).toStdString();
    monAes.LoadAESKeyFromFile(Aesfichc);

    switch(this -> AESCH){
    case 1:
        monAes.EncryptFileAES256(this ->Aesfich,"chiffre_Aes.txt");
        break;
    case 0:
        monAes.DecryptFileAES256(this ->Aesfich,"dechiffre_Aes.txt");
        break;
    }
}

void MainWindow::on_AESgenerer_clicked()
{
    monAes.GenerateAESKey();
    monAes.SaveAESKeyToFile("cle.Aes");
    switch(this -> AESCH){
    case 1:
        monAes.EncryptFileAES256(this ->Aesfich,"chiffre_Aes.txt");
        break;
    case 0:
        monAes.DecryptFileAES256(this ->Aesfich,"dechiffre_Aes.txt");
        break;
    }
}


//RSA----------------------------------------------------------------------------------------------------------------------
void MainWindow::on_RSAchiffrer_clicked()
{
    QStringList SelectFichierRSA = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSA;

    this ->Rsafich = SelectFichierRSA.at(0).toStdString();
    this -> RSACH = 1;

    ui->AESchargementclepv->hide();
    ui->AESgenerer->hide();

    ui->RSAchargementclepv->hide();
    ui->RSAchargementclepu->show();
    ui->RSAgenerer->show();
}

void MainWindow::on_RSAdechiffrer_clicked()
{
    QStringList SelectFichierRSA = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSA;

    this ->Rsafich = SelectFichierRSA.at(0).toStdString();
    this -> RSACH = 0;

    ui->AESchargementclepv->hide();
    ui->AESgenerer->hide();

    ui->RSAchargementclepv->show();
    ui->RSAchargementclepu->hide();
    ui->RSAgenerer->hide();
}

void MainWindow::on_RSAchargementclepv_clicked()
{
    QStringList SelectFichierRSAcpr = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSAcpr;

    this ->Rsafichcpr = SelectFichierRSAcpr.at(0).toStdString();

    monRsa.chargementClefsPrive(this ->Rsafichcpr);

    switch(this -> RSACH){
    case 1:
        monRsa.chiffrementFichier(this->Rsafich,"chiffre_Rsa.txt",1);
        break;
    case 0:
        monRsa.dechiffrementFichier(this->Rsafich,"dechiffre_Rsa.txt",1);
        break;
    }

//chargement priver + chiffre/dechiffre

}

void MainWindow::on_RSAchargementclepu_clicked()
{
    QStringList SelectFichierRSAcpu = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSAcpu;

    this ->Rsafichcpu = SelectFichierRSAcpu.at(0).toStdString();
    monRsa.chargementClefsPublic(this ->Rsafichcpu);

    switch(this -> RSACH){
    case 1:
        monRsa.chiffrementFichier(this->Rsafich,"chiffre_Rsa.txt",1);
        break;
    case 0:
        monRsa.dechiffrementFichier(this->Rsafich,"dechiffre_Rsa.txt",1);
        break;
    }
//chargement publique + chiffre/dechiffre
}

void MainWindow::on_RSAgenerer_clicked()
{
// generation cle + chiffre/dechiffre

    monRsa.generationClef("cle_public.Rsa","cle_priver.Rsa",1024);

    switch(this -> RSACH){
    case 1:
        monRsa.chiffrementFichier(this->Rsafich,"chiffre_Rsa.txt",1);
        break;
    case 0:
        monRsa.dechiffrementFichier(this->Rsafich,"dechiffre_Rsa.txt",1);
        break;
    }
}





