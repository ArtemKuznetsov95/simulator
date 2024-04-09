/********************************************************************************
** Form generated from reading UI file 'level1_form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL1_FORM_H
#define UI_LEVEL1_FORM_H

#include <../src/Utilities/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_level1_Form
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget_plot;

    void setupUi(QWidget *level1_Form)
    {
        if (level1_Form->objectName().isEmpty())
            level1_Form->setObjectName(QString::fromUtf8("level1_Form"));
        level1_Form->resize(1000, 461);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(level1_Form->sizePolicy().hasHeightForWidth());
        level1_Form->setSizePolicy(sizePolicy);
        level1_Form->setMinimumSize(QSize(1000, 0));
        verticalLayout = new QVBoxLayout(level1_Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_plot = new QCustomPlot(level1_Form);
        widget_plot->setObjectName(QString::fromUtf8("widget_plot"));

        verticalLayout->addWidget(widget_plot);


        retranslateUi(level1_Form);

        QMetaObject::connectSlotsByName(level1_Form);
    } // setupUi

    void retranslateUi(QWidget *level1_Form)
    {
        level1_Form->setWindowTitle(QCoreApplication::translate("level1_Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class level1_Form: public Ui_level1_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL1_FORM_H
