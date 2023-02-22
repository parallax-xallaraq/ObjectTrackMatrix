#include "ObjectMatrix.h"
#include "ui_ObjectMatrix.h"

ObjectMatrix::ObjectMatrix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ObjectMatrix)
{
    ui->setupUi(this);
}

ObjectMatrix::~ObjectMatrix()
{
    delete ui;
}
