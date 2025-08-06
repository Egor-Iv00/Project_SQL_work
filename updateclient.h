#ifndef UPDATECLIENT_H
#define UPDATECLIENT_H

#include <QDialog>

namespace Ui {
class UpdateClient;
}

class UpdateClient : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateClient(QWidget *parent = nullptr);
    ~UpdateClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UpdateClient *ui;
};

#endif // UPDATECLIENT_H
