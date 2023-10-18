#include "mainwindow.h"

#include <QApplication>
#include "AesGestion.h"
#include "RsaGestion.h"
#include "HashGestion.h"
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //HashGestion monSteak;
    //std::string hashRes = monSteak.CalculateSHA256("essaie sha");
    //std::cout << "Resultat Hash : " << hashRes << std::endl;
    //std::cout << "Le Fichier selectionner : " << filename << std::endl;


    //AesGestion Aes;
    //Aes.GenerateAESKey();
    //Aes.SaveAESKeyToFile("cle");
    //Aes.LoadAESKeyFromFile("cle");
    //Aes.EncryptFileAES256("un.txt", "deux.txt");
    //Aes.DecryptFileAES256("deux.txt", "trois.txt");

    /*RsaGestion Rsa;
    Rsa.generationClef("pu", "pr", 1024);
    Rsa.chiffrementFichier("rsa1.txt","rsa2.txt",1);
    Rsa.dechiffrementFichier("rsa2.txt", "rsa3.txt", 1);*/


    return a.exec();
}
