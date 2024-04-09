#include <Utilities/delegate.h>
#include <Simulator/simulator.h>
#include <ui_simulator.h>


Simulator::Simulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulator),
    m_widgetControl(new ControlMode_Form),
    m_widgetTraining(new Tratining_Form)
{
    ui->setupUi(this);

//#ifdef ANDROID
//    ui->pb_add->setMinimumSize(64,64);
//    ui->pb_add->setMaximumSize(64,64);

//    ui->pb_del->setMinimumSize(64,64);
//    ui->pb_del->setMaximumSize(64,64);

//    ui->pb_edit->setMinimumSize(64,64);
//    ui->pb_edit->setMaximumSize(64,64);
//#endif

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

    ui->tableWidget->setItemDelegateForColumn(1, new NonEditDelegate());

    ui->plot->addGraph();
    ui->plot->axisRect()->setupFullAxesBox(true);
    ui->plot->xAxis->setRange(0, 1, Qt::AlignLeft);
    ui->plot->xAxis->setLabel(trUtf8("t,с"));
    ui->plot->yAxis->setLabel(trUtf8("U,мВ"));    

    noEdit=true;
    viewPlay(false);
    noEdit=false;
    edit_row();    
    timer = new QTimer(this);
    modelDiogramList = new QStandardItemModel();
    QActionGroup * actiution_menu = new QActionGroup(this);
    actiution_menu->addAction(ui->action_playback);
    actiution_menu->addAction(ui->action_training);
    actiution_menu->addAction(ui->action_control);

    QButtonGroup* gropButton = new QButtonGroup(this);
    gropButton->addButton(ui->m_pushButton_eeg);
    gropButton->addButton(ui->m_pushButton_ecg);
    gropButton->addButton(ui->m_pushButton_emg);

    connect(ui->action_open,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->cbNameSig,SIGNAL(currentIndexChanged(int)),this,SLOT(playPlot()));
    connect(ui->action_view_play,SIGNAL(toggled(bool)),this,SLOT(viewPlay(bool)));
    connect(ui->sliderX,SIGNAL(valueChanged(int)),this,SLOT(plotX(int)));
    connect(ui->sliderX0,SIGNAL(valueChanged(int)),this,SLOT(plotX0(int)));
    connect(ui->dsb_sig_frec,SIGNAL(valueChanged(double)),this,SLOT(changeSig()));
    connect(ui->dsb_sig_amp,SIGNAL(valueChanged(double)),this,SLOT(changeSig()));
    connect(ui->pb_add,SIGNAL(pressed()),this,SLOT(add_row()));
    connect(ui->pb_del,SIGNAL(pressed()),this,SLOT(del_row()));
    connect(ui->pb_edit,SIGNAL(pressed()),this,SLOT(edit_row()));
    connect(ui->tableWidget,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(changeList(int,int,int,int)));
    connect(ui->cb_pqrst,SIGNAL(currentIndexChanged(int)),this,SLOT(changeDataSig(int)));
    connect(ui->dsb_end,SIGNAL(valueChanged(double)),this,SLOT(changeDataEnd(double)));
    connect(ui->dsb_dur,SIGNAL(valueChanged(double)),this,SLOT(changeDataDur(double)));
    connect(ui->dsb_amp,SIGNAL(valueChanged(double)),this,SLOT(changeDataAmp(double)));
    connect(ui->dsb_amp_shift,SIGNAL(valueChanged(double)),this,SLOT(changeDataAmpSh(double)));
    connect(ui->dsb_time_shift,SIGNAL(valueChanged(double)),this,SLOT(changeDataTimeSh(double)));
    connect(ui->action_start,SIGNAL(toggled(bool)),this,SLOT(startGen(bool)));    
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlot()));
    connect(ui->action_playback,SIGNAL(triggered()),this,SLOT(switchingModesPlayback()));
    connect(ui->action_training,SIGNAL(triggered()),this,SLOT(switchingModesTraining()));
    connect(ui->action_control,SIGNAL(triggered()),this,SLOT(switchingModesControl()));
    connect(ui->m_listView_diogram, &QListView::clicked, [this](){
        auto index = ui->m_listView_diogram->currentIndex();
        QStandardItemModel* model = static_cast<QStandardItemModel* >(ui->m_listView_diogram->model());
        QStandardItem* item = model->item(index.row());
        switch (m_currentSignal) {
        case ListData::SignalEFS::EKG:
            sl_showPlot_DiogramEKG(static_cast<ListData::DiogramEKG>(item->data().toInt()));
            break;
        case ListData::SignalEFS::EMG:
            sl_showPlot_DiogramEMG(static_cast<ListData::DiogramEMG>(item->data().toInt()));
            break;
        case ListData::SignalEFS::EEG:
            sl_showPlot_DiogramEEG(static_cast<ListData::DiogramEEG>(item->data().toInt()));
            break;
        }
    });

    ui->m_stackedWidget->addWidget(m_widgetTraining);
    ui->m_stackedWidget->addWidget(m_widgetControl);

    switchingModesPlayback();
}

