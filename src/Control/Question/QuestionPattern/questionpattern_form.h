#ifndef QUESTIONPATTERN_FORM_H
#define QUESTIONPATTERN_FORM_H

#include <QWidget>
#include <QRandomGenerator>

#include <Control/Question/level1/level1_form.h>
#include <Control/Question/level2/level2_form.h>
#include <Control/Question/level3/level3_form.h>
#include <Control/Question/level4/level4.h>
#include <Control/Question/level5/level5.h>
#include <Control/Question/level6/level6.h>
#include <Control/Question/level7/level7.h>
#include <Control/Question/level8/level8.h>
#include <Control/Question/level9/level9.h>
#include <Control/Question/level10/level10.h>
#include <Control/Question/level11/level11.h>
#include <Control/Question/level12/level12.h>


namespace Ui {
class QuestionPattern_Form;
}

class QuestionPattern_Form : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionPattern_Form(QWidget *parent = nullptr);
    ~QuestionPattern_Form();

    void init();
    void randCurrentWidget();
    int randCurent();
    void randMapAnswer(QMap<int, QString> map);
    bool isWidget();

    bool checkAnswer();
    bool getAnswer();
    int getWidget();

signals:
    void si_checkRadioButton();

private:
    Ui::QuestionPattern_Form *ui;
    QSet<int> m_set_widget;
    QSet<int> m_selected_widget;
    QButtonGroup *buttonGroup;
    bool m_right = false;
    QString correctAnswer;
};

#endif // QUESTIONPATTERN_FORM_H
