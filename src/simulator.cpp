#include "delegate.h"
#include "simulator.h"
#include "ui_simulator.h"


Simulator::Simulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulator),
    m_widgetControl(new ControlMode_Form)
{
    ui->setupUi(this);

#ifdef ANDROID
    ui->pb_1->setMinimumSize(64,64);
    ui->pb_1->setMaximumSize(64,64);

    ui->pb_2->setMinimumSize(64,64);
    ui->pb_2->setMaximumSize(64,64);

    ui->pb_3->setMinimumSize(64,64);
    ui->pb_3->setMaximumSize(64,64);

    ui->pb_add->setMinimumSize(64,64);
    ui->pb_add->setMaximumSize(64,64);

    ui->pb_del->setMinimumSize(64,64);
    ui->pb_del->setMaximumSize(64,64);

    ui->pb_edit->setMinimumSize(64,64);
    ui->pb_edit->setMaximumSize(64,64);
#endif

    ui->mainToolBar->addAction(ui->action_open);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->action_start);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->action_view_gen);
    ui->mainToolBar->addAction(ui->action_view_play);
    QActionGroup * agr = new QActionGroup(this);
    agr->addAction(ui->action_view_gen);
    agr->addAction(ui->action_view_play);

    ui->dsb_sig_amp->setValue(1);
    ui->dsb_sig_frec->setValue(1);

    //ui->tableWidget->selectRow(0);
    //ui->tableWidget->setItemDelegateForColumn(1, new ComboBoxDelegate(ui->tableWidget));
    ui->tableWidget->setItemDelegateForColumn(1, new NonEditDelegate());

    ui->plot->addGraph();
//    ui->plot->graph()->setPen(QPen( Qt::red, 3 ));
    ui->plot->graph()->setPen(QPen( Qt::blue, 2 ));
    //    ui->plot->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));

    ui->plot->axisRect()->setupFullAxesBox(true);
    //    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->plot->xAxis->setRange(0, 1, Qt::AlignLeft);
    ui->plot->xAxis->setLabel(trUtf8("t,с"));
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    noEdit=true;
    pqrstInit_1();
    noEdit=false;

    connect(ui->action_open,SIGNAL(triggered()),this,SLOT(openFile()));

    connect(ui->cbNameSig,SIGNAL(currentIndexChanged(int)),this,SLOT(playPlot()));
    connect(ui->action_view_play,SIGNAL(toggled(bool)),this,SLOT(viewPlay(bool)));
//    connect(ui->cb_sig,SIGNAL(currentIndexChanged(int)),this,SLOT(changeSig()));
    connect(ui->cb_noise,SIGNAL(currentIndexChanged(int)),this,SLOT(changeSig()));
//    connect(ui->m_comboBox_vid,SIGNAL(currentIndexChanged(int)),this,SLOT(changeSig()));
//    connect(ui->m_comboBox_mod,SIGNAL(currentIndexChanged(int)),this,SLOT(changeSig()));
    connect(ui->m_comboBox_vid,SIGNAL(currentIndexChanged(int)),this,SLOT(pqrstInit_1()));
    connect(ui->m_comboBox_mod,SIGNAL(currentIndexChanged(int)),this,SLOT(pqrstInit_1()));
    connect(ui->cb_sig,SIGNAL(currentIndexChanged(int)),this,SLOT(pqrstInit_1()));

    noEdit=true;
    viewPlay(false);
    noEdit=false;
    edit_row();

    connect(ui->sliderX,SIGNAL(valueChanged(int)),this,SLOT(plotX(int)));
    connect(ui->sliderX0,SIGNAL(valueChanged(int)),this,SLOT(plotX0(int)));

    connect(ui->dsb_sig_frec,SIGNAL(valueChanged(double)),this,SLOT(changeSig()));
    connect(ui->dsb_sig_amp,SIGNAL(valueChanged(double)),this,SLOT(changeSig()));

    connect(ui->pb_add,SIGNAL(pressed()),this,SLOT(add_row()));
    connect(ui->pb_del,SIGNAL(pressed()),this,SLOT(del_row()));
    connect(ui->pb_edit,SIGNAL(pressed()),this,SLOT(edit_row()));

    connect(ui->pb_1,SIGNAL(pressed()),this,SLOT(pqrstInit_1()));
    connect(ui->pb_2,SIGNAL(pressed()),this,SLOT(pqrstInit_2()));
    connect(ui->pb_3,SIGNAL(pressed()),this,SLOT(pqrstInit_3()));

    connect(ui->tableWidget,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(changeList(int,int,int,int)));

    connect(ui->cb_pqrst,SIGNAL(currentIndexChanged(int)),this,SLOT(changeDataSig(int)));
    connect(ui->dsb_end,SIGNAL(valueChanged(double)),this,SLOT(changeDataEnd(double)));
    connect(ui->dsb_dur,SIGNAL(valueChanged(double)),this,SLOT(changeDataDur(double)));
    connect(ui->dsb_amp,SIGNAL(valueChanged(double)),this,SLOT(changeDataAmp(double)));
    connect(ui->dsb_amp_shift,SIGNAL(valueChanged(double)),this,SLOT(changeDataAmpSh(double)));
    connect(ui->dsb_time_shift,SIGNAL(valueChanged(double)),this,SLOT(changeDataTimeSh(double)));

    connect(ui->action_start,SIGNAL(toggled(bool)),this,SLOT(startGen(bool)));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlot()));

    QActionGroup * actiution_menu = new QActionGroup(this);
    actiution_menu->addAction(ui->action_playback);
    actiution_menu->addAction(ui->action_training);
    actiution_menu->addAction(ui->action_control);

    connect(ui->action_playback,SIGNAL(triggered()),this,SLOT(switchingModesPlayback()));
    connect(ui->action_training,SIGNAL(triggered()),this,SLOT(switchingModesTraining()));
    connect(ui->action_control,SIGNAL(triggered()),this,SLOT(switchingModesControl()));

    switchingModesPlayback();

    ui->cb_sig->setCurrentIndex(5);

    ui->m_stackedWidget->addWidget(m_widgetControl);
}

