#ifndef TRATINING_FORM_H
#define TRATINING_FORM_H

#include <QWidget>
#include <QStringList>
#include <QMap>
#include <QStandardItemModel>
#include <QButtonGroup>
#include <src/Diograms/Enum/listdata.h>
#include <src/Tratining/Servise/servise_plot.h>

namespace Ui {
class Tratining_Form;
}

class Tratining_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Tratining_Form(QWidget *parent = nullptr);
    ~Tratining_Form();

    void showListSignal();
    void showListNoide();

    void show_DiogramEKG_BEAT_Norm();
    void show_DiogramEKG_BEAT_Patology();
    void show_DiogramEKG_FORM_Norm();
    void show_DiogramEKG_FORM_Patology();

    void show_DiogramEMG_Norm();
    void show_DiogramEMG_Patology();

    void show_DiogramEEG_Norm();
    void show_DiogramEEG_Patology();

public slots:
    void sl_selectDirection();
    void sl_currentEKG();
    void sl_currentEMG();
    void sl_currentEEG();

    void sl_curentDiogramEKG(ListData::Mode mode, ListData::Vid vid);
    void sl_curentDiogramEMG(ListData::Vid vid);
    void sl_curentDiogramEEG(ListData::Vid vid);

    void updateComboBox_noise();
    void show_Noise();
    void turnOn_noise_type1();
    void turnOn_noise_type2();
    void turnOn_noise_type3();
    void turnOn_noise_type4();
    void turnOn_noise_type5();
    void turnOn_noise_type6();
    void turnOn_noise_type7();

private:
    Ui::Tratining_Form *ui;
    Servise_plot* m_plot;
    QStandardItemModel* modelDiogramList;
    QButtonGroup* gropRadioButtonMode; //!< Группа кнопок Режима
    QButtonGroup* gropRadioButtonVid; //!< Группа кнопок Вида
    ListData::SignalEFS m_currentSignal; //!< Активный сигнал

};

#endif // TRATINING_FORM_H
