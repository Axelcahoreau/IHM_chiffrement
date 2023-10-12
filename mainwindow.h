#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLabel>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private :
    QPushButton *monbouton ;
    QLabel *monAffichage;
    int compteur;

private slots:
    void clicBouton();


};
#endif // MAINWINDOW_H
