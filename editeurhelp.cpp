#include "editeurhelp.h"
#include "ui_editeurhelp.h"

editeurhelp::editeurhelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editeurhelp)
{
    ui->setupUi(this);
}

editeurhelp::~editeurhelp()
{
    delete ui;
}
