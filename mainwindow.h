#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Exit_clicked();

    void on_SHA256_clicked();

    void on_RSA_clicked();

    void on_AES_clicked();

    void on_AESchiffrer_clicked();

    void on_AESdechiffrer_clicked();

    void on_RSAchiffrer_clicked();

    void on_RSAdechiffrer_clicked();

    void on_SHA256fichier_clicked();

    void on_RSAchargementclepv_clicked();

    void on_RSAchargementclepu_clicked();

    void on_RSAgenerer_clicked();

    void on_AESchargementclepv_clicked();

    void on_AESgenerer_clicked();

private:
    Ui::MainWindow *ui;

    int monCompteur;

};
#endif // MAINWINDOW_H
