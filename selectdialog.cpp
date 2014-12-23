#include "selectdialog.h"
#include "ui_selectdialog.h"

selectDialog::selectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectDialog)
{
    ui->setupUi(this);
}

selectDialog::~selectDialog()
{
    delete ui;
}
