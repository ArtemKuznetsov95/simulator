#include "diograms_data.h"

Diograms_Data::Diograms_Data()
{

}

QVector<_data_pqrst_> Diograms_Data::getDataECGNorm()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.27;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.3;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.36;
    data_pqrst.amp = 0.12;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.4;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.48;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.84;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.96;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.04;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.11;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 1.14;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 1.18;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 1.2;
    data_pqrst.amp = 0.12;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 1.24;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.32;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.48;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.68;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies1()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.19;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.27;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.3;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.36;
    data_pqrst.amp = 0.12;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.4;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.48;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.84;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies2()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.3;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.36;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.44;
    data_pqrst.amp = 0.19;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.48;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.84;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies3()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.27;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.3;
    data_pqrst.amp = -0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.35;
    data_pqrst.amp = 0.88;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.48;
    data_pqrst.amp = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.56;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.84;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies4()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;

    data_pqrst.name = "P1 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P2 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 1.5;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P3 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 3.45;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.5;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P4 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 4.3;
    data_pqrst.dur = 0.5;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.1;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P5 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 5.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 1.5;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "P6 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 6.5;
    data_pqrst.dur = 0.5;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P7 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 7.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 1.5;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P8 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 8.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.5;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P9 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 9.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.5;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P10 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 10.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P11 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 11.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P12 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 12.5;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 1.5;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P13 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 13.45;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.5;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P14 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 14.3;
    data_pqrst.dur = 0.5;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.1;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P15 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 15.3;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 1.7;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P16 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 16.3;
    data_pqrst.dur = 0.5;
    data_pqrst.time_shift = 0.1;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P17 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 17.3;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 1.7;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P18 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 18.3;
    data_pqrst.dur = 0.5;
    data_pqrst.time_shift = -1;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P19 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 19;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 0.5;
    data_pqrst.amp = 0.5;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    return v_data_pqrst;

}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies5()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.27;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.3;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.36;
    data_pqrst.amp = 0.12;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.4;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.48;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.27;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 1.3;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 1.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 1.36;
    data_pqrst.amp = 0.12;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 1.4;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.48;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 2;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.27;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 2.3;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 2.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 2.36;
    data_pqrst.amp = 0.12;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 2.4;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.48;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.84;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies6()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.27;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.3;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.36;
    data_pqrst.amp = 0.12;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.4;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.48;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.8;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);

    createImpulse(&v_data_pqrst, 1, 8);

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies7()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.27;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.3;
    data_pqrst.amp = 0.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.36;
    data_pqrst.amp = 0.12;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.4;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.48;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.8;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);

    createImpulse(&v_data_pqrst, 2, 2);

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies8()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.3;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.36;
    data_pqrst.amp = 0.25;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.37;
    data_pqrst.amp = 0.35;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.38;
    data_pqrst.amp = 0.3;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.48;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.75;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.85;
    data_pqrst.amp = 1.2;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.86;
    data_pqrst.amp = 1.15;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.87;
    data_pqrst.amp = 1.15;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.9;
    data_pqrst.amp = 0.25;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.0;
    data_pqrst.dur = 0.12;
    data_pqrst.time_shift = 0.03;
    data_pqrst.amp = 0.03;
    data_pqrst.amp_shift = 0.22;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.55;
    data_pqrst.dur = 1;
    data_pqrst.time_shift = 1.5;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.23;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 5;
    data_pqrst.end = 2;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies9()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.3;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.34;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.36;
    data_pqrst.amp = 0.15;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.4;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.48;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.75;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.79;
    data_pqrst.amp = 1;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.81;
    data_pqrst.amp = 0.15;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.85;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST зубец";
    data_pqrst.sig = 5;
    data_pqrst.end = 0.93;
    data_pqrst.amp = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.09;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.29;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.2;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);

    createImpulse(&v_data_pqrst, 2, 1);

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataECGPathologies10()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;

    //Количество отрезков
    int count = 200;
    int start = 10;
    int end = 50;

    srand(time(NULL));
    for(int i = 1; i <= count; ++i) {

        double x = rand() % (end - start +1) + start;
        data_pqrst.name = QString("Отрезок%1").arg(QString::number(i));
        data_pqrst.sig = 5;
        data_pqrst.end = (double)i/10;

        if(i % 2 == 0) {
            x = 50 + x;

        } else {
            x = 50 - x;
        }
        data_pqrst.amp = (double)x/100;
        v_data_pqrst.push_back(data_pqrst);
    }

    return v_data_pqrst;
}

QVector<_data_pqrst_> Diograms_Data::getDataEEGPathologies1()
{
    QVector<_data_pqrst_> v_data_pqrst;
    _data_pqrst_ data_pqrst;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P1 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.85;
    data_pqrst.dur = 3.8;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P1 интервал";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.2;
    data_pqrst.dur = 0.84;
    data_pqrst.time_shift = 0.39;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P2 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.8;
    data_pqrst.dur = 2;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P2 интервал";
    data_pqrst.sig = 1;
    data_pqrst.end = 3.2;
    data_pqrst.dur = 0.88;
    data_pqrst.time_shift = 0.33;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P3 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 4.75;
    data_pqrst.dur = 3.8;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 0.8;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P3 интервал";
    data_pqrst.sig = 1;
    data_pqrst.end = 5.3;
    data_pqrst.dur = 0.9;
    data_pqrst.time_shift = 0.33;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.24;
    v_data_pqrst.push_back(data_pqrst);

    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P4 зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 6.85;
    data_pqrst.dur = 3.8;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.6;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "P4 интервал";
    data_pqrst.sig = 1;
    data_pqrst.end = 7.35;
    data_pqrst.dur = 0.9;
    data_pqrst.time_shift = 0.47;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    return v_data_pqrst;
}

void Diograms_Data::createImpulse(QVector<_data_pqrst_> *data_pqrst_, double sec, int count)
{
    QVector<_data_pqrst_> data_pqrst = *data_pqrst_;
    QVector<_data_pqrst_>::iterator it;
    for(int i = 1; i <= count; i++) {
        for(it = data_pqrst.begin(); it != data_pqrst.end(); it++) {
            (*it).end = (*it).end + sec;
            data_pqrst_->push_back(*it);
        }
    }
}



