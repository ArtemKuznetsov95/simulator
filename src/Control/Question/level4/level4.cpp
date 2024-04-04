#include "level4.h"

level4::level4(QWidget *parent) :
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
level4::~level4()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level4::getMapAnswer()
{
    return m_mapAnswer;
}

int level4::getResult()
{
    return m_result;
}

QString level4::getQuestion()
{
    return m_nameQuestin;
}

void level4::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies3();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
    widget_plot->xAxis->setLabel(trUtf8("t,с"));
    widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level4::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(0, "признаков инфаркта миокарда");
    m_mapAnswer.insert(1, "признаков гипертрофии желудочков");
    m_mapAnswer.insert(2, "блокады ножек пучка Гиса");
}

void level4::createQuestion()
{
    m_nameQuestin = "На рисунке представлен сигнал ЭКГ с патологией в виде___________";
}
