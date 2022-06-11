#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cadastrowindow.h"
#include "modificarWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BOTAO_SAIR_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_clicked()
{
    cadastroWindow cw;
    cw.setPtrEmpresa(&empresa);
    cw.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    modificarWindow mw;
    mw.setPtrEmpresa(&empresa);
    mw.exec();
}

