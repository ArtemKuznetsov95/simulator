#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QtGui>
#include <QMainWindow>
#include <wfdb/wfdblib.h>
#include <Control/Form/controlmode_form.h>
#include <Tratining/Form/tratining_form.h>

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

    enum TypeOfMode {
        PLAY = 0,
        TRAINING = 1,
        CONTROL = 2
    };
    TypeOfMode typeOfMode;

    QString fileName;
    struct Data {
        QVector <double> pointsX;
        QVector <double> pointsY;
        int data_frec;
        double data_max;
        double data_min;
    } d;
    QVector <struct Data> data;
    QVector <double> pointsX, pointsY;
    QVector <double> pointsXg, pointsYg;

    void signal(double frequency, double amplitude);

    void sinusPlot();
    void pilaPlot();
    void trapPlot();
    void parabPlot();
    void impPlot();
    void addEMG();
    void addWhiteNoise();
    void addSin50Noise();
    void addSinNoise();


    QVector<_data_pqrst> v_data_pqrst;
    bool noEdit;
    QTimer *timer;
    int it;

    bool isTraining = false;

private slots:
    void openFile();
    void viewPlay(bool);
    void startGen(bool);
    void changeSig();

    void pqrstInit_1();
    void pqrstInit_2();
    void pqrstInit_3();

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


    void fun_play_ECG();
    void fun_play_EMG();
    void fun_play_EEG();
    void fun_training_mode_norm();
    void fun_training_mode_pathology1();
    void fun_training_mode_pathology2();
    void fun_training_form_norm();
    void fun_training_form_pathology1();
    void fun_training_form_pathology2();
    void fun_training_form_pathology3();

    void setVisionCombobox(bool in);
    void setRand(double last, double first, int count);

};

#endif // SIMULATOR_H
