#include "tratining_form.h"
#include "ui_tratining_form.h"

Tratining_Form::Tratining_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tratining_Form),
    modelDiogramList(new QStandardItemModel)

{
    ui->setupUi(this);

    m_plot = new Servise_plot(this);
    ui->widget->layout()->addWidget(m_plot);

    QButtonGroup* gropButton = new QButtonGroup(this);
    gropButton->addButton(ui->m_pushButton_eeg);
    gropButton->addButton(ui->m_pushButton_ekg);
    gropButton->addButton(ui->m_pushButton_emg);

    gropRadioButtonMode = new QButtonGroup(this);
    gropRadioButtonMode->addButton(ui->m_radioButton_beat);
    gropRadioButtonMode->addButton(ui->m_radioButton_form);

    gropRadioButtonVid = new QButtonGroup(this);
    gropRadioButtonVid->addButton(ui->m_radioButton_norm);
    gropRadioButtonVid->addButton(ui->m_radioButton_pathology);

    connect(ui->m_pushButton_ekg, &QPushButton::clicked, [this] () {
        m_currentSignal = ListData::SignalEFS::EKG;
        ui->m_groupBox_mode->setVisible(true);
        ui->m_radioButton_beat->click();
        ui->m_radioButton_norm->click();

    });
    connect(ui->m_pushButton_emg, &QPushButton::clicked, [this] () {
        m_currentSignal = ListData::SignalEFS::EMG;
        ui->m_groupBox_mode->setVisible(false);
        ui->m_radioButton_norm->click();
    });
    connect(ui->m_pushButton_eeg, &QPushButton::clicked, [this] () {
        m_currentSignal = ListData::SignalEFS::EEG;
        ui->m_groupBox_mode->setVisible(false);
        ui->m_radioButton_norm->click();
    });

    connect(ui->m_radioButton_beat, &QRadioButton::clicked, this, &Tratining_Form::sl_selectDirection);
    connect(ui->m_radioButton_form, &QRadioButton::clicked, this, &Tratining_Form::sl_selectDirection);
    connect(ui->m_radioButton_norm, &QRadioButton::clicked, this, &Tratining_Form::sl_selectDirection);
    connect(ui->m_radioButton_pathology, &QRadioButton::clicked, this, &Tratining_Form::sl_selectDirection);

    ui->m_listView_diogram->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->m_listView_diogram->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->m_listView_diogram, &QListView::clicked, [this](){
        auto index = ui->m_listView_diogram->currentIndex();
        QStandardItemModel* model = static_cast<QStandardItemModel* >(ui->m_listView_diogram->model());
        QStandardItem* item = model->item(index.row());
        switch (m_currentSignal) {
        case ListData::SignalEFS::EKG:
            m_plot->sl_showPlot_DiogramEKG(static_cast<ListData::DiogramEKG>(item->data().toInt()));
            break;
        case ListData::SignalEFS::EMG:
            m_plot->sl_showPlot_DiogramEMG(static_cast<ListData::DiogramEMG>(item->data().toInt()));
            break;
        case ListData::SignalEFS::EEG:
            m_plot->sl_showPlot_DiogramEEG(static_cast<ListData::DiogramEEG>(item->data().toInt()));
            break;
        case ListData::SignalEFS::TEST:
            break;
        }
    });
    connect(ui->m_comboBox_noise, SIGNAL(currentIndexChanged(int)), this, SLOT(sl_selectDirection()));
    this->updateComboBox_noise();

    ui->m_pushButton_ekg->click();
}

Tratining_Form::~Tratining_Form()
{
    delete ui;
}

void Tratining_Form::show_DiogramEKG_BEAT_Norm()
{
    modelDiogramList->clear();
    auto map = ListData::getMapDiogramEKG_BEAT_Norm();
    QMap<ListData::DiogramEKG, QString>::iterator it;

    int i = 1;
    for(it = map.begin(); it != map.end(); it++) {
        QStandardItem* item = new QStandardItem();
        item->setText(QString("%1. ").arg(QString::number(i)) + it.value());
        item->setData(it.key());
        modelDiogramList->appendRow(item);
        ++i;
    }
    ui-> m_listView_diogram->setModel(modelDiogramList);

}