Simulator::~Simulator()
{
    delete ui;
}

void Simulator::openFile() {
    fileName = QFileDialog::getOpenFileName(this, trUtf8("Открыть сигнал..."),
                                            QString(), trUtf8("Сигналы MIT BIH (*.hea);;Все файлы (*)"));
    if (fileName.isEmpty()) return;
    if (!QFile::exists(fileName)) {
        QMessageBox::warning(this, trUtf8("Внимание"),
                             trUtf8("Файл %1 не существует.").arg(fileName),
                             QMessageBox::Close);
        fileName.clear();
        return;
    }
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->sliderX0->setValue(0);
    qDebug() << "file=" << fileName.toLatin1().data();
    int nsig = isigopen(fileName.toLatin1().data(), NULL, 0);
    if (nsig > 0) {
        WFDB_Siginfo * s = (WFDB_Siginfo *)malloc(nsig * sizeof(WFDB_Siginfo));
        int * vv = (int *)malloc(nsig * sizeof(int));
        if (s && vv) {
            if (isigopen(fileName.toLatin1().data(), s, nsig) == nsig) {
                WFDB_Frequency sfreq = sampfreq(NULL);
                if (sfreq <= 0.0) sfreq = WFDB_DEFFREQ;
                qDebug() << "frec =" << sfreq;//360                     частота

                data.clear();
                ui->cbNameSig->clear();
                for (int i = 0; i < nsig; i++) {                        //количество сигналов
                    if (s[i].gain == 0.0) s[i].gain = WFDB_DEFGAIN;

                    qDebug() << "desc =" << s[i].desc;//MLII            имя
                    qDebug() << "gain =" << s[i].gain;//200             усилитель
                    qDebug() << "units =" << s[i].units;//              в чем измеряется
                    qDebug() << "nsamp =" << s[i].nsamp; //21600        точек
                    qDebug() << "baseline =" << s[i].baseline;//1024    ось
                    qDebug() << "initval =" << s[i].initval;//995       отсчет
                    qDebug() << "spf =" << s[i].spf;//1                 выборок на фрейм
                    qDebug() << "fname =" << s[i].fname;//100s.dat      имя файла
                    qDebug() << "fmt =" << s[i].fmt;//212               формат
                    qDebug() << "adcres =" << s[i].adcres;//11          дискретизация АЦП
                    qDebug() << "adczero =" << s[i].adczero;//1024      ось АЦП

                    d.data_frec = sfreq;
                    d.pointsX.clear();
                    d.pointsY.clear();
                    for (int t = 0; t < s[i].nsamp; t++) {
                        if (isigsettime(t) < 0 || getvec(vv) < nsig) break;
                        //qDebug() << t << "[" << i << "] =" << (vv[i] + s[i].initval) / s[i].gain << s[i].units;
                        double val = (vv[i] + s[i].initval) / s[i].gain;
                        if (val > d.data_max || !t) d.data_max = val;
                        if (val < d.data_min || !t) d.data_min = val;
                        d.pointsX.push_back(t / sfreq);
                        d.pointsY.push_back(val);
                    }
                    data.push_back(d);
                    ui->cbNameSig->addItem(QString("%1 (%2)").arg(s[i].desc).arg(s[i].fname));
                }

            } else {
                QMessageBox::warning(this, trUtf8("Внимание"),
                                     trUtf8("Не все сигналы считаны."),
                                     QMessageBox::Close);
                fileName.clear();
            }
            wfdb_sigclose();
            free(vv);
            free(s);
        } else {
            qDebug() << "simulator: insufficient memory";
            fileName.clear();
        }
    } else {
        QMessageBox::warning(this, trUtf8("Внимание"),
                             trUtf8("Нет информации о сигнале."),
                             QMessageBox::Close);
        fileName.clear();
    }

    QApplication::restoreOverrideCursor();
    statusBar()->showMessage(trUtf8("Сигнал открыт"), 2000);
}

void Simulator::viewPlay(bool in) {
    ui->action_open->setEnabled(in);
    ui->widget_gen->setHidden(in);
    ui->cbNameSig->setVisible(in);

    if (ui->action_start->isChecked()) ui->action_start->toggle();
    ui->sliderX0->setValue(0);

    if (in) {
        ui->action_start->setText(trUtf8("Воспроизводить"));
        if (fileName.isEmpty()) openFile();
        else playPlot();
    } else {
        ui->action_start->setText(trUtf8("Генерировать"));
        changeSig();
    }
}

