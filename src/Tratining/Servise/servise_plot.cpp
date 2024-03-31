#include "servise_plot.h"

Servise_plot::Servise_plot(QWidget *parent) :
    QWidget(parent),
    m_stackWidget(new QStackedWidget)
//    plot(new QCustomPlot)
{
    vbl = new QVBoxLayout();
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlot()));

    QHBoxLayout *hbox = new QHBoxLayout;
    sliderX0 = new QSlider(Qt::Horizontal);
    sliderX = new QSlider(Qt::Horizontal);
//    hbox->addWidget(slider);

    vbl->addWidget(plot);
    vbl->addWidget(sliderX0);
    vbl->addWidget(sliderX);

    setLayout(vbl);


    connect(sliderX,SIGNAL(valueChanged(int)),this,SLOT(plotX(int)));
    connect(sliderX0,SIGNAL(valueChanged(int)),this,SLOT(plotX0(int)));
}



void Servise_plot::sl_showPlot_DiogramEKG(ListData::DiogramEKG type)
{
    switch (type) {
    case ListData::EKG_NORM:
        show_DiogramEKG_BEAT_Norm();
        break;
    case ListData::EKG_NORM_2:
        show_DiogramEKG_FORM_Norm();
        break;
    case ListData::EKG_PATOLOGY1:
        show_DiogramEKG_BEAT_Patology1();
        break;
    case ListData::EKG_PATOLOGY2:
        show_DiogramEKG_BEAT_Patology2();
        break;
    case ListData::EKG_PATOLOGY3:
        show_DiogramEKG_BEAT_Patology3();
        break;
    case ListData::EKG_PATOLOGY4:
        show_DiogramEKG_BEAT_Patology4();
        break;
    case ListData::EKG_PATOLOGY5:
        show_DiogramEKG_BEAT_Patology5();
        break;
    case ListData::EKG_PATOLOGY6:
        show_DiogramEKG_FORM_Patology6();
        break;
    case ListData::EKG_PATOLOGY7:
        show_DiogramEKG_FORM_Patology7();
        break;
    case ListData::EKG_PATOLOGY8:
        show_DiogramEKG_FORM_Patology8();
        break;
    }
}

void Servise_plot::sl_showPlot_DiogramEMG(ListData::DiogramEMG type)
{
    switch (type) {
    case ListData::EMG_NORM:
        show_DiogramEMG_Norm();
        break;
    case ListData::EMG_PATOLOGY1:
        show_DiogramEMG_Patology1();
        break;
    case ListData::EMG_PATOLOGY2:
        show_DiogramEMG_Patology2();
        break;
    }
}

void Servise_plot::sl_showPlot_DiogramEEG(ListData::DiogramEEG type)
{
    switch (type) {
    case ListData::EEG_NORM_1:
        show_DiogramEEG_Norm_1();
        break;
    case ListData::EEG_NORM_2:
        show_DiogramEEG_Norm_2();
        break;
    case ListData::EEG_NORM_3:
        show_DiogramEEG_Norm_3();
        break;
    case ListData::EEG_NORM_4:
        show_DiogramEEG_Norm_4();
        break;
    case ListData::EEG_NORM_5:
        show_DiogramEEG_Norm_5();
        break;
    case ListData::EEG_PATOLOGY1:
        show_DiogramEEG_Patology1();
        break;
    case ListData::EEG_PATOLOGY2:
        show_DiogramEEG_Patology2();
        break;
    case ListData::EEG_PATOLOGY3:
        show_DiogramEEG_Patology3();
        break;
    case ListData::EEG_PATOLOGY4:
        show_DiogramEEG_Patology4();
        break;
    case ListData::EEG_PATOLOGY5:
        show_DiogramEEG_Patology5();
        break;
    case ListData::EEG_PATOLOGY6:
        show_DiogramEEG_Patology6();
        break;
    }
}

