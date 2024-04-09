/********************************************************************************
** Form generated from reading UI file 'controlmode_form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLMODE_FORM_H
#define UI_CONTROLMODE_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlMode_Form
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *m_widget_start;
    QVBoxLayout *verticalLayout;
    QLabel *m_label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *m_pushButton_start;
    QWidget *m_widget_test;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *m_label_eror;
    QPushButton *m_pushButton_next;
    QWidget *m_widget_result;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_label_result;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_pushButton_restart;

    void setupUi(QWidget *ControlMode_Form)
    {
        if (ControlMode_Form->objectName().isEmpty())
            ControlMode_Form->setObjectName(QString::fromUtf8("ControlMode_Form"));
        ControlMode_Form->resize(884, 374);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControlMode_Form->sizePolicy().hasHeightForWidth());
        ControlMode_Form->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(ControlMode_Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_widget_start = new QWidget(ControlMode_Form);
        m_widget_start->setObjectName(QString::fromUtf8("m_widget_start"));
        verticalLayout = new QVBoxLayout(m_widget_start);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_label = new QLabel(m_widget_start);
        m_label->setObjectName(QString::fromUtf8("m_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_label->sizePolicy().hasHeightForWidth());
        m_label->setSizePolicy(sizePolicy1);
        m_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_label);

        verticalSpacer = new QSpacerItem(20, 281, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        m_pushButton_start = new QPushButton(m_widget_start);
        m_pushButton_start->setObjectName(QString::fromUtf8("m_pushButton_start"));
        m_pushButton_start->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(m_pushButton_start);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout->addWidget(m_widget_start);

        m_widget_test = new QWidget(ControlMode_Form);
        m_widget_test->setObjectName(QString::fromUtf8("m_widget_test"));
        sizePolicy1.setHeightForWidth(m_widget_test->sizePolicy().hasHeightForWidth());
        m_widget_test->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(m_widget_test);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(m_widget_test);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(m_widget_test);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(0, 0));

        verticalLayout_3->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        m_label_eror = new QLabel(m_widget_test);
        m_label_eror->setObjectName(QString::fromUtf8("m_label_eror"));
        m_label_eror->setStyleSheet(QString::fromUtf8("color: red"));

        horizontalLayout_3->addWidget(m_label_eror);

        m_pushButton_next = new QPushButton(m_widget_test);
        m_pushButton_next->setObjectName(QString::fromUtf8("m_pushButton_next"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_pushButton_next->sizePolicy().hasHeightForWidth());
        m_pushButton_next->setSizePolicy(sizePolicy3);
        m_pushButton_next->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(m_pushButton_next);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(m_widget_test);

        m_widget_result = new QWidget(ControlMode_Form);
        m_widget_result->setObjectName(QString::fromUtf8("m_widget_result"));
        verticalLayout_2 = new QVBoxLayout(m_widget_result);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_label_result = new QLabel(m_widget_result);
        m_label_result->setObjectName(QString::fromUtf8("m_label_result"));
        sizePolicy1.setHeightForWidth(m_label_result->sizePolicy().hasHeightForWidth());
        m_label_result->setSizePolicy(sizePolicy1);
        m_label_result->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(m_label_result);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        m_pushButton_restart = new QPushButton(m_widget_result);
        m_pushButton_restart->setObjectName(QString::fromUtf8("m_pushButton_restart"));
        m_pushButton_restart->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(m_pushButton_restart);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(m_widget_result);


        retranslateUi(ControlMode_Form);

        QMetaObject::connectSlotsByName(ControlMode_Form);
    } // setupUi

    void retranslateUi(QWidget *ControlMode_Form)
    {
        ControlMode_Form->setWindowTitle(QCoreApplication::translate("ControlMode_Form", "Form", nullptr));
        m_label->setText(QCoreApplication::translate("ControlMode_Form", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        m_pushButton_start->setText(QCoreApplication::translate("ControlMode_Form", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("ControlMode_Form", "1/12", nullptr));
        m_label_eror->setText(QCoreApplication::translate("ControlMode_Form", "\320\236\321\210\320\270\320\261\320\272\320\260. \320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\276\320\264\320\270\320\275 \320\270\320\267 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\320\276\320\262 \320\276\321\202\320\262\320\265\321\202\320\260.", nullptr));
        m_pushButton_next->setText(QCoreApplication::translate("ControlMode_Form", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        m_label_result->setText(QCoreApplication::translate("ControlMode_Form", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        m_pushButton_restart->setText(QCoreApplication::translate("ControlMode_Form", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlMode_Form: public Ui_ControlMode_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLMODE_FORM_H
