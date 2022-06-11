#include "modificarwindow.h"
#include "ui_modificarwindow.h"

modificarWindow::modificarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modificarWindow)
{
    ui->setupUi(this);
}

void modificarWindow::setPtrEmpresa(Empresa *empresa) {
    this->empresa = empresa;
}

modificarWindow::~modificarWindow()
{
    delete ui;
}

void modificarWindow::on_pb_voltar_clicked()
{
    this->close();
}

