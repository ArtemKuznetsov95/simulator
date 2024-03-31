#include "level12.h"

level12::level12(QWidget *parent) :
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
level12::~level12()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level12::getMapAnswer()
{
    return m_mapAnswer;
}

int level12::getResult()
{
    return m_result;
}

QString level12::getQuestion()
{
    return m_nameQuestin;
}

void level12::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGPathologies1();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
    widget_plot->xAxis->setLabel(trUtf8("t,с"));
    widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level12::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(1, "альфа");
    m_mapAnswer.insert(2, "дельта");
    m_mapAnswer.insert(3, "тетта");
}

void level12::createQuestion()
{
    m_nameQuestin = "Укажите ритм (0,5 – 4 Гц) сигнала ЭЭГ, представленного на рисунке:";
}
