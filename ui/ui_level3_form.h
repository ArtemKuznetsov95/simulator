/********************************************************************************
** Form generated from reading UI file 'level3_form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL3_FORM_H
#define UI_LEVEL3_FORM_H

#include <../src/Utilities/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_level3_Form
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget_plot;

    void setupUi(QWidget *level3_Form)
    {
        if (level3_Form->objectName().isEmpty())
            level3_Form->setObjectName(QString::fromUtf8("level3_Form"));
        level3_Form->resize(400, 300);
        verticalLayout = new QVBoxLayout(level3_Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_plot = new QCustomPlot(level3_Form);
        widget_plot->setObjectName(QString::fromUtf8("widget_plot"));

        verticalLayout->addWidget(widget_plot);


        retranslateUi(level3_Form);

        QMetaObject::connectSlotsByName(level3_Form);
    } // setupUi

    void retranslateUi(QWidget *level3_Form)
    {
        level3_Form->setWindowTitle(QCoreApplication::translate("level3_Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class level3_Form: public Ui_level3_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL3_FORM_H
