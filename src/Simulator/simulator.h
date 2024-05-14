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


    void pqrstPlot();       // Вычисление координат графика для всех ЭКГ кроме Тестовых сигналов
    void testSignalPlot();  // Вычисление координат графика только для Тестовых сигналов

    void playPlot();
    void plotX(int);
    void plotX0(int);
    void updatePlot();


    void switchingModesTraining();
    void switchingModesPlayback();
    void switchingModesControl();
    void on_m_pushButton_test_clicked();

    void on_m_pushButton_ecg_clicked();
    void on_m_pushButton_emg_clicked();
    void on_m_pushButton_eeg_clicked();
    void sl_showPlot_DiogramEKG(ListData::DiogramEKG type);
    void sl_showPlot_DiogramEMG(ListData::DiogramEMG type);
    void sl_showPlot_DiogramEEG(ListData::DiogramEEG type);
    void sl_showPlot_DiogramTest(ListData::Test type);
    void show_DiogramEKG_FORM_Norm();
    void show_DiogramEMG_Norm_plot();
    void show_DiogramEEG_Norm_1();
    void show_DiogramEEG_Norm_2();
    void show_DiogramEEG_Norm_3();
    void show_DiogramEEG_Norm_4();
    void show_DiogramEEG_Norm_5();

    void show_DiogramTest_Type1();
    void show_DiogramTest_Type2();
    void show_DiogramTest_Type3();
    void show_DiogramTest_Type4();
    void show_DiogramTest_Type5();

    void setPlayEditor(bool in);

    /// Блок управления редактора Тестовых сигналов
    void setEditor_TestSignal(bool in); //Функция включает при true редактор на Тестовые сигналы, при false для всех остальных
    void sl_setData_dsb_sig_amp(double value); //Слот изменения значения поля Амплитуда
    void sl_setData_dsb_sig_frec(double value); //Слот изменения значения поля Частота
    void sl_setData_m_doubleSpinBox_count(int value); //Слот изменения значения поля Кол-во повторений

    /// Блок рисования Тестовых сигналов
    void draw_DiogramTest_Type1();
    void draw_DiogramTest_Type2();
    void draw_DiogramTest_Type3();
    void draw_DiogramTest_Type4();
    void draw_DiogramTest_Type5();

    void draw_clear();

    void updateComboBox_noise();
    void show_Noise();
    void turnOn_noise_type1();
    void turnOn_noise_type2();
    void turnOn_noise_type3();
    void turnOn_noise_type4();
    void turnOn_noise_type5();
    void turnOn_noise_type6();
    void turnOn_noise_type7();


};

#endif // SIMULATOR_H
