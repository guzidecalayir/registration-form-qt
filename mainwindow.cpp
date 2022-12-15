#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList labels = {"Name", "Surname", "Age"};
    ui->tableWidget->setHorizontalHeaderLabels(labels);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   QString name = ui->lineEdit_name->text();
   QString surname = ui->lineEdit_surname->text();
   QString age = ui->lineEdit_age->text();

   if(name.isEmpty())
   {
       return;
   }
   if(surname.isEmpty())
   {
       return;
   }
   if(age.isEmpty())
   {
       return;
   }

   const int row = ui->tableWidget->rowCount();


   for(int i=0; i<(row+1); i++ )
   {
       if(ui->tableWidget->item(i,0) != nullptr)
       {
         if((ui->tableWidget->item(i,0)->text()) == name && (ui->tableWidget->item(i,1)->text()) == surname && (ui->tableWidget->item(i,2)->text()) == age )
         {
            QMessageBox::warning(this,"Warning", "Person already exist.");
            break;
         }
       }
       else
       {
       ui->tableWidget->insertRow(row);
       ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
       ui->tableWidget->setItem(row, 1, new QTableWidgetItem(surname));
       ui->tableWidget->setItem(row, 2, new QTableWidgetItem(age));
       }
   }
}

