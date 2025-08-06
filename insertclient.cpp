#include "headers.h"
#include "ui_insertclient.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

InsertClient::InsertClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertClient)
{
    this->setFixedSize(300,170);
    ui->setupUi(this);
}

InsertClient::~InsertClient()
{
    delete ui;
}

void InsertClient::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString number = ui->number->text();

    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen()) db = Connect_to_Database();

    QSqlQuery check;
    check.prepare("SELECT COUNT(*) FROM table1 WHERE name = :name");
    check.bindValue(":name",name);
    if(!check.exec()){
        QMessageBox::critical(this,"Ошибка!","Возникла ошибка!");
        qDebug()<<"Возникла ошибка при поиске клиента: "<<check.lastError().text();
        return;
    }
    if(check.next()){
        int count = check.value(0).toInt();
        if (count>0){
            QMessageBox::critical(this,"Ошибка!","Данный пользователь уже существует!");
            return;
        }
    }
    QSqlQuery insert;
    insert.prepare("INSERT INTO table1 (name,number)"
                   "VALUES (:name, :number); ");
    insert.bindValue(":name",name);
    insert.bindValue(":number",number);

    if(!insert.exec()){
        qDebug()<<"Возникла ошибка при добавлении клиента: "<<insert.lastError().text();
        QMessageBox::critical(this,"Ошибка!","Возникла ошибка!");
    }
    QMessageBox::information(this,"Успешно!","Пользователь успешно добавлен!");
    qDebug()<<"Клиент "<<name<<" с номером "<<number<<" добавлен в базу";
    return;
}

