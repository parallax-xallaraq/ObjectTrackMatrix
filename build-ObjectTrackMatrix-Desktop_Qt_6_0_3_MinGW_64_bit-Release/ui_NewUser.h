/********************************************************************************
** Form generated from reading UI file 'NewUser.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSER_H
#define UI_NEWUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewUser
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_welcome;
    QLabel *label_instructions;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_newExperiment;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *NewUser)
    {
        if (NewUser->objectName().isEmpty())
            NewUser->setObjectName(QString::fromUtf8("NewUser"));
        NewUser->resize(400, 100);
        verticalLayout_2 = new QVBoxLayout(NewUser);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_welcome = new QLabel(NewUser);
        label_welcome->setObjectName(QString::fromUtf8("label_welcome"));

        verticalLayout->addWidget(label_welcome, 0, Qt::AlignHCenter);

        label_instructions = new QLabel(NewUser);
        label_instructions->setObjectName(QString::fromUtf8("label_instructions"));

        verticalLayout->addWidget(label_instructions, 0, Qt::AlignHCenter);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_newExperiment = new QPushButton(NewUser);
        pushButton_newExperiment->setObjectName(QString::fromUtf8("pushButton_newExperiment"));

        horizontalLayout->addWidget(pushButton_newExperiment);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(NewUser);

        QMetaObject::connectSlotsByName(NewUser);
    } // setupUi

    void retranslateUi(QWidget *NewUser)
    {
        NewUser->setWindowTitle(QCoreApplication::translate("NewUser", "Form", nullptr));
        label_welcome->setText(QCoreApplication::translate("NewUser", "Welcome!", nullptr));
        label_instructions->setText(QCoreApplication::translate("NewUser", "Click the button below to setup a new experiment. ", nullptr));
        pushButton_newExperiment->setText(QCoreApplication::translate("NewUser", "New Experiment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewUser: public Ui_NewUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSER_H
