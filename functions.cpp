#include "functions.h"


QSqlDatabase Connect_to_Database(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("TestDatabase");
    db.setUserName("sysadmin");
    db.setPassword("sysadmin");
    if(!db.open()){
        QSqlError error = db.lastError();
        qDebug()<< "Ошибка подключения к базе данных: "<<error.text();
    }else{
        qDebug()<<"Успешное подключение к базе данных\n";
    }
    return db;
}
