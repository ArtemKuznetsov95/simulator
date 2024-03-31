#include "level10.h"

level10::level10(QWidget *parent) :
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
level10::~level10()
{
//    delete ui;
    delete widget_plot;
}

QMap<int, QString> level10::getMapAnswer()
{
    return m_mapAnswer;
}

int level10::getResult()
{
    return m_result;
}

QString level10::getQuestion()
{
    return m_nameQuestin;
}

void level10::createPlot()
{
    widget_plot->addGraph();
    widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies9();
    diograms_Fun::fun_control(widget_plot, v_data_pqrst);
    widget_plot->xAxis->setLabel(trUtf8("t,с"));
    widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level10::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(1, "бигемения");
    m_mapAnswer.insert(2, "одиночная экстраситола");
    m_mapAnswer.insert(3, "выпадение кардиоцикла");
}

void level10::createQuestion()
{
    m_nameQuestin = "Вид нарушения ритма на рисунке – это___________ ";
}
