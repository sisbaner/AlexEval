#include "dialogTable.h"
#include "ui_dialogTable.h"

DialogTable::DialogTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTable)
{
    ui->setupUi(this);

    ui->tableWidget->verticalHeader()->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction* insertAction = new QAction("insert new item",ui->tableWidget);
    QAction* deleteAction = new QAction("delete item",ui->tableWidget);
    connect(insertAction, SIGNAL(triggered()), this, SLOT(insertItem()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteItem()));
    ui->tableWidget->verticalHeader()->addAction(insertAction);
    ui->tableWidget->verticalHeader()->addAction(deleteAction);

    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setShowGrid(true);

    populate();
}

DialogTable::~DialogTable()
{
    delete ui;
}

void DialogTable::setTableHeader(QList<QString> tableHeader)
{
    m_TableHeader=tableHeader;
    populate();
}

QList<QString> DialogTable::getTableHeader()
{
    return m_TableHeader;
}

QTableWidget *DialogTable::getTableWidget()
{
    return ui->tableWidget;
}

void DialogTable::populate()
{
    ui->tableWidget->setColumnCount(m_TableHeader.size());
    ui->tableWidget->setHorizontalHeaderLabels(m_TableHeader);
}

void DialogTable::setItem(int row, int col, const QString &text)
{
    if(row>=ui->tableWidget->rowCount()) {
        ui->tableWidget->setRowCount(row+1);
    }
    if(col>=ui->tableWidget->columnCount()) {
        ui->tableWidget->setColumnCount(col+1);
    }
    ui->tableWidget->setItem(row,col, new QTableWidgetItem(text));
}

QString DialogTable::getItem(int row, int col)
{
    return ui->tableWidget->item(row, col)->text();
}

QVariant DialogTable::getItemValue(int row, int col)
{
    return ui->tableWidget->item(row, col)->data(Qt::EditRole);
}

int DialogTable::getRowCount()
{
    return ui->tableWidget->rowCount();
}

int DialogTable::getColumnCount()
{
    return ui->tableWidget->columnCount();
}



void DialogTable::insertItem()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void DialogTable::deleteItem()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void DialogTable::on_pushButtonAdd_clicked()
{
    insertItem();
}

void DialogTable::on_pushButtonRemove_clicked()
{
    deleteItem();
}

bool DialogTable::isAuto()
{
    return ui->checkBoxAuto->isChecked();
}




