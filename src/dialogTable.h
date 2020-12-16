#ifndef DIALOGTABLE_H
#define DIALOGTABLE_H

#include <QDialog>
#include<QTableWidget>

namespace Ui {
class DialogTable;
}

class DialogTable : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogTable(QWidget *parent = 0);
    ~DialogTable();
    void setTableHeader(QList<QString> tableHeader);
    QList<QString> getTableHeader();
    QTableWidget * getTableWidget();
    void populate();
    void setItem(int row, int col, const QString &text);
    QString getItem(int row, int col);
    QVariant getItemValue(int row, int col);
    int getRowCount();
    int getColumnCount();
    bool getAuto() {return isAuto();}

    
private:
    Ui::DialogTable *ui;
    QList<QString> m_TableHeader;
private slots:
    void insertItem();
    void deleteItem();
    void on_pushButtonAdd_clicked();
    void on_pushButtonRemove_clicked();
    bool isAuto();
};

#endif // DIALOGTABLE_H
