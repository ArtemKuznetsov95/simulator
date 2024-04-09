/********************************************************************************
** Form generated from reading UI file 'tratining_form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRATINING_FORM_H
#define UI_TRATINING_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tratining_Form
{
public:
    QFormLayout *formLayout_2;
    QWidget *m_widget_navi;
    QVBoxLayout *verticalLayout;
    QWidget *m_widget_EFS;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_pushButton_ekg;
    QPushButton *m_pushButton_emg;
    QPushButton *m_pushButton_eeg;
    QGroupBox *m_groupBox_mode;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *m_radioButton_beat;
    QRadioButton *m_radioButton_form;
    QGroupBox *m_groupBox_vid;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *m_radioButton_norm;
    QRadioButton *m_radioButton_pathology;
    QListView *m_listView_diogram;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QFormLayout *formLayout;

    void setupUi(QWidget *Tratining_Form)
    {
        if (Tratining_Form->objectName().isEmpty())
            Tratining_Form->setObjectName(QString::fromUtf8("Tratining_Form"));
        Tratining_Form->resize(974, 635);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Tratining_Form->sizePolicy().hasHeightForWidth());
        Tratining_Form->setSizePolicy(sizePolicy);
        Tratining_Form->setMinimumSize(QSize(0, 0));
        Tratining_Form->setMaximumSize(QSize(16777215, 16777215));
        formLayout_2 = new QFormLayout(Tratining_Form);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        m_widget_navi = new QWidget(Tratining_Form);
        m_widget_navi->setObjectName(QString::fromUtf8("m_widget_navi"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_widget_navi->sizePolicy().hasHeightForWidth());
        m_widget_navi->setSizePolicy(sizePolicy1);
        m_widget_navi->setMaximumSize(QSize(350, 16777215));
        verticalLayout = new QVBoxLayout(m_widget_navi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_widget_EFS = new QWidget(m_widget_navi);
        m_widget_EFS->setObjectName(QString::fromUtf8("m_widget_EFS"));
        verticalLayout_4 = new QVBoxLayout(m_widget_EFS);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_pushButton_ekg = new QPushButton(m_widget_EFS);
        m_pushButton_ekg->setObjectName(QString::fromUtf8("m_pushButton_ekg"));
        m_pushButton_ekg->setCheckable(true);
        m_pushButton_ekg->setChecked(false);

        horizontalLayout_2->addWidget(m_pushButton_ekg);

        m_pushButton_emg = new QPushButton(m_widget_EFS);
        m_pushButton_emg->setObjectName(QString::fromUtf8("m_pushButton_emg"));
        m_pushButton_emg->setCheckable(true);

        horizontalLayout_2->addWidget(m_pushButton_emg);

        m_pushButton_eeg = new QPushButton(m_widget_EFS);
        m_pushButton_eeg->setObjectName(QString::fromUtf8("m_pushButton_eeg"));
        m_pushButton_eeg->setCheckable(true);

        horizontalLayout_2->addWidget(m_pushButton_eeg);


        verticalLayout_4->addLayout(horizontalLayout_2);

        m_groupBox_mode = new QGroupBox(m_widget_EFS);
        m_groupBox_mode->setObjectName(QString::fromUtf8("m_groupBox_mode"));
        m_groupBox_mode->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(m_groupBox_mode);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_radioButton_beat = new QRadioButton(m_groupBox_mode);
        m_radioButton_beat->setObjectName(QString::fromUtf8("m_radioButton_beat"));
        m_radioButton_beat->setCheckable(true);
        m_radioButton_beat->setChecked(false);

        verticalLayout_2->addWidget(m_radioButton_beat);

        m_radioButton_form = new QRadioButton(m_groupBox_mode);
        m_radioButton_form->setObjectName(QString::fromUtf8("m_radioButton_form"));

        verticalLayout_2->addWidget(m_radioButton_form);


        verticalLayout_4->addWidget(m_groupBox_mode);

        m_groupBox_vid = new QGroupBox(m_widget_EFS);
        m_groupBox_vid->setObjectName(QString::fromUtf8("m_groupBox_vid"));
        m_groupBox_vid->setAlignment(Qt::AlignCenter);
        verticalLayout_3 = new QVBoxLayout(m_groupBox_vid);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_radioButton_norm = new QRadioButton(m_groupBox_vid);
        m_radioButton_norm->setObjectName(QString::fromUtf8("m_radioButton_norm"));
        m_radioButton_norm->setCheckable(true);
        m_radioButton_norm->setChecked(false);

        verticalLayout_3->addWidget(m_radioButton_norm);

        m_radioButton_pathology = new QRadioButton(m_groupBox_vid);
        m_radioButton_pathology->setObjectName(QString::fromUtf8("m_radioButton_pathology"));

        verticalLayout_3->addWidget(m_radioButton_pathology);


        verticalLayout_4->addWidget(m_groupBox_vid);

        m_listView_diogram = new QListView(m_widget_EFS);
        m_listView_diogram->setObjectName(QString::fromUtf8("m_listView_diogram"));

        verticalLayout_4->addWidget(m_listView_diogram);


        verticalLayout->addWidget(m_widget_EFS);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        formLayout_2->setWidget(0, QFormLayout::LabelRole, m_widget_navi);

        widget = new QWidget(Tratining_Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, widget);


        retranslateUi(Tratining_Form);

        QMetaObject::connectSlotsByName(Tratining_Form);
    } // setupUi

    void retranslateUi(QWidget *Tratining_Form)
    {
        Tratining_Form->setWindowTitle(QCoreApplication::translate("Tratining_Form", "Form", nullptr));
        m_pushButton_ekg->setText(QCoreApplication::translate("Tratining_Form", "\320\255\320\232\320\223", nullptr));
        m_pushButton_emg->setText(QCoreApplication::translate("Tratining_Form", "\320\255\320\234\320\223", nullptr));
        m_pushButton_eeg->setText(QCoreApplication::translate("Tratining_Form", "\320\255\320\255\320\223", nullptr));
        m_groupBox_mode->setTitle(QCoreApplication::translate("Tratining_Form", "\320\240\320\265\320\266\320\270\320\274", nullptr));
        m_radioButton_beat->setText(QCoreApplication::translate("Tratining_Form", "\320\240\320\270\321\202\320\274", nullptr));
        m_radioButton_form->setText(QCoreApplication::translate("Tratining_Form", "\320\244\320\276\321\200\320\274\320\260", nullptr));
        m_groupBox_vid->setTitle(QCoreApplication::translate("Tratining_Form", "\320\222\320\270\320\264", nullptr));
        m_radioButton_norm->setText(QCoreApplication::translate("Tratining_Form", "\320\235\320\276\321\200\320\274\320\260 ", nullptr));
        m_radioButton_pathology->setText(QCoreApplication::translate("Tratining_Form", "\320\237\320\260\321\202\320\276\320\273\320\276\320\263\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tratining_Form: public Ui_Tratining_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRATINING_FORM_H