void Tratining_Form::show_DiogramEKG_BEAT_Patology()
{
    modelDiogramList->clear();
    auto map = ListData::getMapDiogramEKG_BEAT_Patology();
    QMap<ListData::DiogramEKG, QString>::iterator it;

    int i = 1;
    for(it = map.begin(); it != map.end(); it++) {
        QStandardItem* item = new QStandardItem();
        item->setText(QString("%1. ").arg(QString::number(i)) + it.value());
        item->setData(it.key());
        modelDiogramList->appendRow(item);
        ++i;
    }
    ui-> m_listView_diogram->setModel(modelDiogramList);
}

void Tratining_Form::show_DiogramEKG_FORM_Norm()
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
    ui-> m_listView_diogram->setModel(modelDiogramList);
}

void Tratining_Form::show_DiogramEKG_FORM_Patology()
{
    modelDiogramList->clear();
    auto map = ListData::getMapDiogramEKG_FORM_Patology();
    QMap<ListData::DiogramEKG, QString>::iterator it;

    int i = 1;
    for(it = map.begin(); it != map.end(); it++) {
        QStandardItem* item = new QStandardItem();
        item->setText(QString("%1. ").arg(QString::number(i)) + it.value());
        item->setData(it.key());
        modelDiogramList->appendRow(item);
        ++i;
    }
    ui-> m_listView_diogram->setModel(modelDiogramList);
}

void Tratining_Form::show_DiogramEMG_Norm()
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
    ui-> m_listView_diogram->setModel(modelDiogramList);

}

void Tratining_Form::show_DiogramEMG_Patology()
{
    modelDiogramList->clear();
    auto map = ListData::getMapDiogramEMG_Patology();
    QMap<ListData::DiogramEMG, QString>::iterator it;

    int i = 1;
    for(it = map.begin(); it != map.end(); it++) {
        QStandardItem* item = new QStandardItem();
        item->setText(QString("%1. ").arg(QString::number(i)) + it.value());
        item->setData(it.key());
        modelDiogramList->appendRow(item);
        ++i;
    }
    ui-> m_listView_diogram->setModel(modelDiogramList);
}

void Tratining_Form::show_DiogramEEG_Norm()
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
    ui-> m_listView_diogram->setModel(modelDiogramList);
}

void Tratining_Form::show_DiogramEEG_Patology()
{
    modelDiogramList->clear();
    auto map = ListData::getMapDiogramEEG_Patology();
    QMap<ListData::DiogramEEG, QString>::iterator it;

    int i = 1;
    for(it = map.begin(); it != map.end(); it++) {
        QStandardItem* item = new QStandardItem();
        item->setText(QString("%1. ").arg(QString::number(i)) + it.value());
        item->setData(it.key());
        modelDiogramList->appendRow(item);
        ++i;
    }
    ui-> m_listView_diogram->setModel(modelDiogramList);
}


void Tratining_Form::sl_selectDirection()
{
    switch(m_currentSignal) {
    case ListData::SignalEFS::EKG:  sl_currentEKG();    break;
    case ListData::SignalEFS::EMG:  sl_currentEMG();    break;
    case ListData::SignalEFS::EEG:  sl_currentEEG();    break;
    case ListData::SignalEFS::TEST:     break;

    }

    QModelIndex firstIndex = modelDiogramList->index(0, 0);
    ui->m_listView_diogram->setCurrentIndex(firstIndex);
    ui->m_listView_diogram->clicked(firstIndex);
}

void Tratining_Form::sl_currentEKG()
{
    ListData::Mode mode =  ListData::Mode::BEAT;
    ListData::Vid vid = ListData::Vid::NORM;   

    if(ui->m_radioButton_beat->isChecked()) {
        mode =  ListData::Mode::BEAT;
    } else
        mode =  ListData::Mode::FORM;

    if(ui->m_radioButton_norm->isChecked())
        vid = ListData::Vid::NORM;
    else
        vid = ListData::Vid::PATOLOGY;


    sl_curentDiogramEKG(mode, vid);
}

void Tratining_Form::sl_currentEMG()
{
    ListData::Vid vid = ListData::Vid::NORM;

    if(ui->m_radioButton_norm->isChecked())
        vid = ListData::Vid::NORM;
    else
        vid = ListData::Vid::PATOLOGY;


    sl_curentDiogramEMG(vid);
}

