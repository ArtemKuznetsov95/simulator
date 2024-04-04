#include "level9.h"

level9::level9(QWidget *parent) :
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
level9::~level9()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level9::getMapAnswer()
{
    return m_mapAnswer;
}

int level9::getResult()
{
    return m_result;
}

QString level9::getQuestion()
{
    return m_nameQuestin;
}

void level9::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies8();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
    widget_plot->xAxis->setLabel(trUtf8("t,с"));
    widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level9::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(0, "бигемения");
    m_mapAnswer.insert(1, "тригемения");
    m_mapAnswer.insert(2, "квадригемения");
}

void level9::createQuestion()
{
    m_nameQuestin = "Вид нарушения ритма на рисунке – это ___________ ";
}
