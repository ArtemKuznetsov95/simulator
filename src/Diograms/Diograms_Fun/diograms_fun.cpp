#include "diograms_fun.h"

diograms_Fun::diograms_Fun()
{

}

void diograms_Fun::fun_control(QCustomPlot *customplot, QVector<_data_pqrst_> data_pqrst)
{
    QVector <double> pointsX, pointsY;
    pqrstPlot(data_pqrst, &pointsX, &pointsY);

    double amp_min = 0;
    double amp_max = 0.1;
    for (int k = 0; k < pointsY.size(); k++){
        double amp_i = pointsY.at(k);
        if (amp_i > amp_max) amp_max = amp_i;
        if (amp_i < amp_min) amp_min = amp_i;
        if (!amp_min) amp_min = amp_max;
        if (!amp_max) amp_max = amp_min;
    }
    double amp_dif = amp_max - amp_min;
    amp_min -= 0.1 * amp_dif;
    amp_dif *= 1.2;
    customplot->yAxis->setRange(amp_min, amp_dif, Qt::AlignLeft);
    customplot->xAxis->setRange(0, data_pqrst.last().end, Qt::AlignLeft);

    customplot->graph(0)->setData(pointsX, pointsY);
    customplot->replot();
}

void diograms_Fun::fun_traning(QCustomPlot *customplot, QVector<_data_pqrst_> data_pqrst)
{
    QVector <double> pointsX, pointsY;
    bool isR = false;

    double amp_min = 0;
    double amp_max = 0;
    double amp_dif = 0;

    QVector<_data_pqrst_> data_pqrst_;
    for(int j = 0; j < data_pqrst.size(); j++) {
        if(j == 0) {
            data_pqrst_.append(data_pqrst.at(j));
            isR = data_pqrst.at(j).isRed;
        } else {
            if(isR == data_pqrst.at(j).isRed) {
                data_pqrst_.append(data_pqrst.at(j));
            } else {

                pqrstPlot(data_pqrst_, &pointsX, &pointsY);
                customplot->addGraph();
                if(isR)
                    customplot->graph()->setPen(QPen(Qt::red));
                else
                    customplot->graph()->setPen(QPen(Qt::blue));
                customplot->graph()->setData(pointsX, pointsY);
                customplot->graph()->rescaleAxes(true);
                customplot->replot();

                double X = pointsX.last();
                double Y = pointsY.last();


                for (int k = 0; k < pointsY.size(); k++){
                    double amp_i = pointsY.at(k);
                    if (amp_i > amp_max) amp_max = amp_i;
                    if (amp_i < amp_min) amp_min = amp_i;
                    if (!amp_min) amp_min = amp_max;
                    if (!amp_max) amp_max = amp_min;
                }

                pointsX.clear();
                pointsY.clear();
                pointsX.append(X);
                pointsY.append(Y);

                data_pqrst_.clear();
                isR = data_pqrst.at(j).isRed;
                data_pqrst_.append(data_pqrst.at(j));
            }
        }
        if(j == data_pqrst.size() - 1) {
            customplot->addGraph();
            pqrstPlot(data_pqrst_, &pointsX, &pointsY);
            if(isR)
                customplot->graph()->setPen(QPen(Qt::red));
            else
                customplot->graph()->setPen(QPen(Qt::blue));
            customplot->graph()->setData(pointsX, pointsY);
            customplot->graph()->rescaleAxes(true);
            customplot->replot();
        }
    }

    for (int k = 0; k < pointsY.size(); k++){
        double amp_i = pointsY.at(k);
        if (amp_i > amp_max) amp_max = amp_i;
        if (amp_i < amp_min) amp_min = amp_i;
        if (!amp_min) amp_min = amp_max;
        if (!amp_max) amp_max = amp_min;
    }

    amp_dif = amp_max - amp_min;
    amp_min -= 0.1 * amp_dif;
    amp_dif *= 1.2;
    customplot->yAxis->setRange(amp_min, amp_dif, Qt::AlignLeft);
    customplot->xAxis->setRange(0, data_pqrst.last().end, Qt::AlignLeft);

    customplot->replot();
}

void diograms_Fun::pqrstPlot(QVector<_data_pqrst_> v_data_pqrst, QVector <double>* pointsX, QVector <double>* pointsY)
{
#ifdef ANDROID
    const int N = 250;
#else
    const int N = 1000;
#endif
    double X;
    double Y;
    int i = 0;
    int begin = 0;
    int end = 0;
    for (int k = 0; k < v_data_pqrst.size(); k++)
    {
        end = v_data_pqrst[k].end * N;
        double shift = v_data_pqrst[k].time_shift + begin;
        while (i <= end) {
            X = (double)i / N;
            switch (v_data_pqrst[k].sig) {
            //нет
            default:
            case 0: {
                Y = 0;
                break;
            }
                //синус
            case 1: {
                double w = 2 * M_PI / v_data_pqrst[k].dur;
                Y = v_data_pqrst[k].amp * sin(w * (X - shift)) + v_data_pqrst[k].amp_shift;
                break;
            }
                //косинус2
            case 2: {
                double w = 2 * M_PI / v_data_pqrst[k].amp;
                Y = v_data_pqrst[k].amp * pow(cos(w * (X - shift)), 2) + v_data_pqrst[k].amp_shift;
                break;
            }
                //колокол
            case 3: {
                double t = 0.303 * v_data_pqrst[k].amp;
                Y = v_data_pqrst[k].amp * exp(-0.5 * pow( (X - shift) / t, 2)) + v_data_pqrst[k].amp_shift;
                break;
            }
                //линия
            case 4: {
                Y = v_data_pqrst[k].amp * (X - shift) + v_data_pqrst[k].amp_shift;
                break;
            }
            case 5: {
                Y = v_data_pqrst[k].amp;
                X = v_data_pqrst[k].end;
                i = end;
                break;
            }
            case 6: {
                Y = v_data_pqrst[k].end;
                X = v_data_pqrst[k].end;
                i = end;
                break;
            }
            }//switch
            pointsX->push_back(X);
            pointsY->push_back(Y);
            i++;
        }//while
        begin = v_data_pqrst[k].end;
    }

}
