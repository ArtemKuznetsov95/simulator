#include "listdata.h"

ListData::ListData()
{

}

QMap<ListData::Noise, QString> ListData::getMapNoise()
{
    QMap<Noise, QString> map;
    map.insert(NO_TYPE, "Нет");
    map.insert(TYPE_1, "Белый шум(БШ)");
    map.insert(TYPE_2, "Сетевая помеха(СП)");
    map.insert(TYPE_3, "Дрейф(Д)");
    map.insert(TYPE_4, "БШ+СП");
    map.insert(TYPE_5, "БШ+Д");
    map.insert(TYPE_6, "СП+Д");
    map.insert(TYPE_7, "БШ+СП+Д");

    return map;
}

QMap<ListData::Test, QString> ListData::getMapTest()
{
    QMap<Test, QString> map;
    map.insert(TEST_TYPE_1, "Синусоидальный");
    map.insert(TEST_TYPE_2, "Треугольный");
    map.insert(TEST_TYPE_3, "Трапецевидный");
    map.insert(TEST_TYPE_4, "Параболический");
    map.insert(TEST_TYPE_5, "Импульсный");

    return map;
}

QMap<ListData::DiogramEKG, QString> ListData::getMapDiogramEKG_BEAT_Norm()
{
    QMap<DiogramEKG, QString> map;
    map.insert(EKG_NORM, "Нормокардия");

    return map;
}

QMap<ListData::DiogramEKG, QString> ListData::getMapDiogramEKG_BEAT_Patology()
{
    QMap<DiogramEKG, QString> map;
    map.insert(EKG_PATOLOGY1, "Фибрилляция желудочков");
    map.insert(EKG_PATOLOGY2, "Тахикардии");
    map.insert(EKG_PATOLOGY3, "Брадикардии");
    map.insert(EKG_PATOLOGY4, "Бигемения");
    map.insert(EKG_PATOLOGY5, "Одиночная экстраситола");

    return map;
}

QMap<ListData::DiogramEKG, QString> ListData::getMapDiogramEKG_FORM_Norm()
{
    QMap<DiogramEKG, QString> map;
    map.insert(EKG_NORM_2, "ЭКГ в норме (кардиоцикл)");

    return map;
}

QMap<ListData::DiogramEKG, QString> ListData::getMapDiogramEKG_FORM_Patology()
{
    QMap<DiogramEKG, QString> map;
    map.insert(EKG_PATOLOGY6, "Гипертрофия левого предсердия");
    map.insert(EKG_PATOLOGY7, "Ишемическая болезнь сердца");
    map.insert(EKG_PATOLOGY8, "Признаков инфаркта миокарда");

    return map;
}

QMap<ListData::DiogramEMG, QString> ListData::getMapDiogramEMG_Norm()
{
    QMap<DiogramEMG, QString> map;
    map.insert(EMG_NORM, "В норме");

    return map;
}

QMap<ListData::DiogramEMG, QString> ListData::getMapDiogramEMG_Patology()
{
    QMap<DiogramEMG, QString> map;
    map.insert(EMG_PATOLOGY1, "При тяжелом парезе мышц после полиомелита");
    map.insert(EMG_PATOLOGY2, "При паркинсоническом дрожании и ригидном повышении тонуса");
    return map;
}

QMap<ListData::DiogramEEG, QString> ListData::getMapDiogramEEG_Norm()
{
    QMap<DiogramEEG, QString> map;
    map.insert(EEG_NORM_1, "Альфа-ритм, 8-13 ГЦ");
    map.insert(EEG_NORM_2, "Бета-ритмб 14-30 ГЦ");
    map.insert(EEG_NORM_3, "Тетра-ритм, 4-7 ГЦ");
    map.insert(EEG_NORM_4, "Гамма-ритм, 30-60 ГЦ");
    map.insert(EEG_NORM_5, "Дельта-ритмб 0.5-4 ГЦ");
    map.insert(EEG_NORM_5, "Здоровый человек");
    return map;

}

QMap<ListData::DiogramEEG, QString> ListData::getMapDiogramEEG_Patology()
{
    QMap<DiogramEEG, QString> map;
    map.insert(EEG_PATOLOGY1, "Спайки");
    map.insert(EEG_PATOLOGY2, "Острые волны");
    map.insert(EEG_PATOLOGY3, "Острые волны в полосе");
    map.insert(EEG_PATOLOGY4, "Срайки-волна");
    map.insert(EEG_PATOLOGY5, "Множественные спайки-волна");
    map.insert(EEG_PATOLOGY6, "Острая волна-медленная волна");
    map.insert(EEG_PATOLOGY6, "Малый эпилептический припадок");
    return map;
}

