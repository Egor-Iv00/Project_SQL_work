#include "headers.h"
#include "ui_deleteclient.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

DeleteClient::DeleteClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteClient)
{
    ui->setupUi(this);
    this->setFixedSize(300,170);
}

DeleteClient::~DeleteClient()
{
    delete ui;
}

void DeleteClient::on_pushButton_clicked()
{
   QString name = ui->name->text();

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
       qDebug()<<"Попытка удаления клиента: "<<name<<":Пользователь не найден";
       return;
   }else{
   QSqlQuery deleting;
   deleting.prepare("DELETE FROM table1 WHERE name = :name");
   deleting.bindValue(":name",name);
   deleting.exec();
   QMessageBox::information(this,"","Данный клиент удалён");
   qDebug()<<"Попытка удаления клиента: "<<name<<":Успешно";
   }
}

