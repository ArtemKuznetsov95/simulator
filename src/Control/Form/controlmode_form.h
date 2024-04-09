#ifndef CONTROLMODE_FORM_H
#define CONTROLMODE_FORM_H

#include <QWidget>
#include <Control/Question/QuestionPattern/questionpattern_form.h>
#include <QMessageBox>

class QuestionPattern_Form;

namespace Ui {
class ControlMode_Form;
}

class ControlMode_Form : public QWidget
{
    Q_OBJECT

public:
    explicit ControlMode_Form(QWidget *parent = nullptr);
    ~ControlMode_Form();

    void initRules();

public slots:
    bool getStart();

private slots:
    void initTest();
    void initResults();

    void on_m_pushButton_start_clicked();

    void on_m_pushButton_next_clicked();

    void on_m_pushButton_restart_clicked();

private:
    Ui::ControlMode_Form *ui;
    QuestionPattern_Form* m_questionPattern;
    int m_countQuestion = 12;
    int n_countPassed = 1;
    int m_countAnswers = 0;
    int m_countBall = 0;

    bool isStart = false;
};

#endif // CONTROLMODE_FORM_H
