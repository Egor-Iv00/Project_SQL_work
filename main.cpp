#include "headers.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = Connect_to_Database();
    if(!db.isOpen()){
        QMessageBox::critical(nullptr,"Ошибка","В результате работы приложения возникла ошибка!\n");
        return 1;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
