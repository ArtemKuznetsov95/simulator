#ifndef DIOGRAMS_DATA_H
#define DIOGRAMS_DATA_H

#include <QString>
#include <QVector>

struct _data_pqrst_ {
        _data_pqrst_() : sig(0),
            end(0),dur(0),
            amp(0),amp_shift(0),
            time_shift(0),
            isRed(false)
        {}
        int sig;
        double begin;
        double end;
        double dur;
        double amp;
        double amp_shift;
        double time_shift;
        QString name;
        bool isRed = false;

    } ;

class Diograms_Data
{
public:
    Diograms_Data();
    //ЭКГ в норме режим
    static QVector<_data_pqrst_> getDataECGNorm();
    //с гипертрофией левого предсердия.
    static QVector<_data_pqrst_> getDataECGPathologies1();
    //ишемическая болезнь сердца;
    static QVector<_data_pqrst_> getDataECGPathologies2();
    //признаков инфаркта миокарда;
    static QVector<_data_pqrst_> getDataECGPathologies3();
    //фибрилляция желудочков;
    static QVector<_data_pqrst_> getDataECGPathologies4();
    //нормального ритма;
    static QVector<_data_pqrst_> getDataECGPathologies5();
    //тахикардии
    static QVector<_data_pqrst_> getDataECGPathologies6();
    //брадикардии
    static QVector<_data_pqrst_> getDataECGPathologies7();
    //бигемения
    static QVector<_data_pqrst_> getDataECGPathologies8();
    //одиночная экстраситола;
    static QVector<_data_pqrst_> getDataECGPathologies9();

    //электромиограмма
    static QVector<_data_pqrst_> getDataECGPathologies10();    
    //При тяжелом парезе мышц после полиомелита
    static QVector<_data_pqrst_> getDataEMGPathologies1();
    //При паркинсоническом дрожании и ригидном повышении тонуса
    static QVector<_data_pqrst_> getDataEMGPathologies2();

    //ЭЭГ
    //Альфа
    static QVector<_data_pqrst_> getDataEEGNorm_1();
    //Бета
    static QVector<_data_pqrst_> getDataEEGNorm_2();
    //"Тетра-ритм, 4-7 ГЦ"
    static QVector<_data_pqrst_> getDataEEGNorm_3();
    //Гамма-ритм, 30-60 ГЦ
    static QVector<_data_pqrst_> getDataEEGNorm_4();
    //дельта
    static QVector<_data_pqrst_> getDataEEGPathologies1();

    //"Гамма-ритм. Спайки"
    static QVector<_data_pqrst_> getDataEEGPathologies_1();
//Острые волны"
    static QVector<_data_pqrst_> getDataEEGPathologies_2();
    //Острые волны в полосе
    static QVector<_data_pqrst_> getDataEEGPathologies_3();

    //"Гамма-ритм.  Срайки-волна""
    static QVector<_data_pqrst_> getDataEEGPathologies_4();
    //Множественные спайки-волна"
    static QVector<_data_pqrst_> getDataEEGPathologies_5();
    //Острая волна-медленная волна
    static QVector<_data_pqrst_> getDataEEGPathologies_6();

    static void createImpulse(QVector<_data_pqrst_>* data_pqrst_, double sec, int count);

};

#endif // DIOGRAMS_DATA_H
