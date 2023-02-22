#ifndef OBJECTMATRIX_H
#define OBJECTMATRIX_H

#include <QWidget>

namespace Ui {
class ObjectMatrix;
}

class ObjectMatrix : public QWidget
{
    Q_OBJECT

public:
    explicit ObjectMatrix(QWidget *parent = nullptr);
    ~ObjectMatrix();

private:
    Ui::ObjectMatrix *ui;
};

#endif // OBJECTMATRIX_H
