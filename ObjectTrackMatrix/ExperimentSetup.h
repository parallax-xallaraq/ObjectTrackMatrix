#ifndef EXPERIMENTSETUP_H
#define EXPERIMENTSETUP_H

#include <QWidget>

namespace Ui {
class ExperimentSetup;
}

class ExperimentSetup : public QWidget
{
    Q_OBJECT

public:
    explicit ExperimentSetup(QWidget *parent = nullptr);
    ~ExperimentSetup();

private:
    Ui::ExperimentSetup *ui;
};

#endif // EXPERIMENTSETUP_H
