#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QtGui>
#include <QMainWindow>
#include <Utilities/wfdblib.h>
#include <Utilities/wfdb.h>
#include <Control/Form/controlmode_form.h>
#include <Tratining/Form/tratining_form.h>

#include <QMap>
#include <QStandardItemModel>
#include <QButtonGroup>

namespace Ui {
class Simulator;
}

class Simulator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Simulator(QWidget *parent = 0);
    ~Simulator();

    struct _data_pqrst {
        _data_pqrst() : sig(0),
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
    } data_pqrst;
    
private:
    Ui::Simulator *ui;
    ControlMode_Form *m_widgetControl;
    Tratining_Form * m_widgetTraining;

    struct Data {
        QVector <double> pointsX;
        QVector <double> pointsY;
        int data_frec;
        double data_max;
        double data_min;
    } d;

    ListData::SignalEFS m_currentSignal;

    QTimer *timer;
    QStandardItemModel* modelDiogramList;

    int it;
    QString fileName;
    QVector <struct Data> data;
    QVector <double> pointsX, pointsY;
    QVector <double> pointsXg, pointsYg;
    QVector<_data_pqrst> v_data_pqrst;

    bool noEdit;

private slots:

    void show_DiogramEKG_Norm();
    void show_DiogramEMG_Norm();
    void show_DiogramEEG_Norm();

    void openFile();
    void viewPlay(bool);
    void startGen(bool);
    void changeSig();
    void changeDataSig(int sig);
    void changeDataEnd(double val);
    void changeDataDur(double val);
    void changeDataAmp(double val);
    void changeDataAmpSh(double val);
    void changeDataTimeSh(double val);
    void changeList(int,int,int,int);
    void add_row();
    void del_row();
    void edit_row();
    void pqrstPlot();
    void playPlot();
    void plotX(int);
    void plotX0(int);
    void updatePlot();
    void switchingModesTraining();
    void switchingModesPlayback();
    void switchingModesControl();
    void on_m_pushButton_ecg_clicked();
    void on_m_pushButton_emg_clicked();
    void on_m_pushButton_eeg_clicked();
    void sl_showPlot_DiogramEKG(ListData::DiogramEKG type);
    void sl_showPlot_DiogramEMG(ListData::DiogramEMG type);
    void sl_showPlot_DiogramEEG(ListData::DiogramEEG type);
    void show_DiogramEKG_FORM_Norm();
    void show_DiogramEMG_Norm_plot();
    void show_DiogramEEG_Norm_1();
    void show_DiogramEEG_Norm_2();
    void show_DiogramEEG_Norm_3();
    void show_DiogramEEG_Norm_4();
    void show_DiogramEEG_Norm_5();
    void setPlayEditor(bool in);
};

#endif // SIMULATOR_H