void Servise_plot::plotX(int value)
{
    valueSlider = value;
    plot->xAxis->setRange(0.01 * sliderX0->value(), 0.01 * value, Qt::AlignLeft);
    if (isPlay) plot->replot();
        else changeSig();
}

void Servise_plot::plotX0(int value)
{
    plot->xAxis->setRange(0.01 * value, 0.01 * sliderX->value(), Qt::AlignLeft);
    if (isPlay) plot->replot();
    else changeSig();
}

void Servise_plot::startGen(bool in)
{
    it = sliderX0->value();
    if(isPlay) {
        pointsXg = pointsX;
        pointsYg = pointsY;
    }
#ifdef ANDROID
    if (in) timer->start(100);
#else
    if (in) timer->start(10);
#endif
    else timer->stop();
}

void Servise_plot::setIsPlay(bool in)
{
    isPlay = in;
    sliderX0->setValue(0);
    if (in) {
        playPlot();
    } else {
        changeSig();
    }
}

void Servise_plot::playPlot()
{
    int i = 0;
    double x_visible = data[i].pointsX.count() / data[i].data_frec;
    sliderX->setMaximum(x_visible * 100 + 0.1 - sliderX0->value());
    sliderX0->setMaximum(x_visible * 100 + 0.1 - sliderX->value());

    double amp_min = 0;
    double amp_max = 0;
    for (int k = 0; k < data[i].pointsY.size(); k++){
        double amp_i = data[i].pointsY.at(k);
        if (amp_i > amp_max) amp_max = amp_i;
        if (amp_i < amp_min) amp_min = amp_i;
        if (!amp_min) amp_min = amp_max;
        if (!amp_max) amp_max = amp_min;
    }
    double amp_dif = amp_max - amp_min;
    amp_min -= 0.1 * amp_dif;
    amp_dif *= 1.2;

    plot->yAxis->setRange(amp_min, amp_dif, Qt::AlignLeft);

    plot->graph(0)->setData(data[i].pointsX, data[i].pointsY);
    plot->replot();
}

void Servise_plot::updatePlot()
{

    if (isPlay) {
        sliderX0->setValue(it);
    } else {
        plot->xAxis->setRange(0.01 * it, 0.01 * sliderX->value(), Qt::AlignLeft);
        plot->graph(0)->setData(pointsXg, pointsYg);
        plot->replot();

#ifdef ANDROID
        int N = 250;
        int k = 25;
#else
        int N = 1000;
        int k = 10;
#endif
        double dx = (double)1/N;
        for (int i=0;i<k;i++) {
            pointsXg.append(pointsXg.last() + dx);
            pointsXg.removeFirst();
            pointsYg.append(pointsYg.first());
            pointsYg.removeFirst();
        }
    }
#ifdef ANDROID
    it = it + 10;
#else
    it++;
#endif
}

void Servise_plot::changeSig()
{
    double amp_min = 0;
    double amp_max = 1.1;
    double x_visible = 5;

    for (int k = 0; k < pointsY.size(); k++){
        double amp_i = pointsY.at(k);
        if (amp_i > amp_max) amp_max = amp_i;
        if (amp_i < amp_min) amp_min = amp_i;
        if (!amp_min) amp_min = amp_max;
        if (!amp_max) amp_max = amp_min;
    }

    x_visible = v_data_pqrst.last().end;
    int x_vis = x_visible * 100 + 0.1;
    if (sliderX0->value() >= x_vis) sliderX0->setValue(0);
    int x_max = x_vis - sliderX0->value();
    if (sliderX->value() > x_max) sliderX->setValue(x_max);
    sliderX->setMaximum(x_max);
    sliderX0->setMaximum(x_visible * 100 + 0.1 - sliderX->value());

    double amp_dif = amp_max - amp_min;
    amp_min -= 0.1 * amp_dif;
    amp_dif *= 1.2;
    plot->yAxis->setRange(amp_min, amp_dif, Qt::AlignLeft);
    plot->xAxis->setRange(0.01 * sliderX0->value(), 0.01 * sliderX->value(), Qt::AlignLeft);

    plot->graph(0)->setData(pointsX, pointsY);
    plot->replot();

}

