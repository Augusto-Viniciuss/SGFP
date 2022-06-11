#ifndef CADASTROWINDOW_H
#define CADASTROWINDOW_H

#include <QDialog>
#include "Empresa.h"
#include "Presidente.h"
#include "Diretor.h"
#include "Gerente.h"
#include "Operador.h"

namespace Ui {
class cadastroWindow;
}

class cadastroWindow : public QDialog
{
    Q_OBJECT

public:
    explicit cadastroWindow(QWidget *parent = nullptr);
    void setPtrEmpresa(Empresa *empresa);
    ~cadastroWindow();

private slots:
    void on_pushButton_clicked();

    void on_rb_operador_clicked(bool checked);

    void on_rb_gerente_clicked(bool checked);

    void on_rb_diretor_clicked(bool checked);

    void on_rb_presidente_clicked(bool checked);

    void on_pb_voltar_clicked();

private:
    Ui::cadastroWindow *ui;
    Empresa *empresa;
};

#endif // CADASTROWINDOW_H
