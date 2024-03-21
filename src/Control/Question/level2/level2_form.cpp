#include "level2_form.h"
#include "ui_level2_form.h"

level2_Form::level2_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level2_Form)
{
    ui->setupUi(this);
    createAnswer();
    createQuestion();
    createPlot();
}

level2_Form::~level2_Form()
{
    delete ui;
}
QMap<int, QString> level2_Form::getMapAnswer()
{
    return m_mapAnswer;
}

int level2_Form::getResult()
{
    return m_result;
}

QString level2_Form::getQuestion()
{
    return m_nameQuestin;
}

void level2_Form::createPlot()
{
    ui->widget_plot->addGraph();
    ui->widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies1();
    diograms_Fun::fun_control(ui->widget_plot, v_data_pqrst);
}

void level2_Form::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(1, "в норме");
    m_mapAnswer.insert(2, "с областями инфаркта миокарда");
    m_mapAnswer.insert(3, "с гипертрофией левого предсердия");
}

void level2_Form::createQuestion()
{
    m_nameQuestin = "На рисунке представлен кардиоцикл___________";
}