void Tratining_Form::sl_currentEEG()
{
    ListData::Vid vid = ListData::Vid::NORM;

    if(ui->m_radioButton_norm->isChecked())
        vid = ListData::Vid::NORM;
    else
        vid = ListData::Vid::PATOLOGY;

    sl_curentDiogramEEG(vid);
}

void Tratining_Form::sl_curentDiogramEKG(ListData::Mode mode, ListData::Vid vid)
{
    switch (mode) {
    case ListData::Mode::BEAT:
        switch (vid) {
        case ListData::Vid::NORM:       show_DiogramEKG_BEAT_Norm();        break;
        case ListData::Vid::PATOLOGY:   show_DiogramEKG_BEAT_Patology();    break;
        }
        break;
    case ListData::Mode::FORM:
        switch (vid) {
        case ListData::Vid::NORM:       show_DiogramEKG_FORM_Norm();        break;
        case ListData::Vid::PATOLOGY:   show_DiogramEKG_FORM_Patology();    break;
        }
        break;
    }


}

void Tratining_Form::sl_curentDiogramEMG(ListData::Vid vid)
{
    switch (vid) {
    case ListData::Vid::NORM:       show_DiogramEMG_Norm();        break;
    case ListData::Vid::PATOLOGY:   show_DiogramEMG_Patology();    break;
    }
}

void Tratining_Form::sl_curentDiogramEEG(ListData::Vid vid)
{
    switch (vid) {
    case ListData::Vid::NORM:       show_DiogramEEG_Norm();        break;
    case ListData::Vid::PATOLOGY:   show_DiogramEEG_Patology();    break;
    }
}

void Tratining_Form::updateComboBox_noise()
{

}

void Tratining_Form::show_Noise()
{

}
void Tratining_Form::turnOn_noise_type1()
{
//    int N = pointsY.size();
//    double Y;
//    for (int k = 0; k < N; k++)
//    {
//        Y = ui->dsb_sig_amp->value() / 20 * 2 * ((rand()/((double)RAND_MAX)) - 0.5);
//        pointsY[k] = pointsY.at(k) + Y;
//    }
}
void Tratining_Form::turnOn_noise_type2()
{
//    int N = pointsY.size();
//    double X;
//    double Y1,Y2;
//    double delta = 1.5 * M_PI;
//    for (int k = 0; k < N; k++)
//    {
//        X = (double)(k * 0.01 * ui->sliderX->value()) / (N - 1) + 0.01 * ui->sliderX0->value();
//        Y1 = ui->dsb_sig_amp->value() / 20 * (sin(2 * M_PI * X * 50 + delta) / 2 + 0.5);
//        Y2 = 0;//ui->dsb_sig_amp->value() / 10 * (sin(M_2PI * X * 60 + delta) / 2 + 0.5);
//        pointsY[k] = pointsY.at(k) + Y1 + Y2;
//    }
}
void Tratining_Form::turnOn_noise_type3()
{
//    int N = pointsY.size();
//    double X;
//    double Y;
//    double delta = 1.5 * M_PI;
//    double ch = (double)(1 / (0.01 * (ui->sliderX->value()) + ui->sliderX0->value()));
//    for (int k = 0; k < N; k++)
//    {
//        X = (double)(k * 0.01 * ui->sliderX->value()) / (N - 1) + 0.01 * ui->sliderX0->value();
//        Y = ui->dsb_sig_amp->value() / 10 * (sin(2 * M_PI * X * ch + delta) / 2 + 0.5);
//        pointsY[k] = pointsY.at(k) + Y;
//    }
}
void Tratining_Form::turnOn_noise_type4()
{
    turnOn_noise_type1();
    turnOn_noise_type2();
}
void Tratining_Form::turnOn_noise_type5()
{
    turnOn_noise_type1();
    turnOn_noise_type3();
}
void Tratining_Form::turnOn_noise_type6()
{
    turnOn_noise_type2();
    turnOn_noise_type3();
}
void Tratining_Form::turnOn_noise_type7()
{
    turnOn_noise_type1();
    turnOn_noise_type2();
    turnOn_noise_type3();
}
