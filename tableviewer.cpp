#include "headers.h"
#include "ui_tableviewer.h"

#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlField>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>

TableViewer::TableViewer( QWidget *parent) :QDialog(parent),ui(new Ui::TableViewer){

    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen()) db = Connect_to_Database();
    QString tableName = db.tables().first();

    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setAlternatingRowColors(true);

    loadData(tableName);
}

void TableViewer::loadData(const QString &tableName)
{
    QSqlQuery query;
    if (!query.exec("SELECT * FROM " + tableName)) {
        QMessageBox::critical(this, "Ошибка", query.lastError().text());
        return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(query.record().count());

    QStringList headers;
    for (int i = 0; i < query.record().count(); ++i) {
        headers << query.record().fieldName(i);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        for (int col = 0; col < query.record().count(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(
                query.isNull(col) ? "NULL" : query.value(col).toString()
            );

            if (query.record().field(col).type() == QVariant::Int ||
                query.record().field(col).type() == QVariant::Double) {
                item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            }

            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }

}

TableViewer::~TableViewer()
{
    delete ui;
}