void Servise_plot::show_DiogramEKG_BEAT_Norm()
{
    //Норма ритм
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGNorm();
//    diograms_Fun::fun_control(plot, v_data_pqrst);

    diograms_Fun::fun_play(plot, v_data_pqrst, pointsX, pointsY);

}

void Servise_plot::show_DiogramEKG_BEAT_Patology1()
{
    //Фибрилляция желудочков++++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies4();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_BEAT_Patology2()
{
    //Тахикардии+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies6();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_BEAT_Patology3()
{
    //Брадикардии+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies7();
    diograms_Fun::fun_control(plot, v_data_pqrst);

}

void Servise_plot::show_DiogramEKG_BEAT_Patology4()
{
    //Бигемения
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies8();
    diograms_Fun::fun_traning(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_BEAT_Patology5()
{
    //Одиночная экстраситола++++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies9();
    diograms_Fun::fun_control(plot, v_data_pqrst);

    double x_begin = 0.75;
    double y = 0.29;
    double x_end = 2.3;
    double h = - 0.15;

    createItemLine(x_begin, x_end, y + h, "КП");
    createItemLineDashLine(y, y + h, x_begin);
    createItemLineDashLine(y, y + h, x_end);
}

void Servise_plot::show_DiogramEKG_FORM_Norm()
{
    //норма в форма ++++
    delete plot;
    pointsX.clear();
    pointsY.clear();
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    vbl->addWidget(plot);
    vbl->insertWidget(0, plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies5();
//    diograms_Fun::fun_control(plot, v_data_pqrst);


    diograms_Fun::fun_play(plot, v_data_pqrst, pointsX, pointsY);

}

void Servise_plot::show_DiogramEKG_FORM_Patology6()
{
    //Гипертрофия левого предсердия +++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies1();
    diograms_Fun::fun_traning(plot, v_data_pqrst);

    createItemText(0.19, 0.4, "P mitral");
}

void Servise_plot::show_DiogramEKG_FORM_Patology7()
{
    //Ишемическая болезнь сердца+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies2();
    diograms_Fun::fun_traning(plot, v_data_pqrst);

    createItemText(0.4, 0.23, "ST");
    createItemText(0.52, 0.12, "T");
}

void Servise_plot::show_DiogramEKG_FORM_Patology8()
{
    //Признаков инфаркта миокарда+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies3();
    diograms_Fun::fun_traning(plot, v_data_pqrst);

    createItemText(0.27, -0.1, "Q");
}

void Servise_plot::show_DiogramEMG_Norm()
{

    //ЭМГ в норме+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies10();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEMG_Patology1()
{
//    //При тяжелом парезе мышц после полиомелита+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEMGPathologies1();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEMG_Patology2()
{
//    //При паркинсоническом дрожании и ригидном повышении тонуса+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEMGPathologies2();
    diograms_Fun::fun_control(plot, v_data_pqrst);

}

void Servise_plot::show_DiogramEEG_Norm_1()
{
//"Альфа-ритм, 8-13 ГЦ"+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGNorm_1();
    diograms_Fun::fun_control(plot, v_data_pqrst);

}

void Servise_plot::show_DiogramEEG_Norm_2()
{
//"Бета-ритм 14-30 ГЦ"+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGNorm_2();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Norm_3()
{
//"Тетра-ритм, 4-7 ГЦ"+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGNorm_3();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Norm_4()
{
//"Гамма-ритм, 30-60 ГЦ"
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGNorm_4();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Norm_5()
{
    //"Дельта-ритмб 0.5-4 ГЦ"+++
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGPathologies1();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Patology1()
{
    //"Гамма-ритм. Спайки"
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGPathologies_1();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Patology2()
{
    //"Гамма-ритм. Острые волны"
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGPathologies_2();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Patology3()
{
    //"Гамма-ритм. Острые волны в полосе"
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGPathologies_3();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Patology4()
{
    //"Гамма-ритм. Срайки-волна"
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGPathologies_4();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Patology5()
{
    //"Гамма-ритм. Множественные спайки-волна"
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGPathologies_5();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Patology6()
{
    //"Гамма-ритм. Острая волна-медленная волна"
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::red));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataEEGPathologies_6();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::createItemLine(double begin, double end, double y, QString name)
{
    // Создание линий отрезка
    QCPItemLine *line1 = new QCPItemLine(plot);
    QCPItemLine *line2 = new QCPItemLine(plot);
    double l1_x1 = begin;
    double l_y = y;
    double l_centr = end - begin;
    double l1_x2 = end;

    double arrowLength = 0.03;
    double arrowAngle = 0.2;
    // Установка координат начала и конца отрезка
    line1->start->setCoords(l1_x1, l_y);
    line1->end->setCoords(l_centr, l_y);
    line2->start->setCoords(l_centr, l_y);
    line2->end->setCoords(l1_x2, l_y);

    // Создание линий для стрелок
    QCPItemLine *arrow1 = new QCPItemLine(plot);
    QCPItemLine *arrow2 = new QCPItemLine(plot);

    // Установка координат для линий стрелок НАЧАЛО
    arrow1->start->setCoords(l1_x1, l_y);
    arrow1->end->setCoords(l1_x1 + arrowLength * cos(arrowAngle), l_y + arrowLength * sin(arrowAngle));

    arrow2->start->setCoords(l1_x1, l_y);
    arrow2->end->setCoords(l1_x1 + arrowLength * cos(-arrowAngle), l_y + arrowLength * sin(-arrowAngle));


    // Создание линий для стрелок
    QCPItemLine *arrow3 = new QCPItemLine(plot);
    QCPItemLine *arrow4 = new QCPItemLine(plot);

    // Установка координат для линий стрелок КОНЕЦ
    arrow3->start->setCoords(l1_x2, l_y);
    arrow3->end->setCoords(l1_x2 - arrowLength * cos(arrowAngle), l_y + arrowLength * sin(arrowAngle));

    arrow4->start->setCoords(l1_x2, l_y);
    arrow4->end->setCoords(l1_x2 - arrowLength * cos(-arrowAngle), l_y + arrowLength * sin(-arrowAngle));

    if(!name.isEmpty()) {
        // Установка стиля и цвета линий
        line1->setPen(QPen(Qt::black));
        QCPItemText *wavePacketText = new QCPItemText(plot);
        wavePacketText->position->setParentAnchor(line1->end);
        wavePacketText->position->setCoords(0, 10); // move 10 pixels to the top from bracket center anchor
        wavePacketText->setPositionAlignment(Qt::AlignRight|Qt::AlignHCenter);
        wavePacketText->setText(name);
        wavePacketText->setFont(QFont(font().family(), 10));
    }
}

void Servise_plot::createItemLineDashLine(double begin, double end, double x)
{
    QCPItemLine *line1 = new QCPItemLine(plot);
    line1->start->setCoords(x, begin);
    line1->end->setCoords(x, end - 0.03);

    QPen pen;
    pen.setStyle(Qt::DashLine); // Установка стиля прерывистой линии
    pen.setColor(Qt::black); // Установка цвета линии
    line1->setPen(pen);
}

void Servise_plot::createItemText(double X, double Y, QString name)
{
    QCPItemText *wavePacketText = new QCPItemText(plot);
    wavePacketText->position->setCoords(X, Y); // move 10 pixels to the top from bracket center anchor
    wavePacketText->setPositionAlignment(Qt::AlignRight|Qt::AlignHCenter);
    wavePacketText->setText(name);
    wavePacketText->setFont(QFont(font().family(), 10));
}

