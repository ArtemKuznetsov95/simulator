#ifndef SERVISE_PLOT_H
#define SERVISE_PLOT_H

#include <src/Utilities/qcustomplot.h>
#include <src/Diograms/Diograms_Data/diograms_data.h>
#include <src/Diograms/Diograms_Fun/diograms_fun.h>
#include <src/Diograms/Enum/listdata.h>
#include <QObject>
#include <QWidget>

class Servise_plot : public QWidget
{
public:
    Servise_plot(QWidget* parent = 0);

    void  sl_showPlot(bool metka);

    void sl_showPlot_DiogramEKG(ListData::DiogramEKG type);
    void sl_showPlot_DiogramEMG(ListData::DiogramEMG type);
    void sl_showPlot_DiogramEEG(ListData::DiogramEEG type);

private:
    void show_DiogramEKG_BEAT_Norm();
    void show_DiogramEKG_BEAT_Patology1();
    void show_DiogramEKG_BEAT_Patology2();
    void show_DiogramEKG_BEAT_Patology3();
    void show_DiogramEKG_BEAT_Patology4();
    void show_DiogramEKG_BEAT_Patology5();

    void show_DiogramEKG_FORM_Norm();
    void show_DiogramEKG_FORM_Patology6();
    void show_DiogramEKG_FORM_Patology7();
    void show_DiogramEKG_FORM_Patology8();


    void show_DiogramEMG_Norm();
    void show_DiogramEMG_Patology1();
    void show_DiogramEMG_Patology2();

    void show_DiogramEEG_Norm_1();
    void show_DiogramEEG_Norm_2();
    void show_DiogramEEG_Norm_3();
    void show_DiogramEEG_Norm_4();
    void show_DiogramEEG_Norm_5();

    void show_DiogramEEG_Patology1();
    void show_DiogramEEG_Patology2();
    void show_DiogramEEG_Patology3();
    void show_DiogramEEG_Patology4();
    void show_DiogramEEG_Patology5();
    void show_DiogramEEG_Patology6();

private:
    QStackedWidget* m_stackWidget;
    QCustomPlot* plot;
    _data_pqrst_ data_pqrst;
    QVector<_data_pqrst_> v_data_pqrst;
    QVBoxLayout* vbl;
};

#endif // SERVISE_PLOT_H
