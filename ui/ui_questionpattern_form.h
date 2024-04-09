/********************************************************************************
** Form generated from reading UI file 'questionpattern_form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONPATTERN_FORM_H
#define UI_QUESTIONPATTERN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionPattern_Form
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *m_stackedWidget;
    QLabel *m_label_question;
    QRadioButton *m_radioButton_1;
    QRadioButton *m_radioButton_2;
    QRadioButton *m_radioButton_3;

    void setupUi(QWidget *QuestionPattern_Form)
    {
        if (QuestionPattern_Form->objectName().isEmpty())
            QuestionPattern_Form->setObjectName(QString::fromUtf8("QuestionPattern_Form"));
        QuestionPattern_Form->resize(830, 567);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QuestionPattern_Form->sizePolicy().hasHeightForWidth());
        QuestionPattern_Form->setSizePolicy(sizePolicy);
        QuestionPattern_Form->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(QuestionPattern_Form);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_stackedWidget = new QStackedWidget(QuestionPattern_Form);
        m_stackedWidget->setObjectName(QString::fromUtf8("m_stackedWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_stackedWidget->sizePolicy().hasHeightForWidth());
        m_stackedWidget->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(m_stackedWidget);

        m_label_question = new QLabel(QuestionPattern_Form);
        m_label_question->setObjectName(QString::fromUtf8("m_label_question"));
        m_label_question->setStyleSheet(QString::fromUtf8("font: 75 13pt \"Ubuntu\";"));

        verticalLayout_2->addWidget(m_label_question);

        m_radioButton_1 = new QRadioButton(QuestionPattern_Form);
        m_radioButton_1->setObjectName(QString::fromUtf8("m_radioButton_1"));

        verticalLayout_2->addWidget(m_radioButton_1);

        m_radioButton_2 = new QRadioButton(QuestionPattern_Form);
        m_radioButton_2->setObjectName(QString::fromUtf8("m_radioButton_2"));

        verticalLayout_2->addWidget(m_radioButton_2);

        m_radioButton_3 = new QRadioButton(QuestionPattern_Form);
        m_radioButton_3->setObjectName(QString::fromUtf8("m_radioButton_3"));

        verticalLayout_2->addWidget(m_radioButton_3);


        retranslateUi(QuestionPattern_Form);

        QMetaObject::connectSlotsByName(QuestionPattern_Form);
    } // setupUi

    void retranslateUi(QWidget *QuestionPattern_Form)
    {
        QuestionPattern_Form->setWindowTitle(QCoreApplication::translate("QuestionPattern_Form", "Form", nullptr));
        m_label_question->setText(QCoreApplication::translate("QuestionPattern_Form", "\320\222\320\276\320\277\321\200\320\276\321\201", nullptr));
        m_radioButton_1->setText(QCoreApplication::translate("QuestionPattern_Form", "RadioButton", nullptr));
        m_radioButton_2->setText(QCoreApplication::translate("QuestionPattern_Form", "RadioButton", nullptr));
        m_radioButton_3->setText(QCoreApplication::translate("QuestionPattern_Form", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionPattern_Form: public Ui_QuestionPattern_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONPATTERN_FORM_H