void Simulator::changeSig() {
    qDebug() << "changeSig()";
    if (noEdit) return;

    pointsX.clear();
    pointsY.clear();
    double amp_min = 0;
    double amp_max = 1.1 * ui->dsb_sig_amp->value();
    double x_visible = 5;

    ui->widget_pqrst->setVisible(ui->cb_sig->currentIndex() == 5);
    ui->widget_sig->setVisible(ui->widget_pqrst->isHidden());

    qDebug() << "sig=" << ui->cb_sig->currentIndex();
    switch (ui->cb_sig->currentIndex()) {
    case 0: {
        sinusPlot();
        setVisionCombobox(false);
        break;
    }
    case 1: {
        pilaPlot();
        setVisionCombobox(false);
        break;
    }
    case 2: {
        trapPlot();
        setVisionCombobox(false);
        break;
    }
    case 3: {
        parabPlot();
        setVisionCombobox(false);
        break;
    }
    case 4: {
        impPlot();
        setVisionCombobox(false);
        break;
    }
    case 5: {
        pqrstPlot();
        setVisionCombobox(true);

        for (int k = 0; k < pointsY.size(); k++){
            double amp_i = pointsY.at(k);
            if (amp_i > amp_max) amp_max = amp_i;
            if (amp_i < amp_min) amp_min = amp_i;
            if (!amp_min) amp_min = amp_max;
            if (!amp_max) amp_max = amp_min;
        }

        x_visible = v_data_pqrst.last().end;
        break;
    }
    }

    noEdit = true;
    int x_vis = x_visible * 100 + 0.1;
    if (ui->sliderX0->value() >= x_vis) ui->sliderX0->setValue(0);
    int x_max = x_vis - ui->sliderX0->value();
    if (ui->sliderX->value() > x_max) ui->sliderX->setValue(x_max);
    ui->sliderX->setMaximum(x_max);
    ui->sliderX0->setMaximum(x_visible * 100 + 0.1 - ui->sliderX->value());
    noEdit = false;

    qDebug() << "noise=" << ui->cb_noise->currentIndex();
    switch (ui->cb_noise->currentIndex()) {
    case 1: {
        addWhiteNoise();
        break;
    }
    case 2: {
        addSin50Noise();
        break;
    }
    case 3: {
        addSinNoise();
        break;
    }
    case 4: {
        addWhiteNoise();
        addSin50Noise();
        break;
    }
    case 5: {
        addWhiteNoise();
        addSinNoise();
        break;
    }
    case 6: {
        addSin50Noise();
        addSinNoise();
        break;
    }
    case 7: {
        addWhiteNoise();
        addSin50Noise();
        addSinNoise();
        break;
    }
    }

    //TODO обработка режим
    if(isTraining) {
        qDebug() << "mod=" << ui->m_comboBox_mod->currentIndex();
        switch (ui->m_comboBox_mod->currentIndex()) {
        case 0: {
            // Режим
            qDebug() << "vid=" << ui->m_comboBox_vid->currentIndex();
            switch (ui->m_comboBox_vid->currentIndex()) {
            case 0: {
                // Норма
                ui->plot->graph()->setPen(QPen( Qt::blue, 2 ));

                ui->pb_1->setVisible(true);
                ui->pb_2->setVisible(false);
                ui->pb_3->setVisible(false);
                break;
            }
            case 1: {
                // Патология
                ui->plot->graph()->setPen(QPen( Qt::red, 2 ));

                ui->pb_1->setVisible(true);
                ui->pb_2->setVisible(true);
                ui->pb_3->setVisible(false);
                break;
            }
                break;
            }
            break;
        }
        case 1: {
            // Форма
            qDebug() << "vid=" << ui->m_comboBox_vid->currentIndex();
            switch (ui->m_comboBox_vid->currentIndex()) {
            case 0: {
                // Норма
                ui->plot->graph()->setPen(QPen( Qt::blue, 2 ));

                ui->pb_1->setVisible(true);
                ui->pb_2->setVisible(false);
                ui->pb_3->setVisible(false);
                break;
            }
            case 1: {
                // Патология
                ui->plot->graph()->setPen(QPen( Qt::red, 2 ));

                ui->pb_1->setVisible(true);
                ui->pb_2->setVisible(true);
                ui->pb_3->setVisible(true);
                break;
            }
                break;
            }
        }
        break;
        }

    } else {
         ui->plot->graph()->setPen(QPen( Qt::blue, 2 ));
    }

    double amp_dif = amp_max - amp_min;
    amp_min -= 0.1 * amp_dif;
    amp_dif *= 1.2;
    ui->plot->yAxis->setRange(amp_min, amp_dif, Qt::AlignLeft);
    ui->plot->xAxis->setRange(0.01 * ui->sliderX0->value(), 0.01 * ui->sliderX->value(), Qt::AlignLeft);

    ui->plot->graph(0)->setData(pointsX, pointsY);
    ui->plot->replot();
}

void Simulator::add_row()
{
    int i = ui->tableWidget->rowCount();
    data_pqrst.end = v_data_pqrst[i - 1].end + data_pqrst.dur;
    v_data_pqrst.push_back(data_pqrst);

    ui->tableWidget->insertRow(i);

    ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString(trUtf8("%1 участок")).arg(i + 1)));
    ui->tableWidget->setItem(i, 1, new QTableWidgetItem(trUtf8("нет")));
    ui->tableWidget->selectRow(i);
    ui->pb_del->setEnabled(true);

    int x_max = data_pqrst.end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
}

void Simulator::del_row()
{
    int i = ui->tableWidget->rowCount() - 1;
    v_data_pqrst.remove(i);
    ui->tableWidget->removeRow(i);
    ui->pb_del->setDisabled(ui->tableWidget->rowCount() == 1);

    int x_max = v_data_pqrst.at(i-1).end * 100 + 0.1;
    ui->sliderX->setValue(x_max);
    ui->sliderX->setMaximum(x_max);
}

void Simulator::edit_row()
{
    bool h = ui->widget_edit_row->isHidden();
    ui->widget_edit_row->setVisible(h);
    ui->tableWidget->setHidden(h);
    ui->pb_add->setHidden(h);
    ui->pb_del->setHidden(h);
    ui->pb_edit->setChecked(h);

    ui->pb_1->setHidden(h);
    ui->pb_2->setHidden(h);
    ui->pb_3->setHidden(h);
}

void Simulator::changeList(int i, int, int i_b, int)
{
    qDebug() << "changeList=" << i << "=" << i_b;
    if (i<0) return;
    noEdit = true;
    ui->label_uch->setText(ui->tableWidget->item(i,0)->text());
    ui->cb_pqrst->setCurrentIndex(v_data_pqrst[i].sig);

    double begin_f = i ? v_data_pqrst[i - 1].end : 0;
    QString begin_s = QString("%L1").arg(begin_f, 0,'f',2);
    ui->label_begin_val->setText(begin_s);

    ui->dsb_end->setMinimum(begin_f + 0.01);

    double end_f = v_data_pqrst.size() > i + 1 ? v_data_pqrst[i + 1].end : 100;
    ui->dsb_end->setMaximum(end_f - 0.01);

    ui->dsb_end->setValue(v_data_pqrst[i].end);

    ui->dsb_dur->setValue(v_data_pqrst[i].dur);
    ui->dsb_amp->setValue(v_data_pqrst[i].amp);
    ui->dsb_amp_shift->setValue(v_data_pqrst[i].amp_shift);
    ui->dsb_time_shift->setValue(v_data_pqrst[i].time_shift);
    noEdit = false;
}

