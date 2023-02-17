#include "NewUser.h"
#include "ui_NewUser.h"

NewUser::NewUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUser)
{
    ui->setupUi(this);
}

NewUser::~NewUser()
{
    delete ui;
}
