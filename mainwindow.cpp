#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <cstdint>
#include <filesystem>
#include <fstream>


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


    /*
     * if qui verifie si bien un seul fichier est selectionner ( pas moin ni plus)
     */
    if(SelectFichierSHA256.length() == 1){

        ui->SHA256label->show();

        std::string SelectFichierSHA256s= SelectFichierSHA256.at(0).toStdString();// transforme SelectFichierSHA256 qui est en qstringlist en string
        std::cout << SelectFichierSHA256s << std::endl;

        HashGestion SHA;

        QString SHA2 = QString::fromStdString(SHA.CalculateFileSHA256(SelectFichierSHA256s));// transforme le resultat de "SHA.CalculateFileSHA256(SelectFichierSHA256s)" qui est en string en Qstring


        /*
        * change le text du label "SHA256label" et fait en sorte qu'il soit selectionnable et copiable
        */
        ui->SHA256label->setText(SHA2);
        ui->SHA256label->setTextInteractionFlags(Qt::TextSelectableByMouse);

    }else{
        std::cout << "erreur" << std::endl;
    }

}




//AES----------------------------------------------------------------------------------------------------------------------
void MainWindow::on_AESchiffrer_clicked()
{
    QStringList SelectFichierAES = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierAES;



    /*
     * if qui verifie si bien un seul fichier est selectionner ( pas moin ni plus)
     */
    if(SelectFichierAES.length() == 1){

        this ->Aesfich = SelectFichierAES.at(0).toStdString();// transforme SelectFichierAES qui est en qstringlist en string

        this -> AESCH = 1;//varaible bool qui dit si l'utilisateur veut chiffrer ou dechiffrer
        ui->AESchargementclepv->show();
        ui->AESgenerer->show();

        ui->RSAchargementclepv->hide();
        ui->RSAchargementclepu->hide();
        ui->RSAgenerer->hide();

    }else{
        std::cout << "erreur" << std::endl;
    }
}



void MainWindow::on_AESdechiffrer_clicked()
{
    QStringList SelectFichierAES = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierAES;



    /*
     * if qui verifie si bien un seul fichier est selectionner ( pas moin ni plus)
     */
    if(SelectFichierAES.length() == 1){
        this ->Aesfich = SelectFichierAES.at(0).toStdString();// transforme SelectFichierAES qui est en qstringlist en string
        this -> AESCH = 0;//varaible bool qui dit si l'utilisateur veut chiffrer ou dechiffrer
        ui->AESchargementclepv->show();
        ui->AESgenerer->show();

        ui->RSAchargementclepv->hide();
        ui->RSAchargementclepu->hide();
        ui->RSAgenerer->hide();

    }else{
    std::cout << "erreur" << std::endl;
    }
}

void MainWindow::on_AESchargementclepv_clicked()
{
    QStringList SelectFichierAESc = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierAESc;


    /*
     * if qui verifie si bien un seul fichier est selectionner ( pas moin ni plus)
     */
    if(SelectFichierAESc.length() == 1){
        this ->Aesfichc = SelectFichierAESc.at(0).toStdString();// transforme SelectFichierAESc qui est en qstringlist en string
        monAes.LoadAESKeyFromFile(Aesfichc);

        /*
         * switch pour savoir si l'on veut chiffrer ou dechiffrer
         */
        switch(this -> AESCH){
        case 1:
            monAes.EncryptFileAES256(this ->Aesfich,"chiffre_Aes.txt");
            break;
        case 0:
            monAes.DecryptFileAES256(this ->Aesfich,"dechiffre_Aes.txt");
            break;
        }

    }else{
    std::cout << "erreur" << std::endl;
    }
}

