#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(): QWidget()
{
    this->compteur = 0;
    setFixedSize(150, 100);

    monbouton = new QPushButton("bouton", this);
    monbouton->move(10, 10);
    monAffichage = new QLabel("0", this);
    monAffichage->move(10, 50);

    connect(monbouton, SIGNAL(clicked()), this, SLOT(clicBouton()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::clicBouton()
{
    this->compteur++;
    this->monAffichage->setText(QString::number(this->compteur));
    this->monAffichage->adjustSize();
}

