#ifndef DIOGRAMS_DATA_H
#define DIOGRAMS_DATA_H

#include <QString>
#include <QVector>

struct _data_pqrst_ {
        _data_pqrst_() : sig(0),
            end(0),dur(0),
            amp(0),amp_shift(0),
            time_shift(0)
        {}
        int sig;
        double end;
        double dur;
        double amp;
        double amp_shift;
        double time_shift;
        QString name;
    } ;

class Diograms_Data
{
public:
    Diograms_Data();

    static QVector<_data_pqrst_> getDataECGNorm();
    static QVector<_data_pqrst_> getDataECGPathologies1();
    static QVector<_data_pqrst_> getDataECGPathologies2();
    static QVector<_data_pqrst_> getDataECGPathologies3();
    static QVector<_data_pqrst_> getDataECGPathologies4();
    static QVector<_data_pqrst_> getDataECGPathologies5();
    static QVector<_data_pqrst_> getDataECGPathologies6();
    static QVector<_data_pqrst_> getDataECGPathologies7();
    static QVector<_data_pqrst_> getDataECGPathologies8();
    static QVector<_data_pqrst_> getDataECGPathologies9();
    static QVector<_data_pqrst_> getDataECGPathologies10();

    static QVector<_data_pqrst_> getDataEEGPathologies1();

    static void createImpulse(QVector<_data_pqrst_>* data_pqrst_, double sec, int count);

};

#endif // DIOGRAMS_DATA_H
