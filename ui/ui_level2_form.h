/********************************************************************************
** Form generated from reading UI file 'level2_form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL2_FORM_H
#define UI_LEVEL2_FORM_H

#include <../src/Utilities/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_level2_Form
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget_plot;

    void setupUi(QWidget *level2_Form)
    {
        if (level2_Form->objectName().isEmpty())
            level2_Form->setObjectName(QString::fromUtf8("level2_Form"));
        level2_Form->resize(400, 300);
        verticalLayout = new QVBoxLayout(level2_Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_plot = new QCustomPlot(level2_Form);
        widget_plot->setObjectName(QString::fromUtf8("widget_plot"));

        verticalLayout->addWidget(widget_plot);


        retranslateUi(level2_Form);

        QMetaObject::connectSlotsByName(level2_Form);
    } // setupUi

    void retranslateUi(QWidget *level2_Form)
    {
        level2_Form->setWindowTitle(QCoreApplication::translate("level2_Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class level2_Form: public Ui_level2_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL2_FORM_H
