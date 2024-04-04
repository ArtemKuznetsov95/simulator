#include "level1_form.h"
#include "ui_level1_form.h"

level1_Form::level1_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level1_Form)
{
    ui->setupUi(this);

    createAnswer();
    createQuestion();
    createPlot();
}

level1_Form::~level1_Form()
{
    delete ui;
}

QMap<int, QString> level1_Form::getMapAnswer()
{
    return m_mapAnswer;
}

int level1_Form::getResult()
{
    return m_result;
}

QString level1_Form::getQuestion()
{
    return m_nameQuestin;
}

void level1_Form::createPlot()
{
    ui->widget_plot->addGraph();
    ui->widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGNorm();
    diograms_Fun::fun_control(ui->widget_plot, v_data_pqrst);
    ui->widget_plot->xAxis->setLabel(trUtf8("t,с"));
    ui->widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level1_Form::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(0, "в норме");
    m_mapAnswer.insert(1, "с областями инфаркта миокарда");
    m_mapAnswer.insert(2, "с гипертрофией желудочков");
}

void level1_Form::createQuestion()
{
    m_nameQuestin = "На рисунке представлен график электрокардиограммы___________";
}