void Simulator::pqrstInit_1()
{
    if(isTraining) {
        switch (ui->m_comboBox_mod->currentIndex()) {
        case 0: {
            // Режим
            switch (ui->m_comboBox_vid->currentIndex()) {
            case 0: {
                // Норма
                this->fun_training_mode_norm();
                break;
            }
            case 1: {
                // Патология
                this->fun_training_mode_pathology1();
                break;
            }
                break;
            }
            break;
        }
        case 1: {
            // Форма
            switch (ui->m_comboBox_vid->currentIndex()) {
            case 0: {
                // Норма
                this->fun_training_form_norm();
                break;
            }
            case 1: {
                // Патология
                this->fun_training_form_pathology1();
                break;
            }
                break;
            }
        }
            break;
        }

    } else {

        this->fun_play_ECG();
    }
}

void Simulator::pqrstInit_2()
{
    if(isTraining) {
        switch (ui->m_comboBox_mod->currentIndex()) {
        case 0: {
            // Режим
            switch (ui->m_comboBox_vid->currentIndex()) {
            case 1: {
                // Патология
                this->fun_training_mode_pathology2();
                break;
            }
                break;
            }
            break;
        }
        case 1: {
            // Форма
            switch (ui->m_comboBox_vid->currentIndex()) {
            case 1: {
                // Патология
                this->fun_training_form_pathology2();
                break;
            }
                break;
            }
            break;
        }
        }
    } else {
        this->fun_play_EMG();
    }
}

void Simulator::pqrstInit_3()
{
    if(isTraining) {
        switch (ui->m_comboBox_mod->currentIndex()) {
        case 1: {
            // Форма
            switch (ui->m_comboBox_vid->currentIndex()) {
            case 1: {
                // Патология
                this->fun_training_form_pathology3();
                break;
            }
                break;
            }
            break;
        }
        }
    } else {
        this->fun_play_EEG();
    }
}

void Simulator::changeDataSig(int sig)
{
    ui->label_dur->setEnabled(sig == 1);
    ui->dsb_dur->setEnabled(sig == 1);
    ui->label_amp->setEnabled(sig);
    ui->dsb_amp->setEnabled(sig);
    ui->label_amp_shift->setEnabled(sig);
    ui->dsb_amp_shift->setEnabled(sig);
    ui->label_time_shift->setEnabled(sig);
    ui->dsb_time_shift->setEnabled(sig);

    if (noEdit) return;

    int i = ui->tableWidget->currentRow();
    double dur = v_data_pqrst[i].end - (i ? v_data_pqrst[i - 1].end : 0);

    switch (sig) {
    case 1:
    case 4: {
        ui->dsb_dur->setValue(dur);
        ui->dsb_amp->setValue(ui->dsb_amp_shift->value());
        ui->dsb_time_shift->setValue(0);
        break;
    }
    case 2: {
        ui->dsb_dur->setValue(dur);
        ui->dsb_amp->setValue(2 * dur);
        ui->dsb_time_shift->setValue(dur / 2);
        break;
    }
    case 3: {
        ui->dsb_amp->setValue(dur / 2);
        ui->dsb_dur->setValue(0.303 * dur);
        ui->dsb_time_shift->setValue(dur / 2);
        break;
    }
    }

    ui->tableWidget->item(i,1)->setText(ui->cb_pqrst->currentText());
    v_data_pqrst[i].sig = sig;
    changeSig();
}

void Simulator::changeDataEnd(double val)
{
    if (noEdit) return;
    v_data_pqrst[ui->tableWidget->currentRow()].end = val;
    if (ui->tableWidget->currentRow() + 1 == ui->tableWidget->rowCount())
        ui->sliderX->setValue(val * 100 + 0.1);
    changeSig();
}

void Simulator::changeDataDur(double val)
{
    if (noEdit) return;
    v_data_pqrst[ui->tableWidget->currentRow()].dur = val;
    changeSig();
}

void Simulator::changeDataAmp(double val)
{
    if (noEdit) return;
    v_data_pqrst[ui->tableWidget->currentRow()].amp = val;
    changeSig();
}

void Simulator::changeDataAmpSh(double val)
{
    if (noEdit) return;
    v_data_pqrst[ui->tableWidget->currentRow()].amp_shift = val;
    changeSig();
}

void Simulator::changeDataTimeSh(double val)
{
    if (noEdit) return;
    v_data_pqrst[ui->tableWidget->currentRow()].time_shift = val;
    changeSig();
}

void Simulator::sinusPlot()
{
    ui->label_plot->setText( QString::fromUtf8("Синус") );
#ifdef ANDROID
    const int N = 250;
#else
    const int N = 1000;
#endif
    double X;
    double Y;
    int i = 0.01 * ui->sliderX0->value() * N;
    int end = 0.01 * (ui->sliderX0->value() + ui->sliderX->value()) * N;
    double shift = 1.0 / (ui->dsb_sig_frec->value() * 4);
    while (i <= end) {
        X = (double)i / N;
        double w = 2 * M_PI * ui->dsb_sig_frec->value();
        Y = ui->dsb_sig_amp->value() * (sin(w * (X - shift)) / 2 + 0.5);
        pointsX.push_back(X);
        pointsY.push_back(Y);
        i++;
    }//while
}

