//листинг "mainwindow.h"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void showlist();
    ~MainWindow();

private slots:
    void on_show_clicked();
    void on_receive_2_clicked();
    void on_receive_clicked();
    void on_send_clicked();
    void sendbutton();

private:
    Ui::MainWindow *ui;
    Database* postoffice = Database::getpost();
};
#endif // MAINWINDOW_H

