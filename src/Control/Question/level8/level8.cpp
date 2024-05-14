#include "level8.h"

level8::level8(QWidget *parent) :
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
level8::~level8()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level8::getMapAnswer()
{
    return m_mapAnswer;
}

int level8::getResult()
{
    return m_result;
}

QString level8::getQuestion()
{
    return m_nameQuestin;
}

void level8::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies7();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
    widget_plot->xAxis->setLabel("t,с");
    widget_plot->yAxis->setLabel("U,мВ");
}

void level8::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(0, "нормального ритма");
    m_mapAnswer.insert(1, "тахикардии");
    m_mapAnswer.insert(2, "брадикардии");
}

void level8::createQuestion()
{
    m_nameQuestin = "На рисунке представлена длительность межимпульсовых интервалов R-R на ЭКГ в виде___________ ";
}
