#include "servise_plot.h"

Servise_plot::Servise_plot(QWidget *parent) :
    QWidget(parent),
    m_stackWidget(new QStackedWidget)
//    plot(new QCustomPlot)
{
    vbl = new QVBoxLayout();
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);

    setLayout(vbl);
}

void Servise_plot::sl_showPlot(bool metka)
{
    if(metka){
        delete plot;
        plot = new QCustomPlot(this);
        plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        vbl->addWidget(plot);
        plot->addGraph();
        plot->graph(0)->setPen(QPen(Qt::blue));
        plot->axisRect()->setupFullAxesBox(true);
        v_data_pqrst.clear();
        v_data_pqrst = Diograms_Data::getDataECGNorm();
        diograms_Fun::fun_control(plot, v_data_pqrst);

//        plot->show();
    }
    else {
        delete plot;
        plot = new QCustomPlot(this);
        vbl->addWidget(plot);
        plot->addGraph();
        plot->graph(0)->setPen(QPen(Qt::blue));
        plot->axisRect()->setupFullAxesBox(true);
        v_data_pqrst.clear();
        v_data_pqrst = Diograms_Data::getDataECGPathologies1();
        diograms_Fun::fun_control(plot, v_data_pqrst);
    }
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
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_BEAT_Patology1()
{
    //Фибрилляция желудочков
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies4();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_BEAT_Patology2()
{
    //Тахикардии
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies6();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_BEAT_Patology3()
{
    //Брадикардии
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
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
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies8();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_BEAT_Patology5()
{
    //Одиночная экстраситола
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
}

void Servise_plot::show_DiogramEKG_FORM_Norm()
{
    //норма в форма
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies5();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_FORM_Patology6()
{
    //Гипертрофия левого предсердия
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies1();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_FORM_Patology7()
{
    //Ишемическая болезнь сердца
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies2();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEKG_FORM_Patology8()
{
    //Признаков инфаркта миокарда
    delete plot;
    plot = new QCustomPlot(this);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbl->addWidget(plot);
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->axisRect()->setupFullAxesBox(true);
    v_data_pqrst.clear();
    v_data_pqrst = Diograms_Data::getDataECGPathologies3();
    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEMG_Norm()
{

    //ЭМГ в норме
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
//    //При тяжелом парезе мышц после полиомелита
//    delete plot;
//    plot = new QCustomPlot(this);
//    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    vbl->addWidget(plot);
//    plot->addGraph();
//    plot->graph(0)->setPen(QPen(Qt::blue));
//    plot->axisRect()->setupFullAxesBox(true);
//    v_data_pqrst.clear();
////    v_data_pqrst = Diograms_Data::getDataECGPathologies3();
//    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEMG_Patology2()
{
//    //При паркинсоническом дрожании и ригидном повышении тонуса
//    delete plot;
//    plot = new QCustomPlot(this);
//    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    vbl->addWidget(plot);
//    plot->addGraph();
//    plot->graph(0)->setPen(QPen(Qt::blue));
//    plot->axisRect()->setupFullAxesBox(true);
//    v_data_pqrst.clear();
////    v_data_pqrst = Diograms_Data::getDataECGPathologies3();
//    diograms_Fun::fun_control(plot, v_data_pqrst);
}

void Servise_plot::show_DiogramEEG_Norm_1()
{
//"Альфа-ритм, 8-13 ГЦ"
}

void Servise_plot::show_DiogramEEG_Norm_2()
{
//"Бета-ритмб 14-30 ГЦ"
}

void Servise_plot::show_DiogramEEG_Norm_3()
{
//"Тетра-ритм, 4-7 ГЦ"
}

void Servise_plot::show_DiogramEEG_Norm_4()
{
//"Гамма-ритм, 30-60 ГЦ"
}

void Servise_plot::show_DiogramEEG_Norm_5()
{
    //"Дельта-ритмб 0.5-4 ГЦ"
}

void Servise_plot::show_DiogramEEG_Patology1()
{
    //"Гамма-ритм. Спайки"
}

void Servise_plot::show_DiogramEEG_Patology2()
{
    //"Гамма-ритм. Острые волны"
}

void Servise_plot::show_DiogramEEG_Patology3()
{
    //"Гамма-ритм. Острые волны в полосе"

}

void Servise_plot::show_DiogramEEG_Patology4()
{
    //"Гамма-ритм. Срайки-волна"
}

void Servise_plot::show_DiogramEEG_Patology5()
{
    //"Гамма-ритм. Множественные спайки-волна"
}

void Servise_plot::show_DiogramEEG_Patology6()
{
    //"Гамма-ритм. Острая волна-медленная волна"
}

