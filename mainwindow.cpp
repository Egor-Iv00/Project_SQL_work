#include "headers.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_InsertClient_clicked()
{
    InsertClient window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_UpdateClient_clicked()
{
    UpdateClient window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_DeleteClient_clicked()
{
    DeleteClient window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_printTable_clicked()
{
    TableViewer window;
    window.setModal(true);
    window.exec();
}
