#include "cadastrowindow.h"
#include "ui_cadastrowindow.h"

cadastroWindow::cadastroWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroWindow)
{
    ui->setupUi(this);
    ui->line_AreaFormacao->setDisabled(true);
    ui->line_AreaSupervisao->setDisabled(true);
    ui->rb_graduacao->setDisabled(true);
    ui->rb_mestrado->setDisabled(true);
    ui->rb_doutorado->setDisabled(true);
    ui->rb_PHD->setDisabled(true);
}

cadastroWindow::~cadastroWindow()
{
    delete ui;
}

void cadastroWindow::setPtrEmpresa(Empresa *empresa) {
    this->empresa = empresa;
}

void cadastroWindow::on_pushButton_clicked()
{
    QString nome, telefone, CEP, CPF, data, areaSupervisao, areaFormacao;
    int codigo, idade, estadoCivil, designacao, formacaoMax;

    nome = telefone = CEP = CPF = data = areaSupervisao = areaFormacao = "";
    idade = codigo = estadoCivil = designacao = formacaoMax = -1;

    nome = ui->line_nome->text();
    codigo = ui->spinBox_codigo->value();
    idade = ui->spinBox_idade->value();
    telefone = ui->line_telefone->text();
    CPF = ui->line_CPF->text();
    CEP = ui->line_CEP->text();
    if(ui->rb_solteiro->isChecked()) {
        estadoCivil = 0;
    } else if(ui->rb_casado->isChecked()) {
        estadoCivil = 1;
    } else if(ui->rb_viuvo->isChecked()) {
        estadoCivil = 2;
    }
    data = ui->dateEdit_dataIngresso->text();
    if(ui->rb_operador->isChecked()) {
        designacao = 0;
    } else if(ui->rb_gerente->isChecked()) {
        designacao = 1;
    } else if(ui->rb_diretor->isChecked()) {
        designacao = 2;
    } else if(ui->rb_presidente->isChecked()) {
        designacao = 3;
    }
    areaSupervisao = ui->line_AreaSupervisao->text();
    areaFormacao = ui->line_AreaFormacao->text();
    if(ui->rb_graduacao->isChecked()) {
        formacaoMax = 0;
    } else if(ui->rb_mestrado->isChecked()) {
        formacaoMax = 1;
    } else if(ui->rb_doutorado->isChecked()) {
        formacaoMax = 2;
    } else if(ui->rb_PHD->isChecked()) {
        formacaoMax = 3;
    }

    if(designacao == 0) {
        if((nome == "") || (telefone == "") || (CEP == "") || (CPF == "") || (data == "") || (idade == -1) || (estadoCivil == -1) || (codigo == -1)) {
           return;
        }
    } else if(designacao == 1) {
        if((nome == "") || (telefone == "") || (CEP == "") || (CPF == "") || (areaSupervisao == "") || (data == "") || (idade == -1) || (estadoCivil == -1) || (codigo == -1)) {
           return;
        }
    } else if(designacao == 2) {
        if((nome == "") || (telefone == "") || (CEP == "") || (CPF == "") || (areaSupervisao == "") || (areaFormacao == "") ||  (data == "") || (idade == -1) || (estadoCivil == -1) || (codigo == -1)) {
           return;
        }
    } else if(designacao == 3) {
        if((nome == "") || (telefone == "") || (CEP == "") || (CPF == "") || (areaFormacao == "") || (data == "") || (idade == -1) || (estadoCivil == -1) || (formacaoMax == -1) || (codigo == -1)) {
           return;
        }
    } else if(designacao == -1){
        return;
    }

    switch (designacao) {
    case 0:
        //this->empresa->addFuncionario(new Operador(codigo, nome.toStdString(), CPF.toStdString(), idade, CEP.toStdString(), telefone.toStdString(), data.toStdString(), designacao));
        break;
    case 1:
        //this->empresa->addFuncionario(new Gerente(codigo, nome.toStdString(), CPF.toStdString(), idade, CEP.toStdString(), telefone.toStdString(), data.toStdString(), designacao, areaSupervisao.toStdString()));
        break;
    case 2:
        //this->empresa->addFuncionario(new Diretor(codigo, nome.toStdString(), CPF.toStdString(), idade, CEP.toStdString(), telefone.toStdString(), data.toStdString(), designacao, areaSupervisao.toStdString(), areaFormacao.toStdString()));
        break;
    case 3:
        //this->empresa->addFuncionario(new Presidente(codigo, nome.toStdString(), CPF.toStdString(), idade, CEP.toStdString(), telefone.toStdString(), data.toStdString(), designacao, areaFormacao.toStdString(), formacaoMax));
        break;
    }


    this->close();
}

void cadastroWindow::on_rb_operador_clicked(bool checked)
{
    ui->line_AreaFormacao->setDisabled(true);
    ui->line_AreaSupervisao->setDisabled(true);
    ui->rb_graduacao->setDisabled(true);
    ui->rb_mestrado->setDisabled(true);
    ui->rb_doutorado->setDisabled(true);
    ui->rb_PHD->setDisabled(true);

    ui->line_AreaFormacao->setStyleSheet("background-color: rgb(191, 191, 191);");
    ui->line_AreaSupervisao->setStyleSheet("background-color: rgb(191, 191, 191);");
}

void cadastroWindow::on_rb_gerente_clicked(bool checked)
{
    ui->line_AreaSupervisao->setDisabled(false);
    ui->line_AreaSupervisao->setStyleSheet("background-color: rgb(255, 255, 255);");
}

void cadastroWindow::on_rb_diretor_clicked(bool checked)
{
    ui->line_AreaFormacao->setDisabled(false);
    ui->line_AreaFormacao->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->line_AreaSupervisao->setDisabled(false);
    ui->line_AreaSupervisao->setStyleSheet("background-color: rgb(255, 255, 255);");
}

void cadastroWindow::on_rb_presidente_clicked(bool checked)
{
    ui->line_AreaSupervisao->setDisabled(true);
    ui->line_AreaFormacao->setDisabled(false);
    ui->rb_graduacao->setDisabled(false);
    ui->rb_mestrado->setDisabled(false);
    ui->rb_doutorado->setDisabled(false);
    ui->rb_PHD->setDisabled(false);

    ui->line_AreaSupervisao->setStyleSheet("background-color: rgb(191, 191, 191);");
    ui->line_AreaFormacao->setStyleSheet("background-color: rgb(255, 255, 255);");
}

void cadastroWindow::on_pb_voltar_clicked()
{
    this->close();
}
