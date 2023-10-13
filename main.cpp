#include "mainwindow.h"

#include <QApplication>
#include "HashGestion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    HashGestion monSteak;

    std::string hashRes = monSteak.CalculateSHA256("testPV");
    std::cout << "Resultat Hash : " << hashRes << std::endl;

    return a.exec();
}
