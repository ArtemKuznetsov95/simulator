#include "level3_form.h"
#include "ui_level3_form.h"

level3_Form::level3_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level3_Form)
{
    ui->setupUi(this);

    createAnswer();
    createQuestion();
    createPlot();
}

level3_Form::~level3_Form()
{
    delete ui;
}

QMap<int, QString> level3_Form::getMapAnswer()
{
    return m_mapAnswer;
}

int level3_Form::getResult()
{
    return m_result;
}

QString level3_Form::getQuestion()
{
    return m_nameQuestin;
}

void level3_Form::createPlot()
{
    ui->widget_plot->addGraph();
    ui->widget_plot->graph(0)->setPen(QPen(Qt::blue));
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies2();
    diograms_Fun::fun_control(ui->widget_plot, v_data_pqrst);
    ui->widget_plot->xAxis->setLabel(trUtf8("t,с"));
    ui->widget_plot->yAxis->setLabel(trUtf8("U,мВ"));
}

void level3_Form::createAnswer()
{
    m_mapAnswer.clear();
    m_mapAnswer.insert(0, "инфаркта миокарда");
    m_mapAnswer.insert(1, "ишемическая болезнь сердца");
    m_mapAnswer.insert(2, "гипертрофия левого предсердия");
}

void level3_Form::createQuestion()
{
    m_nameQuestin = "Укажите вид патологии на изображении кардиоцикла:";
}

