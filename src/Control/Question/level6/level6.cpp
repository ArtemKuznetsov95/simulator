#include "level6.h"

level6::level6(QWidget *parent) :
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
level6::~level6()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level6::getMapAnswer()
{
    return m_mapAnswer;
}

int level6::getResult()
{
    return m_result;
}

QString level6::getQuestion()
{
    return m_nameQuestin;
}

void level6::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies5();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
}

void level6::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(1, "нормального ритма");
    m_mapAnswer.insert(2, "тахикардии");
    m_mapAnswer.insert(3, "брадикардии");
}

void level6::createQuestion()
{
    m_nameQuestin = "На рисунке представлена длительность межимпульсовых интервалов R-R на ЭКГ в виде___________";
}
