#ifndef INSERTCLIENT_H
#define INSERTCLIENT_H

#include <QDialog>

namespace Ui {
class InsertClient;
}

class InsertClient : public QDialog
{
    Q_OBJECT

public:
    explicit InsertClient(QWidget *parent = nullptr);
    ~InsertClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InsertClient *ui;
};

#endif // INSERTCLIENT_H
