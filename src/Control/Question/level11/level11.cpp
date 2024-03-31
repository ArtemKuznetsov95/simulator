#include "level11.h"

level11::level11(QWidget *parent) :
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
level11::~level11()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level11::getMapAnswer()
{
    return m_mapAnswer;
}

int level11::getResult()
{
    return m_result;
}

QString level11::getQuestion()
{
    return m_nameQuestin;
}

void level11::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies10();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
    widget_plot->xAxis->setLabel(trUtf8("t,с"));
    widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level11::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(1, "электрокардиограмма");
    m_mapAnswer.insert(2, "эдектроэнцефалограмма");
    m_mapAnswer.insert(3, "электромиограмма");
}

void level11::createQuestion()
{
    m_nameQuestin = "Укажите вид сигнала, представленного на рисунке: ";
}
