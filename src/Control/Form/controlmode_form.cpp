#include "controlmode_form.h"
#include "ui_controlmode_form.h"
#include <QVBoxLayout>

ControlMode_Form::ControlMode_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlMode_Form)
{
    ui->setupUi(this);
    m_questionPattern = new QuestionPattern_Form();
    auto vlb = new QVBoxLayout;
    ui->groupBox->setLayout(vlb);
    vlb->addWidget(m_questionPattern);

    initTest();

    connect(m_questionPattern, &QuestionPattern_Form::si_checkRadioButton, [this](){
        ui->m_label_eror->setVisible(false);
    });
}

ControlMode_Form::~ControlMode_Form()
{
    delete ui;

}

void ControlMode_Form::initRules()
{
    QString pules = "Правила:\n"
                    "Тест состоит из 12 вопросов. \n"
                    "В каждом вопросе только 1 (один) правильный ответ. \n"
                    "Время неограничено.\n\n"
                    "Чтобы начать тест нажмите кнопку \"Начать\"";

    ui->m_label->setText(pules);
}

bool ControlMode_Form::getStart()
{
    if(isStart) {
        auto result = QMessageBox::warning(this, "Предупреждение!", "Вы хотите завершить тестирования?", QMessageBox::Yes, QMessageBox::No);
        if(result == QMessageBox::No)
            return false;
    }
    isStart = false;
    initTest();
    return true;
}

void ControlMode_Form::initTest()
{
    //TODO начало теста
    //Запуск счетчика
    ui->m_widget_start->show();
    ui->m_widget_test->hide();
    ui->m_widget_result->hide();
    m_countAnswers = 0;
    m_countBall = 0;
    n_countPassed = 1;
    initRules();
    isStart = false;
}

void ControlMode_Form::initResults()
{
    int estimation = 1;
    m_countBall = (int)(m_countAnswers * 100/m_countQuestion);
    if(m_countBall > 85) {
        estimation = 5;
        if(m_countAnswers == 12)
            m_countBall = 100;
    } else if (m_countBall > 70) {
        estimation = 4;
    } else if (m_countBall > 50) {
        estimation = 3;
    } else
        estimation = 2;

    QString result = QString("Результат:\n"
                     "Правильных ответов - %1\n"
                     "Кол-во баллов - %2\n\n"
                     "Оценка - %3").arg(QString::number(m_countAnswers),
                                        QString::number(m_countBall),
                                        QString::number(estimation));

    ui->m_label_result->setText(result);

    isStart = false;
}

void ControlMode_Form::on_m_pushButton_start_clicked()
{
    m_questionPattern->init();

    ui->m_widget_test->show();
    ui->m_widget_start->hide();
    ui->m_label_eror->setVisible(false);
    m_countQuestion = m_questionPattern->getWidget();
    ui->label->setText(QString("%1/%2").arg(QString::number(n_countPassed),
                                            QString::number(m_countQuestion)));

    isStart = true;
}


void ControlMode_Form::on_m_pushButton_next_clicked()
{
    if(m_questionPattern->checkAnswer()) {

        if(m_questionPattern->getAnswer()) {
            m_countAnswers++;
        }
    } else {
        ui->m_label_eror->setVisible(true);
        return;
    }

    if(m_questionPattern->isWidget()) {
        m_questionPattern->randCurrentWidget();
        n_countPassed++;
        ui->label->setText(QString("%1/%2").arg(QString::number(n_countPassed),
                                                QString::number(m_countQuestion)));
    }
    else
    {
        ui->m_widget_test->hide();
        ui->m_widget_result->show();
        initResults();
    }
}


void ControlMode_Form::on_m_pushButton_restart_clicked()
{
    this->initTest();
}