Simulator::~Simulator()
{
    delete ui;
}

void Simulator::show_DiogramEKG_Norm()
{
    modelDiogramList->clear();
    auto map = ListData::getMapDiogramEKG_FORM_Norm();
    QMap<ListData::DiogramEKG, QString>::iterator it;

    int i = 1;
    for(it = map.begin(); it != map.end(); it++) {
        QStandardItem* item = new QStandardItem();
        item->setText(QString("%1. ").arg(QString::number(i)) + it.value());
        item->setData(it.key());
        modelDiogramList->appendRow(item);
        ++i;
    }

    ui->m_listView_diogram->setModel(modelDiogramList);
}

void Simulator::show_DiogramEMG_Norm()
{
    modelDiogramList->clear();
    auto map = ListData::getMapDiogramEMG_Norm();
    QMap<ListData::DiogramEMG, QString>::iterator it;

    int i = 1;
    for(it = map.begin(); it != map.end(); it++) {
        QStandardItem* item = new QStandardItem();
        item->setText(QString("%1. ").arg(QString::number(i)) + it.value());
        item->setData(it.key());
        modelDiogramList->appendRow(item);
        ++i;
    }
    ui->m_listView_diogram->setModel(modelDiogramList);
}

void Simulator::show_DiogramEEG_Norm()
{
    modelDiogramList->clear();
    auto map = ListData::getMapDiogramEEG_Norm();
    QMap<ListData::DiogramEEG, QString>::iterator it;

    int i = 1;
    for(it = map.begin(); it != map.end(); it++) {
        QStandardItem* item = new QStandardItem();
        item->setText(QString("%1. ").arg(QString::number(i)) + it.value());
        item->setData(it.key());
        modelDiogramList->appendRow(item);
        ++i;
    }
    ui->m_listView_diogram->setModel(modelDiogramList);
}