void Simulator::pilaPlot()
{
    ui->label_plot->setText( QString::fromUtf8("Треугольник") );
#ifdef ANDROID
    const int N = 250;
#else
    const int N = 1000;
#endif
    double X;
    double Y;
    int i = 0.01 * ui->sliderX0->value() * N;
    int end = 0.01 * (ui->sliderX0->value() + ui->sliderX->value()) * N;
    while (i <= end) {
        X = (double)i / N;
        double l;
        Y = ui->dsb_sig_amp->value() * 2 * modf(X * ui->dsb_sig_frec->value(),&l);
        if (Y > ui->dsb_sig_amp->value())
            Y = ui->dsb_sig_amp->value() * 2 - Y;
        pointsX.push_back(X);
        pointsY.push_back(Y);
        i++;
    }//while

}

void Simulator::trapPlot()
{
    ui->label_plot->setText( QString::fromUtf8("Трапеция") );
#ifdef ANDROID
    const int N = 250;
#else
    const int N = 1000;
#endif
    double X;
    double Y;
    int i = 0.01 * ui->sliderX0->value() * N;
    int end = 0.01 * (ui->sliderX0->value() + ui->sliderX->value()) * N;
    while (i <= end) {
        X = (double)i / N;
        double l;
        Y = ui->dsb_sig_amp->value() * 4 * modf(X * ui->dsb_sig_frec->value(),&l);
        if (Y > ui->dsb_sig_amp->value() * 2)
            Y = ui->dsb_sig_amp->value() * 4 - Y;
        if (Y > ui->dsb_sig_amp->value()) Y = ui->dsb_sig_amp->value();
        pointsX.push_back(X);
        pointsY.push_back(Y);
        i++;
    }//while
}

void Simulator::parabPlot()
{
    ui->label_plot->setText( QString::fromUtf8("Парабола") );
#ifdef ANDROID
    const int N = 250;
#else
    const int N = 1000;
#endif
    double X;
    double Y;
    int i = 0.01 * ui->sliderX0->value() * N;
    int end = 0.01 * (ui->sliderX0->value() + ui->sliderX->value()) * N;
    while (i <= end) {
        X = (double)i / N;
        Y = ui->dsb_sig_amp->value() * sin(M_PI * X * ui->dsb_sig_frec->value());
        if (Y < 0) Y *= -1;
        pointsX.push_back(X);
        pointsY.push_back(Y);
        i++;
    }//while
}

void Simulator::impPlot()
{
    ui->label_plot->setText( QString::fromUtf8("Импульс") );
#ifdef ANDROID
    const int N = 250;
#else
    const int N = 1000;
#endif
    double X;
    double Y;
    int i = 0.01 * ui->sliderX0->value() * N;
    int end = 0.01 * (ui->sliderX0->value() + ui->sliderX->value()) * N;
    int t = N / ui->dsb_sig_frec->value();
    while (i <= end) {
        X = (double)i / N;
        if (!(i % t)) Y = ui->dsb_sig_amp->value();
        else Y = 0;
        pointsX.push_back(X);
        pointsY.push_back(Y);
        i++;
    }//while
}

void Simulator::addEMG()
{
    int N = pointsY.size();
    double Y;
    for (int k = 0; k < N; k++)
    {
        Y = ui->dsb_sig_amp->value() / 20 * 2 * ((rand()/((double)RAND_MAX)) - 0.5);
        pointsY[k] = pointsY.at(k) + Y;
    }
}

void Simulator::pqrstPlot()
{
    //    ui->label_plot->setText( QString::fromUtf8("PQRST") );
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
                Y = v_data_pqrst[k].amp * (X - shift) + v_data_pqrst[k].amp_shift;
                addWhiteNoise();
//                addSinNoise();
                break;
            }
            }//switch
            pointsX.push_back(X);
            pointsY.push_back(Y);
            i++;
        }//while
        begin = v_data_pqrst[k].end;
    }
}

void Simulator::addWhiteNoise()
{
    int N = pointsY.size();
    double Y;
    for (int k = 0; k < N; k++)
    {
        Y = ui->dsb_sig_amp->value() / 20 * 2 * ((rand()/((double)RAND_MAX)) - 0.5);
        pointsY[k] = pointsY.at(k) + Y;
    }
}

void Simulator::addSin50Noise()
{
    int N = pointsY.size();
    double X;
    double Y1,Y2;
    double delta = 1.5 * M_PI;
    for (int k = 0; k < N; k++)
    {
        X = (double)(k * 0.01 * ui->sliderX->value()) / (N - 1) + 0.01 * ui->sliderX0->value();
        Y1 = ui->dsb_sig_amp->value() / 20 * (sin(2 * M_PI * X * 50 + delta) / 2 + 0.5);
        Y2 = 0;//ui->dsb_sig_amp->value() / 10 * (sin(M_2PI * X * 60 + delta) / 2 + 0.5);
        pointsY[k] = pointsY.at(k) + Y1 + Y2;
    }
}

void Simulator::addSinNoise()
{
    int N = pointsY.size();
    double X;
    double Y;
    double delta = 1.5 * M_PI;
    double ch = (double)(1 / (0.01 * (ui->sliderX->value()) + ui->sliderX0->value()));
    for (int k = 0; k < N; k++)
    {
        X = (double)(k * 0.01 * ui->sliderX->value()) / (N - 1) + 0.01 * ui->sliderX0->value();
        Y = ui->dsb_sig_amp->value() / 10 * (sin(2 * M_PI * X * ch + delta) / 2 + 0.5);
        pointsY[k] = pointsY.at(k) + Y;
    }
}


