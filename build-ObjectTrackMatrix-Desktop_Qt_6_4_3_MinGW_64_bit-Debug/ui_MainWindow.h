/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ExperimentSetup.h"
#include "GetUserInfo.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_experimentDetails;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_userInfo;
    QVBoxLayout *verticalLayout_2;
    GetUserInfo *widget_userInfo;
    QGroupBox *groupBox_experimentSetup;
    QVBoxLayout *verticalLayout_3;
    ExperimentSetup *widget_experimentSetup;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_experimentEdit;
    QPushButton *pushButton_experimentSubmit;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_objectMatrix;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_startExperiment;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox_NewUser;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_newExperiment;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 494);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        groupBox_experimentDetails = new QGroupBox(centralwidget);
        groupBox_experimentDetails->setObjectName("groupBox_experimentDetails");
        verticalLayout_4 = new QVBoxLayout(groupBox_experimentDetails);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        groupBox_userInfo = new QGroupBox(groupBox_experimentDetails);
        groupBox_userInfo->setObjectName("groupBox_userInfo");
        verticalLayout_2 = new QVBoxLayout(groupBox_userInfo);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_userInfo = new GetUserInfo(groupBox_userInfo);
        widget_userInfo->setObjectName("widget_userInfo");

        verticalLayout_2->addWidget(widget_userInfo, 0, Qt::AlignTop);


        horizontalLayout_3->addWidget(groupBox_userInfo);

        groupBox_experimentSetup = new QGroupBox(groupBox_experimentDetails);
        groupBox_experimentSetup->setObjectName("groupBox_experimentSetup");
        verticalLayout_3 = new QVBoxLayout(groupBox_experimentSetup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_experimentSetup = new ExperimentSetup(groupBox_experimentSetup);
        widget_experimentSetup->setObjectName("widget_experimentSetup");

        verticalLayout_3->addWidget(widget_experimentSetup, 0, Qt::AlignTop);


        horizontalLayout_3->addWidget(groupBox_experimentSetup);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_experimentEdit = new QPushButton(groupBox_experimentDetails);
        pushButton_experimentEdit->setObjectName("pushButton_experimentEdit");

        horizontalLayout->addWidget(pushButton_experimentEdit);

        pushButton_experimentSubmit = new QPushButton(groupBox_experimentDetails);
        pushButton_experimentSubmit->setObjectName("pushButton_experimentSubmit");

        horizontalLayout->addWidget(pushButton_experimentSubmit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);


        gridLayout->addWidget(groupBox_experimentDetails, 1, 0, 1, 1);

        groupBox_objectMatrix = new QGroupBox(centralwidget);
        groupBox_objectMatrix->setObjectName("groupBox_objectMatrix");
        verticalLayout_5 = new QVBoxLayout(groupBox_objectMatrix);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        pushButton_startExperiment = new QPushButton(groupBox_objectMatrix);
        pushButton_startExperiment->setObjectName("pushButton_startExperiment");

        horizontalLayout_5->addWidget(pushButton_startExperiment);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_5);


        gridLayout->addWidget(groupBox_objectMatrix, 2, 0, 1, 1);

        groupBox_NewUser = new QGroupBox(centralwidget);
        groupBox_NewUser->setObjectName("groupBox_NewUser");
        verticalLayout = new QVBoxLayout(groupBox_NewUser);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBox_NewUser);
        label->setObjectName("label");

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        label_2 = new QLabel(groupBox_NewUser);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_newExperiment = new QPushButton(groupBox_NewUser);
        pushButton_newExperiment->setObjectName("pushButton_newExperiment");

        horizontalLayout_2->addWidget(pushButton_newExperiment);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox_NewUser, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_experimentDetails->setTitle(QCoreApplication::translate("MainWindow", "Experiment Details", nullptr));
        groupBox_userInfo->setTitle(QCoreApplication::translate("MainWindow", "User Information", nullptr));
        groupBox_experimentSetup->setTitle(QCoreApplication::translate("MainWindow", "Experiment Setup", nullptr));
        pushButton_experimentEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButton_experimentSubmit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        groupBox_objectMatrix->setTitle(QCoreApplication::translate("MainWindow", "Experiment", nullptr));
        pushButton_startExperiment->setText(QCoreApplication::translate("MainWindow", "Start Experiment", nullptr));
        groupBox_NewUser->setTitle(QCoreApplication::translate("MainWindow", "New User", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome!", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Click the button below to setup a new experiment.", nullptr));
        pushButton_newExperiment->setText(QCoreApplication::translate("MainWindow", "New Experiment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
