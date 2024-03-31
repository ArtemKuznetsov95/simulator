#ifndef PLAYBACK_FORM_H
#define PLAYBACK_FORM_H

#include <QWidget>
#include <QMap>
#include <QStandardItemModel>
#include <QButtonGroup>
#include <src/Diograms/Enum/listdata.h>
#include <src/Tratining/Servise/servise_plot.h>

namespace Ui {
class Playback_Form;
}

class Playback_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Playback_Form(QWidget *parent = nullptr);
    ~Playback_Form();

public slots:
    void startGen(bool in);
    void setIsPlay(bool in);

private slots:
    void on_m_pushButton_ekg_clicked();
    void on_m_pushButton_emg_clicked();
    void on_m_pushButton_eeg_clicked();

    void show_DiogramEKG_Norm();
    void show_DiogramEMG_Norm();
    void show_DiogramEEG_Norm();



private:
    Ui::Playback_Form *ui;
    QStandardItemModel* modelDiogramList;
    ListData::SignalEFS m_currentSignal; //!< Активный сигнал
    Servise_plot* m_plot;

};

#endif // PLAYBACK_FORM_H
