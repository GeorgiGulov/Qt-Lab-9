//листинг "mainwindow.cpp"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "record.h"
#include "TO.h"
#include "EO.h"
#include "SO.h"
#include "prototypefactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showlist();
    ui->info->setReadOnly(1); //установка виджета только для чтения
    ui->list->setReadOnly(1);
    ui->send->setEnabled(0); //отключение кнопки отправления

    //соединение сигнала изменения текста в виджетах с информацией
    connect(ui->brand,SIGNAL(textChanged()),this,SLOT(sendbutton()),Qt::DirectConnection);
    connect(ui->name,SIGNAL(textChanged()),this,SLOT(sendbutton()),Qt::DirectConnection);
    connect(ui->street,SIGNAL(textChanged()),this,SLOT(sendbutton()),Qt::DirectConnection);
    connect(ui->date,SIGNAL(textChanged()),this,SLOT(sendbutton()),Qt::DirectConnection);
}

MainWindow::~MainWindow() {
    delete ui;
    delete postoffice;
}


//выключение кнопки отправления
void MainWindow::sendbutton() {
    //получение строк свиджетов
    QString strns = ui->name->toPlainText();
    QString strnr = ui->brand->toPlainText();
    QString strcs = ui->street->toPlainText();
    QString strcr = ui->date->toPlainText();
    if(strns=="" || strnr=="" || strcs=="" || strcr=="")
        ui->send->setEnabled(0);
    else
        ui->send->setEnabled(1); //включение кнопки
                                 //если все четыре поля заполнены
}


//вывод списка
void MainWindow::showlist()
{
    ui->list->clear();

    if(postoffice->hasDatabase()){
    foreach(Record* p, postoffice->list){
        Record::records t = p->getType();

        if(t==Record::records::EO)
            ui->list->insertPlainText("(ЕО): ");
        else if(t==Record::records::TO)
            ui->list->insertPlainText("(ТО): ");
        else
            ui->list->insertPlainText("(СО): ");

         ui->list->insertPlainText(p->getName()
         +" ;"+p->getAuto()+" ;" +p->getData()+" ;"+p->getPlace()+"\n");
    }
    }
    else{
       ui->list->insertPlainText(" Нет записей ");
    }
}

//слот обработки сигнала нажатия на кнопку "показ списка"
void MainWindow::on_show_clicked() {
    showlist();
}

//показ информации о заказе
void MainWindow::on_receive_2_clicked() {
    ui->info->clear();
    int n = ui->number->toPlainText().toInt(); //получение порядкового номера

    if(postoffice->hasDatabase() && n>0 && n<=postoffice->list.size()){
        Record* p = postoffice->list.at(n-1); //переход к элементу по номеру

        if(p->getType() == Record::records::EO)
        {
            ui->info->insertPlainText("Ежедневное обслуживание (ЕО) \nОписание: " + p->gettextl());
        }
        else if(p->getType() == Record::records::TO)
        {
            ui->info->insertPlainText("Техническое обслуживание (ТО) \nОписание: " + p->gettext2());
        }
        else
        {
            ui->info->insertPlainText("Сезонное обслуживание (СО) \nОписание: " + p->gettext());
        }
   }
}



//функция удаления записи
void MainWindow::on_receive_clicked()
{
    ui->info->clear();
    int n = ui->number->toPlainText().toInt(); //получение порядкового номера

    if(postoffice->hasDatabase() && n>0 && n<=postoffice->list.size()){
        postoffice->list.removeAt(n-1); //удаление элемента
        showlist();//обновление списка
    }
}


//функция добавления заказа
void MainWindow::on_send_clicked()
{
    PrototypeFactory prototype;
    Record* p = NULL;

    //чтение информации о заказчике
    QString strns = ui->name->toPlainText();
    QString strnr = ui->brand->toPlainText();
    QString strcs = ui->street->toPlainText();
    QString strcr = ui->date->toPlainText();

    if(ui->radioButton->isChecked()){
        QString text = ui->text1->toPlainText();

        p = prototype.createEO();

        if(text!="")
            p->settextl(text);
        p->set(strns, strnr,strcs , strcr);
    }

    else if(ui->radioButton_2->isChecked()){
        QString text = ui->text3->toPlainText();

        p = prototype.createTO();

        if(text!="")
            p->settext2(text);
        p->set(strns, strnr,strcs , strcr);
    }

    else if(ui->radioButton_3->isChecked()){
        QString text = ui->text2->toPlainText();

        p = prototype.createSO();

        if(text!="")
            p->settext(text);
        p->set(strns, strnr,strcs , strcr);
    }

    if(p){
        postoffice->list.push_back(p); // добавление записи о ТО в список
        showlist();                    // обновление списка на экране
    }
}