void MainWindow::on_AESgenerer_clicked()
{
    monAes.GenerateAESKey();
    monAes.SaveAESKeyToFile("cle.Aes");

    /*
     * switch pour savoir si l'on veut chiffrer ou dechiffrer
     */
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

    /*
     * if qui verifie si bien un seul fichier est selectionner ( pas moin ni plus)
     */
    if(SelectFichierRSA.length() == 1){
        this ->Rsafich = SelectFichierRSA.at(0).toStdString();// transforme SelectFichierRSA qui est en qstringlist en string
        this -> RSACH = 1;//varaible bool qui dit si l'utilisateur veut chiffrer ou dechiffrer

        ui->AESchargementclepv->hide();
        ui->AESgenerer->hide();

        ui->RSAchargementclepv->hide();
        ui->RSAchargementclepu->show();
        ui->RSAgenerer->show();

    }else{
    std::cout << "erreur" << std::endl;
    }
}

void MainWindow::on_RSAdechiffrer_clicked()
{
    QStringList SelectFichierRSA = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSA;

    /*
     * if qui verifie si bien un seul fichier est selectionner ( pas moin ni plus)
     */
    if(SelectFichierRSA.length() == 1){
        this ->Rsafich = SelectFichierRSA.at(0).toStdString();// transforme SelectFichierRSA qui est en qstringlist en string
        this -> RSACH = 0;//varaible bool qui dit si l'utilisateur veut chiffrer ou dechiffrer

        ui->AESchargementclepv->hide();
        ui->AESgenerer->hide();

        ui->RSAchargementclepv->show();
        ui->RSAchargementclepu->hide();
        ui->RSAgenerer->hide();

    }else{
        std::cout << "erreur" << std::endl;
    }
}

void MainWindow::on_RSAchargementclepv_clicked()
{
    QStringList SelectFichierRSAcpr = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSAcpr;

    /*
     * if qui verifie si bien un seul fichier est selectionner ( pas moin ni plus)
     */
    if(SelectFichierRSAcpr.length() == 1){

        this ->Rsafichcpr = SelectFichierRSAcpr.at(0).toStdString();// transforme SelectFichierRSAcpr qui est en qstringlist en string

        monRsa.chargementClefsPrive(this ->Rsafichcpr);

        /*
         * switch pour savoir si l'on veut chiffrer ou dechiffrer
         */
        switch(this -> RSACH){
        case 1:
            monRsa.chiffrementFichier(this->Rsafich,"chiffre_Rsa.txt",1);
            break;
        case 0:
            monRsa.dechiffrementFichier(this->Rsafich,"dechiffre_Rsa.txt",1);
            break;
        }

    }else{
        std::cout << "erreur" << std::endl;
    }

}

void MainWindow::on_RSAchargementclepu_clicked()
{
    QStringList SelectFichierRSAcpu = QFileDialog::getOpenFileNames(0, "Selection d'un Fichier", "C://", "All file (*.*)");
    qDebug() << "Fichier selectionné " << SelectFichierRSAcpu;


    /*
     * if qui verifie si bien un seul fichier est selectionner ( pas moin ni plus)
     */
    if(SelectFichierRSAcpu.length() == 1){
        this ->Rsafichcpu = SelectFichierRSAcpu.at(0).toStdString();// transforme SelectFichiercpu qui est en qstringlist en string
        monRsa.chargementClefsPublic(this ->Rsafichcpu);

        /*
         * switch pour savoir si l'on veut chiffrer ou dechiffrer
         */
        switch(this -> RSACH){
        case 1:
            monRsa.chiffrementFichier(this->Rsafich,"chiffre_Rsa.txt",1);
            break;
        case 0:
            monRsa.dechiffrementFichier(this->Rsafich,"dechiffre_Rsa.txt",1);
            break;
        }

    }else{
    std::cout << "erreur" << std::endl;
    }
}

void MainWindow::on_RSAgenerer_clicked()
{


    monRsa.generationClef("cle_public.Rsa","cle_priver.Rsa",1024); // genere une cle public "cle_public.Rsa", une cle priver "cle_priver.Rsa" avec une taille de 1024


    /*
     * switch pour savoir si l'on veut chiffrer ou dechiffrer
     */
    switch(this -> RSACH){
    case 1:
        monRsa.chiffrementFichier(this->Rsafich,"chiffre_Rsa.txt",1);
        break;
    case 0:
        monRsa.dechiffrementFichier(this->Rsafich,"dechiffre_Rsa.txt",1);
        break;
    }
}





