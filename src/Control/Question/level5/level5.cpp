#include "level5.h"

level5::level5(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* boxLayout = new QVBoxLayout;
    this->setLayout(boxLayout);
    widget_plot = new QCustomPlot;
    boxLayout->addWidget(widget_plot);
    createAnswer();
    createQuestion();
    createPlot();
}
level5::~level5()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level5::getMapAnswer()
{
    return m_mapAnswer;
}

int level5::getResult()
{
    return m_result;
}

QString level5::getQuestion()
{
    return m_nameQuestin;
}

void level5::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies4();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
    widget_plot->xAxis->setLabel(trUtf8("t,с"));
    widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level5::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(1, "экстрасистолия");
    m_mapAnswer.insert(2, "фибрилляция желудочков");
    m_mapAnswer.insert(3, "тахикардия");
}

void level5::createQuestion()
{
    m_nameQuestin = "Укажите вид патологии ритма на ЭКГ:";
}