void Simulator::playPlot()
{
    qDebug() << "playPlot()";
    int i = ui->cbNameSig->currentIndex();
    if (i < 0 || noEdit) return;

    ui->label_plot->setText( "" );
    double x_visible = data[i].pointsX.count() / data[i].data_frec;
    ui->sliderX->setMaximum(x_visible * 100 + 0.1 - ui->sliderX0->value());
    ui->sliderX0->setMaximum(x_visible * 100 + 0.1 - ui->sliderX->value());

    double amp_min = 0;
    double amp_max = 0;
    for (int k = 0; k < data[i].pointsY.size(); k++){
        double amp_i = data[i].pointsY.at(k);
        if (amp_i > amp_max) amp_max = amp_i;
        if (amp_i < amp_min) amp_min = amp_i;
        if (!amp_min) amp_min = amp_max;
        if (!amp_max) amp_max = amp_min;
    }
    double amp_dif = amp_max - amp_min;
    amp_min -= 0.1 * amp_dif;
    amp_dif *= 1.2;

    ui->plot->yAxis->setRange(amp_min, amp_dif, Qt::AlignLeft);

    ui->plot->graph(0)->setData(data[i].pointsX, data[i].pointsY);
    ui->plot->replot();
}

void Simulator::plotX(int in)
{
    ui->plot->xAxis->setRange(0.01 * ui->sliderX0->value(), 0.01 * in, Qt::AlignLeft);
    qDebug() << "sliderX=" << ui->sliderX->value();
    if (noEdit) return;
    if (ui->action_view_play->isChecked()) ui->plot->replot();
    else changeSig();
}

void Simulator::plotX0(int in)
{
    ui->plot->xAxis->setRange(0.01 * in, 0.01 * ui->sliderX->value(), Qt::AlignLeft);
    if (noEdit) return;
    if (ui->action_view_play->isChecked()) ui->plot->replot();
    else changeSig();
}

void Simulator::startGen(bool in)
{
    ui->widget_gen->setDisabled(in);
    ui->sliderX0->setDisabled(in);
    ui->sliderX->setDisabled(in);

    {   //временно пока ползет
        //        ui->sliderX0->setValue(ui->sliderX0->minimum());
        //        ui->sliderX->setValue(ui->sliderX->maximum());
    }

    it = ui->sliderX0->value();
    if (!ui->action_view_play->isChecked()) {
        pointsXg = pointsX;
        pointsYg = pointsY;
    }
#ifdef ANDROID
    if (in) timer->start(100);
#else
    if (in) timer->start(10);
#endif
    else timer->stop();
}

void Simulator::updatePlot()
{
    if (ui->action_view_play->isChecked()) {
        ui->sliderX0->setValue(it);
    } else {
        ui->plot->xAxis->setRange(0.01 * it, 0.01 * ui->sliderX->value(), Qt::AlignLeft);
        ui->plot->graph(0)->setData(pointsXg, pointsYg);
        ui->plot->replot();

#ifdef ANDROID
        int N = 250;
        int k = 25;
#else
        int N = 1000;
        int k = 10;
#endif
        double dx = (double)1/N;
        for (int i=0;i<k;i++) {
            pointsXg.append(pointsXg.last() + dx);
            pointsXg.removeFirst();
            pointsYg.append(pointsYg.first());
            pointsYg.removeFirst();
        }
    }
#ifdef ANDROID
    it = it + 10;
#else
    it++;
#endif
}

void Simulator::switchingModesTraining()
{
    typeOfMode =  TypeOfMode::TRAINING;
    isTraining = true;

    ui->m_comboBox_vid->setVisible(true);
    ui->label_vid->setVisible(true);

    ui->m_comboBox_mod->setVisible(true);
    ui->label_mod->setVisible(true);

    ui->pb_2->setVisible(false);
    ui->pb_3->setVisible(false);

    ui->m_comboBox_vid->setCurrentIndex(0);
    ui->m_comboBox_mod->setCurrentIndex(0);

    this->pqrstInit_1();
}

void Simulator::switchingModesPlayback()
{
    typeOfMode =  TypeOfMode::PLAY;
    isTraining = false;

    ui->m_comboBox_vid->setVisible(false);
    ui->label_vid->setVisible(false);

    ui->m_comboBox_mod->setVisible(false);
    ui->label_mod->setVisible(false);

    ui->pb_2->setVisible(true);
    ui->pb_3->setVisible(true);

    this->pqrstInit_1();
}

void Simulator::switchingModesControl()
{
    typeOfMode =  TypeOfMode::CONTROL;

    ui->m_stackedWidget->setCurrentIndex(0);
}

