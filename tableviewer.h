#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class TableViewer;
}

class TableViewer : public QDialog
{
    Q_OBJECT

public:
    explicit TableViewer(QWidget *parent = nullptr);
    ~TableViewer();

private:
    Ui::TableViewer *ui;
    void loadData(const QString &tableName);
};
