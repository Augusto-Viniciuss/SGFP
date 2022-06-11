#ifndef MODIFICARWINDOW_H
#define MODIFICARWINDOW_H

#include <QDialog>
#include "Empresa.h"

namespace Ui {
class modificarWindow;
}

class modificarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit modificarWindow(QWidget *parent = nullptr);
    void setPtrEmpresa(Empresa *empresa);
    ~modificarWindow();

private slots:
    void on_pb_voltar_clicked();

private:
    Ui::modificarWindow *ui;
    Empresa *empresa;
};

#endif // MODIFICARWINDOW_H