void Simulator::openFile() {
#ifdef linux
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
#endif
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
    double amp_max = 0.1 * ui->dsb_sig_amp->value();
    double x_visible = 5;

    ui->widget_pqrst->setVisible(true);
    ui->widget_sig->setVisible(false);

    pqrstPlot();

    for (int k = 0; k < pointsY.size(); k++){
        double amp_i = pointsY.at(k);
        if (amp_i > amp_max) amp_max = amp_i;
        if (amp_i < amp_min) amp_min = amp_i;
        if (!amp_min) amp_min = amp_max;
        if (!amp_max) amp_max = amp_min;
    }

    x_visible = v_data_pqrst.last().end;

    noEdit = true;
    int x_vis = x_visible * 100 + 0.1;
    if (ui->sliderX0->value() >= x_vis) ui->sliderX0->setValue(0);
    int x_max = x_vis - ui->sliderX0->value();
    if (ui->sliderX->value() > x_max) ui->sliderX->setValue(x_max);
    ui->sliderX->setMaximum(x_max);
    ui->sliderX0->setMaximum(x_visible * 100 + 0.1 - ui->sliderX->value());
    noEdit = false;

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

    case 6: {
        ui->dsb_amp->setValue(dur);
        ui->dsb_dur->setValue(dur);
        ui->dsb_time_shift->setValue(0);
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


void Simulator::pqrstPlot()
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
                double X1 = (i-1)/N;
                double Y1 = Y;
                double BC = (X - X1) * tan(v_data_pqrst[k].amp);

                Y = Y1 + BC;
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

void Simulator::playPlot()
{
    qDebug() << "playPlot()";
    int i = ui->cbNameSig->currentIndex();
    if (i < 0 || noEdit) return;

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
    if (in) timer->start(60);
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
    if(m_widgetControl->getStart()) {
        ui->m_widget_play->hide();
        ui->m_stackedWidget->show();
        ui->m_stackedWidget->setCurrentIndex(0);

        this->setWindowTitle(QString("Симулятор. Режим: %1").arg(ui->action_training->text()));

        setPlayEditor(false);
    } else {
        ui->action_control->setChecked(true);
    }
}

void Simulator::switchingModesPlayback()
{
    if(m_widgetControl->getStart()) {
        ui->m_widget_play->show();
        ui->m_stackedWidget->hide();
        ui->m_pushButton_ecg->click();

        this->setWindowTitle(QString("Симулятор. Режим: %1").arg(ui->action_playback->text()));
        setPlayEditor(true);
    }
    else {
            ui->action_control->setChecked(true);
        }
}

void Simulator::switchingModesControl()
{
    ui->m_widget_play->hide();
    ui->m_stackedWidget->show();
    ui->m_stackedWidget->setCurrentIndex(1);

    this->setWindowTitle(QString("Симулятор. Режим: %1").arg(ui->action_control->text()));
    setPlayEditor(false);
}

void Simulator::on_m_pushButton_ecg_clicked()
{
    m_currentSignal = ListData::SignalEFS::EKG;
    show_DiogramEKG_Norm();
    QModelIndex firstIndex = modelDiogramList->index(0, 0);
    ui->m_listView_diogram->setCurrentIndex(firstIndex);
    ui->m_listView_diogram->clicked(firstIndex);
}


void Simulator::on_m_pushButton_emg_clicked()
{
    m_currentSignal = ListData::SignalEFS::EMG;
    show_DiogramEMG_Norm();
    QModelIndex firstIndex = modelDiogramList->index(0, 0);
    ui->m_listView_diogram->setCurrentIndex(firstIndex);
    ui->m_listView_diogram->clicked(firstIndex);
}


void Simulator::on_m_pushButton_eeg_clicked()
{
    m_currentSignal = ListData::SignalEFS::EEG;
    show_DiogramEEG_Norm();
    QModelIndex firstIndex = modelDiogramList->index(0, 0);
    ui->m_listView_diogram->setCurrentIndex(firstIndex);
    ui->m_listView_diogram->clicked(firstIndex);
}

void Simulator::show_DiogramEKG_FORM_Norm()
{
    v_data_pqrst.clear();
    _data_pqrst data_pqrst;
    data_pqrst.name = "до P зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.12;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "P зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.2;
    data_pqrst.dur = 0.16;
    data_pqrst.time_shift = -0.04;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "PQ интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.27;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "Q зубец";
    data_pqrst.sig = 6;
    data_pqrst.end = 0.3;
    data_pqrst.amp = -9.43;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "QR интервал";
    data_pqrst.sig = 6;
    data_pqrst.end = 0.33;
    data_pqrst.amp = 78.62;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "RS интервал";
    data_pqrst.sig = 6;
    data_pqrst.end = 0.36;
    data_pqrst.amp = -9.51;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "S зубец";
    data_pqrst.sig = 6;
    data_pqrst.end = 0.38;
    data_pqrst.amp = 78.57;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "ST интервал";
    data_pqrst.sig = 4;
    data_pqrst.end = 0.48;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "T зубец";
    data_pqrst.sig = 1;
    data_pqrst.end = 0.64;
    data_pqrst.dur = 0.32;
    data_pqrst.time_shift = 0.16;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.29;
    v_data_pqrst.push_back(data_pqrst);
    data_pqrst.name = "после T зубца";
    data_pqrst.sig = 4;
    data_pqrst.end = 1;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0;
    data_pqrst.amp_shift = 0.29;
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

void Simulator::show_DiogramEMG_Norm_plot()
{
    v_data_pqrst.clear();
    _data_pqrst data_pqrst;

    //Количество отрезков
    int count = 500;
    int start = 10;
    int end = 30;

    srand(time(NULL));
    for(int i = 1; i <= count; ++i) {
        if(i % 23 == 0 || i % 22 == 0) {
            start = 40;
            end = 50;
        } else {
            start = 10;
            end = 30;
        }

        double x = rand() % (end - start +1) + start;
        data_pqrst.name = QString("Интервал-%1").arg(QString::number(i));
        data_pqrst.sig = 5;



        if(i % 2 == 0) {
            x = 50 + x;

        } else {
            x = 50 - x;
        }

#ifdef linux
        data_pqrst.end = (double)i/1000;
        data_pqrst.amp = (double)x/10;
#else
        data_pqrst.end = (double)i/250;
        data_pqrst.amp = (double)x/1000;
#endif
        v_data_pqrst.push_back(data_pqrst);
    }

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

void Simulator::show_DiogramEEG_Norm_1()
{
    v_data_pqrst.clear();
    _data_pqrst data_pqrst;

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.16;
    data_pqrst.dur = 0.08;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.3;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = 0.02;
    data_pqrst.amp = 0.08;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.45;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.59;
    data_pqrst.dur = 0.14;
    data_pqrst.time_shift = -0.18;
    data_pqrst.amp = 0.08;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.65;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 0.008;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.8;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.1;
    data_pqrst.amp = -0.08;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.9;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.1;
    data_pqrst.amp = -0.05;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 1;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.1;
    data_pqrst.amp = 0.05;
    data_pqrst.amp_shift = 0;
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

void Simulator::show_DiogramEEG_Norm_2()
{
    v_data_pqrst.clear();
    _data_pqrst data_pqrst;

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.02;
    data_pqrst.dur = 0.02;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.04;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -15;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.1;
    data_pqrst.dur = 0.06;
    data_pqrst.time_shift = -0.02;
    data_pqrst.amp = 5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.12;
    data_pqrst.amp = 17.12;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.13;
    data_pqrst.amp = 8.30;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.14;
    data_pqrst.amp = 13.48;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.15;
    data_pqrst.amp = -17.20;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.16;
    data_pqrst.amp = 14.04;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.17;
    data_pqrst.amp = -17.18;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.18;
    data_pqrst.amp = 32.92;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.19;
    data_pqrst.amp = -32.94;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.21;
    data_pqrst.amp = 14.02;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.22;
    data_pqrst.amp = 8.43;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.23;
    data_pqrst.amp = 16.82;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 6;
    data_pqrst.end = 0.24;
    data_pqrst.amp = -1.43;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.28;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -13;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.32;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.4;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -13;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.44;
    data_pqrst.dur = 0.02;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.48;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -13;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.54;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -20;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.59;
    data_pqrst.dur = 0.02;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.65;
    data_pqrst.dur = 0.03;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 20;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.68;
    data_pqrst.dur = 0.03;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 15;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.72;
    data_pqrst.dur = 0.03;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.76;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.042;
    data_pqrst.amp = -20;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.81;
    data_pqrst.dur = 0.03;
    data_pqrst.time_shift = 0.06;
    data_pqrst.amp = 5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.87;
    data_pqrst.dur = 0.04;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 20;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.915;
    data_pqrst.dur = 0.03;
    data_pqrst.time_shift = 0.06;
    data_pqrst.amp = -5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);


    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.965;
    data_pqrst.dur = 0.03;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = 20;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 5;
    data_pqrst.end = 0.985;
    data_pqrst.amp = -5;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 1;
    data_pqrst.dur = 0.02;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 5;
    data_pqrst.amp_shift = 0;
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

void Simulator::show_DiogramEEG_Norm_3()
{
    v_data_pqrst.clear();
    _data_pqrst data_pqrst;

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.1;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.1;
    data_pqrst.amp = -20;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.25;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = -5;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.35;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.15;
    data_pqrst.amp = -20;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.45;
    data_pqrst.dur = 0.1;
    data_pqrst.time_shift = 0.0;
    data_pqrst.amp = 10;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.65;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = -10;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 0.88;
    data_pqrst.dur = 0.15;
    data_pqrst.time_shift = -0.025;
    data_pqrst.amp = 50;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 1.06;
    data_pqrst.dur = 0.2;
    data_pqrst.time_shift = -0.14;
    data_pqrst.amp = 20;
    data_pqrst.amp_shift = 0;
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

void Simulator::show_DiogramEEG_Norm_4()
{
    v_data_pqrst.clear();
    _data_pqrst data_pqrst;

    //Количество отрезков
    int count = 1000;
    int start = 2;
    int end = 15;

    srand(time(NULL));
    for(int i = 0; i <= count; ++i) {
        double x = rand() % (end - start +1) + start;
        data_pqrst.name = QString("Интервал-%1").arg(QString::number(i));
        data_pqrst.sig = 5;


        if(i % 2 == 0) {
            x = 15 + x;

        } else {
            x = 15 - x;
        }
#ifdef linux
        data_pqrst.end = (double)i/1000;
        data_pqrst.amp = (double)x/10;
#else
        data_pqrst.end = (double)i/250;
        data_pqrst.amp = (double)x/1000;
#endif
        v_data_pqrst.push_back(data_pqrst);
    }

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

void Simulator::show_DiogramEEG_Norm_5()
{
    v_data_pqrst.clear();
    _data_pqrst data_pqrst;

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 1.85;
    data_pqrst.dur = 3.8;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 1;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 2.2;
    data_pqrst.dur = 0.84;
    data_pqrst.time_shift = 0.39;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 2.8;
    data_pqrst.dur = 2;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.3;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 3.2;
    data_pqrst.dur = 0.88;
    data_pqrst.time_shift = 0.33;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.2;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 4.75;
    data_pqrst.dur = 3.8;
    data_pqrst.time_shift = 0.05;
    data_pqrst.amp = 0.8;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 5.3;
    data_pqrst.dur = 0.9;
    data_pqrst.time_shift = 0.33;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0.24;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 6.85;
    data_pqrst.dur = 3.8;
    data_pqrst.time_shift = 0;
    data_pqrst.amp = 0.6;
    data_pqrst.amp_shift = 0;
    v_data_pqrst.push_back(data_pqrst);

    data_pqrst.name = QString("Зубец - %1").arg(QString::number(v_data_pqrst.count()));
    data_pqrst.sig = 1;
    data_pqrst.end = 7.23;
    data_pqrst.dur = 0.9;
    data_pqrst.time_shift = 0.47;
    data_pqrst.amp = 0.1;
    data_pqrst.amp_shift = 0;
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

void Simulator::setPlayEditor(bool in)
{
    if(ui->action_start->isChecked())
        ui->action_start->setChecked(in);
    ui->action_start->setEnabled(in);
    ui->action_open->setEnabled(in);
    ui->action_view_gen->setEnabled(in);
    ui->action_view_play->setEnabled(in);
}


void Simulator::sl_showPlot_DiogramEKG(ListData::DiogramEKG type)
{
    switch (type) {
    case ListData::EKG_NORM_2:
        show_DiogramEKG_FORM_Norm();
        break;
    default:
        break;
    }
}

void Simulator::sl_showPlot_DiogramEMG(ListData::DiogramEMG type)
{
    switch (type) {
    case ListData::EMG_NORM:
        show_DiogramEMG_Norm_plot();
        break;
    default:
        break;
    }
}

void Simulator::sl_showPlot_DiogramEEG(ListData::DiogramEEG type)
{
    switch (type) {
    case ListData::EEG_NORM_1:
        show_DiogramEEG_Norm_1();
        break;
    case ListData::EEG_NORM_2:
        show_DiogramEEG_Norm_2();
        break;
    case ListData::EEG_NORM_3:
        show_DiogramEEG_Norm_3();
        break;
    case ListData::EEG_NORM_4:
        show_DiogramEEG_Norm_4();
        break;
    case ListData::EEG_NORM_5:
        show_DiogramEEG_Norm_5();
        break;
    default:
        break;
    }
}

