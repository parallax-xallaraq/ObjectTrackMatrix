#ifndef GETUSERINFO_H
#define GETUSERINFO_H

#include <QWidget>

namespace Ui {
class GetUserInfo;
}

class GetUserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit GetUserInfo(QWidget *parent = nullptr);
    ~GetUserInfo();

private:
    Ui::GetUserInfo *ui;
};

#endif // GETUSERINFO_H
