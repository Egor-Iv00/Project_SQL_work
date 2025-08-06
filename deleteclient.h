#ifndef DELETECLIENT_H
#define DELETECLIENT_H

#include <QDialog>

namespace Ui {
class DeleteClient;
}

class DeleteClient : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteClient(QWidget *parent = nullptr);
    ~DeleteClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteClient *ui;
};

#endif // DELETECLIENT_H
