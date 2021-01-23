#include "widget.h"
#include "ui_widget.h"
#include <QTableWidget>
#include<QGridLayout>
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QTableWidget example");

    QTableWidget *tableWidget = new QTableWidget;

    tableWidget->setColumnCount(3);
    tableWidget->setRowCount(2);

    for (int ridx = 0 ; ridx < 2 ; ridx++ )
    {
        for (int cidx = 0 ; cidx < 3 ; cidx++)
        {
          QTableWidgetItem* item = new QTableWidgetItem();
          item->setText(QString("Row%1, Column%2").arg(ridx + 1).arg(cidx +1));
          tableWidget->setItem(ridx,cidx,item);
        }
    }

    //set width col
    for (int col=0; col<3; col++)
    {
        tableWidget->setColumnWidth(col,150);

    }
    //set height row
    for (int row=0; row<3; row++){
        tableWidget->setRowHeight(row,80);
    }

    //add table in widget
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(tableWidget);
    setLayout(mainLayout);
}

Widget::~Widget()
{
    delete ui;
}

