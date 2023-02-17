#include "GetUserInfo.h"
#include "ui_GetUserInfo.h"

GetUserInfo::GetUserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetUserInfo)
{
    ui->setupUi(this);
}

GetUserInfo::~GetUserInfo()
{
    delete ui;
}