void Simulator::fun_play_ECG()
{
    qDebug() << "fun_play_ECG";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭКГ") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.22;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.46;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.11;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.0;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.22;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.46;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.11;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.0;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);

    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::fun_play_EMG()
{
    qDebug() << "fun_play_EMG";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭМГ") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));


//    double max = 1;
//    for (double i =0; i < max;) {
//        i += 0.01;
//        data_pqrst.name = QString("Отрезок №%1").arg(i);
//        data_pqrst.sig = 5;
//        data_pqrst.end = i;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = 0;
//        data_pqrst.amp_shift = 0.5;
//        v_data_pqrst.push_back(data_pqrst);
//    }

        data_pqrst.name = "Отрезок 1";
        data_pqrst.sig = 5;
        data_pqrst.end = 1;
        data_pqrst.time_shift = 0;
        data_pqrst.amp = 0;
        data_pqrst.amp_shift = 0.5;
        v_data_pqrst.push_back(data_pqrst);




//        data_pqrst.name = "R зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.02;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = -0.5;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);

//        data_pqrst.name = "P зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.03;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = 0.6;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);

//        data_pqrst.name = "R зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.04;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = -0.6;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);

//        data_pqrst.name = "P зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.05;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = 0.7;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);

//        data_pqrst.name = "R зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.06;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = -0.7;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);

//        data_pqrst.name = "P зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.07;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = 0.5;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);

//        data_pqrst.name = "R зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.08;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = -0.7;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);

//        data_pqrst.name = "P зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.09;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = 0.7;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);

//        data_pqrst.name = "R зубец";
//        data_pqrst.sig = 4;
//        data_pqrst.end = 0.10;
//        data_pqrst.time_shift = 0;
//        data_pqrst.amp = -0.7;
//        data_pqrst.amp_shift = 0;
//        v_data_pqrst.push_back(data_pqrst);



//    data_pqrst.name = "P зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.01;
//    data_pqrst.dur = 0.01;
//    data_pqrst.time_shift = -0.01;
//    data_pqrst.amp = 0.2;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "R зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.02;
//    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = -0.04;
//    data_pqrst.amp = 0.06;
//    data_pqrst.amp_shift = 0.07;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "S зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.03;
//    data_pqrst.dur = 0.08;
//    data_pqrst.time_shift = 0.02;
//    data_pqrst.amp = -0.38;
//    data_pqrst.amp_shift = 0.08;
//    v_data_pqrst.push_back(data_pqrst);


//    data_pqrst.name = "P зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.04;
//    data_pqrst.dur = 0.01;
//    data_pqrst.time_shift = 0;
//    data_pqrst.amp = 0.04;
//    data_pqrst.amp_shift = 0.04;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "R зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.06;
//    data_pqrst.dur = 0.03;
//    data_pqrst.time_shift = 0;
//    data_pqrst.amp = 0.09;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "S зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.13;
//    data_pqrst.dur = 0.03;
//    data_pqrst.time_shift = 0.06;
//    data_pqrst.amp = -0.2;
//    data_pqrst.amp_shift = -0.01;
//    v_data_pqrst.push_back(data_pqrst);


//    data_pqrst.name = "P зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.15;
//    data_pqrst.dur = 0.04;
//    data_pqrst.time_shift = 0.01;
//    data_pqrst.amp = 0.21;
//    data_pqrst.amp_shift = -0.16;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "R зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.16;
//    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = 0;
//    data_pqrst.amp = 0.07;
//    data_pqrst.amp_shift = -0.16;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "S зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.18;
//    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = 0.01;
//    data_pqrst.amp = -0.31;
//    data_pqrst.amp_shift = -0.03;
//    v_data_pqrst.push_back(data_pqrst);


//    data_pqrst.name = "P зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.21;
//    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = 0.03;
//    data_pqrst.amp = -0.2;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "R зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.22;
//    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = 0.04;
//    data_pqrst.amp = 0.01;
//    data_pqrst.amp_shift = -0.03;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "S зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.24;
//    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = 0.02;
//    data_pqrst.amp = -0.2;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);


//    data_pqrst.name = "P зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.26;
//    data_pqrst.dur = 0.01;
//    data_pqrst.time_shift = -0.03;
//    data_pqrst.amp = -0.15;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "R зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.27;
//    data_pqrst.dur = 0.01;
//    data_pqrst.time_shift = -0.04;
//    data_pqrst.amp = -0.1;
//    data_pqrst.amp_shift = 0.01;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "S зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.32;
//    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = 0.03;
//    data_pqrst.amp = 0.08;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);


//    data_pqrst.name = "P зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.36;
//    data_pqrst.dur = 0.03;
//    data_pqrst.time_shift = 0;
//    data_pqrst.amp = 0.18;
//    data_pqrst.amp_shift = -0.02;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "R зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.38;
//    data_pqrst.dur = 0.03;
//    data_pqrst.time_shift = 0;
//    data_pqrst.amp = 0.09;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "S зубец";
//    data_pqrst.sig = 4;
//    data_pqrst.end = 0.39;
////    data_pqrst.dur = 0.03;
//    data_pqrst.time_shift = 0;
//    data_pqrst.amp = -0.1;
//    data_pqrst.amp_shift = -0.07;
//    v_data_pqrst.push_back(data_pqrst);


//    data_pqrst.name = "P зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.42;
//    data_pqrst.dur = 0.03;
//    data_pqrst.time_shift = 0.01;
//    data_pqrst.amp = 0.16;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "R зубец";
//    data_pqrst.sig = 4;
//    data_pqrst.end = 0.43;
////    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = 0;
//    data_pqrst.amp = 0.54;
//    data_pqrst.amp_shift = -0.37;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "S зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.45;
//    data_pqrst.dur = 0.04;
//    data_pqrst.time_shift = 0.00;
//    data_pqrst.amp = -0.24;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);


//    data_pqrst.name = "P зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.47;
//    data_pqrst.dur = 0.01;
//    data_pqrst.time_shift = 0.03;
//    data_pqrst.amp = 0.22;
//    data_pqrst.amp_shift = 0.02;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "R зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.49;
//    data_pqrst.dur = 0.01;
//    data_pqrst.time_shift = 0.04;
//    data_pqrst.amp = 0.17;
//    data_pqrst.amp_shift = -0.01;
//    v_data_pqrst.push_back(data_pqrst);

//    data_pqrst.name = "S зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 1.5;
//    data_pqrst.dur = 0.02;
//    data_pqrst.time_shift = 0.02;
//    data_pqrst.amp = -0.2;
//    data_pqrst.amp_shift = 0;
//    v_data_pqrst.push_back(data_pqrst);


    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();

}

void Simulator::fun_play_EEG()
{
    qDebug() << "fun_play_EEG";

    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭЭГ. Альфа-ритм") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));


    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.1;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = -0.03;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.8;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = -0.05;
    data_pqrst.amp = -0.13;
    data_pqrst.amp_shift = 0.76;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.44;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.79;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.49;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0.00;
    data_pqrst.amp = -0.1;
    data_pqrst.amp_shift = 0.79;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.53;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.03;
    data_pqrst.amp = 0.02;
    data_pqrst.amp_shift = 0.72;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.6;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = -0.1;
    data_pqrst.amp_shift = 0.79;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.69;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0.00;
    data_pqrst.amp = 0.13;
    data_pqrst.amp_shift = 0.78;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.77;
    data_pqrst.dur = 0.12;
    data_pqrst.time_shift = 0.01;
    data_pqrst.amp = 0.07;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.88;
    data_pqrst.dur = 0.13;
    data_pqrst.time_shift = 0.07;
    data_pqrst.amp = 0.08;
    data_pqrst.amp_shift = 0.76;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.05;
    data_pqrst.dur = 0.15;
    data_pqrst.time_shift = 0.03;
    data_pqrst.amp = -0.07;
    data_pqrst.amp_shift = 0.78;
    v_data_pqrst.push_back(data_pqrst);

    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::fun_training_mode_norm()
{
    qDebug() << "fun_training_mode_norm";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭКГ. Нормокардия") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.22;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.46;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.11;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.69;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.22;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.46;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.11;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.0;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);

    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::fun_training_mode_pathology1()
{
    qDebug() << "fun_training_mode_pathology1";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭКГ. Брадикардия") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    QCPItemBracket *bracket = new QCPItemBracket(ui->plot);
    bracket->left->setCoords(0, 1.1);
    bracket->right->setCoords(2, 1.1);
    bracket->setLength(13);
    QCPItemText *wavePacketText = new QCPItemText(ui->plot);
    wavePacketText->position->setParentAnchor(bracket->center);
    wavePacketText->position->setCoords(0, -10); // move 10 pixels to the top from bracket center anchor
    wavePacketText->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);
    wavePacketText->setText("ЧСС <  60 уд/мин");
    wavePacketText->setFont(QFont(font().family(), 10));


    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.22;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.46;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.11;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.69;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.22;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.46;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.11;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 4.0;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);

    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::fun_training_mode_pathology2()
{
    qDebug() << "fun_training_mode_pathology2";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭКГ. Тахикардия") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.04;
//    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.22;
//    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.35;
//    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.55;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.60;
//    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.64;
//    data_pqrst.dur = 0;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.74;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.82;
//    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.84;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.89;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.92;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.95;
//    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.15;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.2;
//    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.24;
//    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.34;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.42;
//    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.44;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.49;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.52;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.55;
//    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.75;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.8;
//    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.84;
//    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 1.94;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.02;
//    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.09;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.12;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.15;
//    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 2.35;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.25;
    data_pqrst.amp_shift = 0.75;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 2.4;
//    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);

    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::fun_training_form_norm()
{
    qDebug() << "fun_training_form_norm";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭКГ. Кардиоцикл") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.22;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.46;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.11;
    data_pqrst.amp = 0.15;
    data_pqrst.amp_shift = 0.65;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.0;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);

    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::fun_training_form_pathology1()
{
    qDebug() << "fun_training_form_pathology1";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭКГ. Р-зубец отрицательный") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = -0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.24;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
//    data_pqrst.name = "Q зубец";
//    data_pqrst.sig = 1;
//    data_pqrst.end = 0.24;
//    data_pqrst.dur = 0.04;
//    data_pqrst.time_shift = 0;
//    data_pqrst.amp = 0.2;
//    data_pqrst.amp_shift = 0.5;
//    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.32;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.46;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.11;
    data_pqrst.amp = 0.15;
    data_pqrst.amp_shift = 0.65;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.0;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);


    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::fun_training_form_pathology2()
{
    qDebug() << "fun_training_form_pathology2";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭКГ. Двугорбый (двухфазный) P –зубец") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 2;
    data_pqrst.end = 0.23;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.09;
    data_pqrst.amp = 0.19;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.26;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.28;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.33;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.08;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.34;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.00;
    data_pqrst.amp = 0.0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.5;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.03;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.42;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1;
    data_pqrst.dur = 0.38;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);

    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);
    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::fun_training_form_pathology3()
{
    qDebug() << "fun_training_form_pathology3";
    v_data_pqrst.clear();
    ui->label_plot->setText( QString::fromUtf8("ЭКГ. Патология сегмента S-T") );
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));

    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.14;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.22;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.24;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.2;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "R зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.29;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.04;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.31;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.59;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.25;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.66;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.01;
    data_pqrst.amp = 0.16;
    data_pqrst.amp_shift = 0.34;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1.0;
    data_pqrst.dur = 0.34;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.5;
    v_data_pqrst.push_back(data_pqrst);

    bool in = noEdit;
    noEdit = true;
    ui->dsb_sig_amp->setValue(1);
    int k = v_data_pqrst.size();
    ui->tableWidget->setRowCount(k);

    for (int i=0; i<k; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(v_data_pqrst.at(i).name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->cb_pqrst->itemText(v_data_pqrst.at(i).sig)));
    }

    ui->tableWidget->selectRow(0);

    int x_max = v_data_pqrst.at(k-1).end * 100 + 0.1;
    ui->sliderX->setMaximum(x_max);
    ui->sliderX->setValue(x_max);

    if (!in) noEdit = false;
    if (ui->action_view_play->isChecked()) playPlot();
    else changeSig();
}

void Simulator::setVisionCombobox(bool in)
{
    if(isTraining){
    ui->label_mod->setVisible(in);
    ui->label_vid->setVisible(in);
    ui->m_comboBox_mod->setVisible(in);
    ui->m_comboBox_vid->setVisible(in);
    if(!in)
        ui->m_comboBox_vid->setCurrentIndex(0);
    }
}

void Simulator::setRand(double last, double first, int count)
{
    const int N = 1000;
    double X;
    double Y;
    int i = 0.01 * ui->sliderX0->value() * N;
    int end = 0.01 * (ui->sliderX0->value() + ui->sliderX->value()) * N;
    while (i <= end) {
        X = (double)i / N;
        double l;
        Y = ui->dsb_sig_amp->value() * 2 * modf(X * ui->dsb_sig_frec->value(),&l);
        if (Y > ui->dsb_sig_amp->value())
            Y = ui->dsb_sig_amp->value() * 2 - Y;
        pointsX.push_back(X);
        pointsY.push_back(Y);
        i++;
    }//while
}

