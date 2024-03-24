#ifndef LISTDATA_H
#define LISTDATA_H

#include <QObject>
#include <QMap>

class ListData
{
public:
    enum Signal {
        EFS = 1,
        Signal1 = 2
    };

    enum SignalEFS {
        EKG = 1,
        EMG = 2,
        EEG = 3
    };

    enum DiogramEKG {
        EKG_NORM = 1,
        EKG_NORM_2 = 2,

        EKG_PATOLOGY1 = 3,  //Фибрилляция желудочков
        EKG_PATOLOGY2 = 4,  //Тахикардии
        EKG_PATOLOGY3 = 5,  //Брадикардии
        EKG_PATOLOGY4 = 6,  //Бигемения
        EKG_PATOLOGY5 = 7,  //Одиночная экстраситола

        EKG_PATOLOGY6 = 8,  //Гипертрофия левого предсердия
        EKG_PATOLOGY7 = 9,  //Ишемическая болезнь сердца
        EKG_PATOLOGY8 = 10   //Признаков инфаркта миокарда

    };

    enum DiogramEMG {
        EMG_NORM = 1,

        EMG_PATOLOGY1 = 2,  //При тяжелом парезе мышц после полиомелита
        EMG_PATOLOGY2 = 3,  //При паркинсоническом дрожании и ригидном повышении тонуса

    };

    enum DiogramEEG {
        EEG_NORM_1 = 1,
        EEG_NORM_2 = 2,
        EEG_NORM_3 = 3,
        EEG_NORM_4 = 4,
        EEG_NORM_5 = 5,

        EEG_PATOLOGY1 = 6,
        EEG_PATOLOGY2 = 7,
        EEG_PATOLOGY3 = 8,
        EEG_PATOLOGY4 = 9,
        EEG_PATOLOGY5 = 10,
        EEG_PATOLOGY6 = 11


    };

    enum Noide {
        NO_TYPE = 0,
        TYPE_1 = 1,
        TYPE_2 = 2,
        TYPE_3 = 3,
        TYPE_4 = 4,
        TYPE_5 = 5,
        TYPE_6 = 6,
        TYPE_7 = 7

    };

    enum Mode {
        BEAT = 1,
        FORM = 2
    };

    enum Vid {
        NORM = 1,
        PATOLOGY = 2
    };

    ListData();

    static QMap<DiogramEKG, QString> getMapDiogramEKG_BEAT_Norm();
    static QMap<DiogramEKG, QString> getMapDiogramEKG_BEAT_Patology();

    static QMap<DiogramEKG, QString> getMapDiogramEKG_FORM_Norm();
    static QMap<DiogramEKG, QString> getMapDiogramEKG_FORM_Patology();

    static QMap<DiogramEMG, QString> getMapDiogramEMG_Norm();
    static QMap<DiogramEMG, QString> getMapDiogramEMG_Patology();

    static QMap<DiogramEEG, QString> getMapDiogramEEG_Norm();
    static QMap<DiogramEEG, QString> getMapDiogramEEG_Patology();

    static QMap<Signal, QString> getMapSignal();
    static QMap<Noide, QString> getMapNoise();

};

#endif // LISTDATA_H
