#include "ExperimentSetup.h"
#include "ui_ExperimentSetup.h"

ExperimentSetup::ExperimentSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExperimentSetup)
{
    ui->setupUi(this);
}

ExperimentSetup::~ExperimentSetup()
{
    delete ui;
}
