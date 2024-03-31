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
    Q_OBJECT
public:
    Servise_plot(QWidget* parent = 0);

//    void  sl_showPlot(bool metka);

    void sl_showPlot_DiogramEKG(ListData::DiogramEKG type);
    void sl_showPlot_DiogramEMG(ListData::DiogramEMG type);
    void sl_showPlot_DiogramEEG(ListData::DiogramEEG type);

public slots:
    void plotX(int value);
    void plotX0(int value);

    void startGen(bool in);
    void setIsPlay(bool in);
    void playPlot();

private:
    void updatePlot();
    void changeSig();


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

    void createItemLine(double begin, double end, double y, QString name = 0);
    void createItemLineDashLine(double begin, double end, double x);
    void createItemText(double X, double Y, QString name);



private:
    QStackedWidget* m_stackWidget;
    QCustomPlot* plot;
    _data_pqrst_ data_pqrst;
    QVector<_data_pqrst_> v_data_pqrst;
    QVBoxLayout* vbl;

    QSlider* sliderX0;
    QSlider* sliderX;

    struct Data {
        QVector <double> pointsX;
        QVector <double> pointsY;
        int data_frec;
        double data_max;
        double data_min;
    } d;
    QVector <struct Data> data;
    QVector <double> pointsX, pointsY;
    QVector <double> pointsXg, pointsYg;
    int it;
    QTimer *timer;
    bool isPlay = false;
    int valueSlider = 0;
};

#endif // SERVISE_PLOT_H
