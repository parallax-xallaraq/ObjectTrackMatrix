/********************************************************************************
** Form generated from reading UI file 'ObjectMatrix.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTMATRIX_H
#define UI_OBJECTMATRIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectMatrix
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_objectMatrix;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget_objects;

    void setupUi(QWidget *ObjectMatrix)
    {
        if (ObjectMatrix->objectName().isEmpty())
            ObjectMatrix->setObjectName("ObjectMatrix");
        ObjectMatrix->resize(548, 196);
        verticalLayout = new QVBoxLayout(ObjectMatrix);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_objectMatrix = new QLabel(ObjectMatrix);
        label_objectMatrix->setObjectName("label_objectMatrix");

        horizontalLayout->addWidget(label_objectMatrix);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget_objects = new QTableWidget(ObjectMatrix);
        if (tableWidget_objects->columnCount() < 4)
            tableWidget_objects->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_objects->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_objects->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_objects->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_objects->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_objects->rowCount() < 3)
            tableWidget_objects->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_objects->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_objects->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_objects->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_objects->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_objects->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_objects->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_objects->setItem(0, 3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_objects->setItem(1, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_objects->setItem(1, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_objects->setItem(1, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_objects->setItem(1, 3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_objects->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_objects->setItem(2, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_objects->setItem(2, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_objects->setItem(2, 3, __qtablewidgetitem18);
        tableWidget_objects->setObjectName("tableWidget_objects");

        verticalLayout->addWidget(tableWidget_objects);


        retranslateUi(ObjectMatrix);

        QMetaObject::connectSlotsByName(ObjectMatrix);
    } // setupUi

    void retranslateUi(QWidget *ObjectMatrix)
    {
        ObjectMatrix->setWindowTitle(QCoreApplication::translate("ObjectMatrix", "Form", nullptr));
        label_objectMatrix->setText(QCoreApplication::translate("ObjectMatrix", "Object Matrix", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_objects->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ObjectMatrix", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_objects->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ObjectMatrix", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_objects->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ObjectMatrix", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_objects->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ObjectMatrix", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_objects->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ObjectMatrix", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_objects->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ObjectMatrix", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_objects->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ObjectMatrix", "G", nullptr));

        const bool __sortingEnabled = tableWidget_objects->isSortingEnabled();
        tableWidget_objects->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_objects->item(0, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ObjectMatrix", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_objects->item(0, 1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ObjectMatrix", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_objects->item(0, 2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ObjectMatrix", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_objects->item(0, 3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ObjectMatrix", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_objects->item(1, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ObjectMatrix", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_objects->item(1, 1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ObjectMatrix", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_objects->item(1, 2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("ObjectMatrix", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_objects->item(1, 3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("ObjectMatrix", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_objects->item(2, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("ObjectMatrix", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_objects->item(2, 1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("ObjectMatrix", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_objects->item(2, 2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("ObjectMatrix", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_objects->item(2, 3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("ObjectMatrix", "12", nullptr));
        tableWidget_objects->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ObjectMatrix: public Ui_ObjectMatrix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTMATRIX_H
