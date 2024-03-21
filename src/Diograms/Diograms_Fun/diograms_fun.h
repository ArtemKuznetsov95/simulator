#ifndef DIOGRAMS_FUN_H
#define DIOGRAMS_FUN_H

#include <qcustomplot.h>
#include <Diograms/Diograms_Data/diograms_data.h>

class diograms_Fun
{
public:
    diograms_Fun();

    static void fun_control(QCustomPlot* customplot, QVector<_data_pqrst_> data_pqrst);

    static void pqrstPlot(QVector<_data_pqrst_> v_data_pqrst, QVector<double> *pointsX, QVector<double> *pointsY);

};

#endif // DIOGRAMS_FUN_H
