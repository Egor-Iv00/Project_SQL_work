#include "headers.h"
#include "ui_updateclient.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

UpdateClient::UpdateClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateClient)
{
    ui->setupUi(this);
}

UpdateClient::~UpdateClient()
{
    delete ui;
}

void UpdateClient::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString number = ui->number->text();

    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen()) db = Connect_to_Database();

    QSqlQuery find;
    find.prepare("SELECT COUNT(*) FROM table1 WHERE name = :name");
    find.bindValue(":name",name);
    if(!find.exec()){
        QMessageBox::warning(this,"Ошибка!","Возникла ошибка при поиске клиента!");
        qDebug()<<"Ошибка при поиске клиента на удаление: "<<find.lastError().text();
        return;
    }
    find.next();
    int count = find.value(0).toInt();
    if(count==0){
        QMessageBox::information(this,"","Данный пользователь не найден");
        qDebug()<<"Попытка редактирования клиента: "<<name<<":Пользователь не найден";
        return;
    }else{
    QSqlQuery updating;
    updating.prepare("UPDATE table1 SET number = :number WHERE name = :name");
    updating.bindValue(":number",number);
    updating.bindValue(":name",name);
    updating.exec();
    QMessageBox::information(this,"","Данный клиент отредактирован");
    qDebug()<<"Попытка редактирования клиента: "<<name<<" Новое значение: "<<number<<":Успешно";
    }
}

