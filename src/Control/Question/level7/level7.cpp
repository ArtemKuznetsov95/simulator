#include "level7.h"

level7::level7(QWidget *parent) :
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
level7::~level7()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level7::getMapAnswer()
{
    return m_mapAnswer;
}

int level7::getResult()
{
    return m_result;
}

QString level7::getQuestion()
{
    return m_nameQuestin;
}

void level7::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies6();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
    widget_plot->xAxis->setLabel(trUtf8("t,с"));
    widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level7::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(1, "нормального ритма");
    m_mapAnswer.insert(2, "тахикардии");
    m_mapAnswer.insert(3, "брадикардии");
}

void level7::createQuestion()
{
    m_nameQuestin = "На рисунке представлена длительность межимпульсовых интервалов R-R на ЭКГ в виде___________ ";
}
