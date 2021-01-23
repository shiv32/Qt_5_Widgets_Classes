//QTableView : Default model/view implementation of a table view

#include "widget.h"
#include "ui_widget.h"
#include <QTableView>
#include "mymodel.h"
#include<QGridLayout>
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QTableView example");

    QTableView *tableView = new QTableView;
    MyModel *myModel = new MyModel;

    tableView->setModel(myModel);

    //count row col
    QAbstractItemModel* tableModel=  tableView->model();
    int iRows = tableModel->rowCount();
    int iCols = tableModel->columnCount();

    qDebug()<<"row : "<<iRows;
    qDebug()<<"col : "<<iCols;

    //set width col
    for (int col=0; col<iCols; col++)
    {
        tableView->setColumnWidth(col,150);

    }
    //set height row
    for (int row=0; row<iRows; row++){
        tableView->setRowHeight(row,80);
    }

    //add table in widget
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(tableView);
    setLayout(mainLayout);
}

Widget::~Widget()
{
    delete ui;
}

