#include "playback_form.h"
#include "ui_playback_form.h"

Playback_Form::Playback_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Playback_Form),
     modelDiogramList(new QStandardItemModel)
{
    ui->setupUi(this);

    QButtonGroup* gropButton = new QButtonGroup(this);
    gropButton->addButton(ui->m_pushButton_eeg);
    gropButton->addButton(ui->m_pushButton_ekg);
    gropButton->addButton(ui->m_pushButton_emg);

    m_plot = new Servise_plot(ui->widget);
    ui->widget->layout()->addWidget(m_plot);

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
        }
    });

    ui->m_listView_diogram->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->m_listView_diogram->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->m_pushButton_ekg->click();

//    connect(ui->m_horizontalSlider, &QSlider::valueChanged, m_plot, &Servise_plot::plotX);
}

Playback_Form::~Playback_Form()
{
    delete ui;
}

void Playback_Form::on_m_pushButton_ekg_clicked()
{
    m_currentSignal = ListData::SignalEFS::EKG;
    show_DiogramEKG_Norm();
    QModelIndex firstIndex = modelDiogramList->index(0, 0);
    ui->m_listView_diogram->setCurrentIndex(firstIndex);
    ui->m_listView_diogram->clicked(firstIndex);
}


void Playback_Form::on_m_pushButton_emg_clicked()
{
    m_currentSignal = ListData::SignalEFS::EMG;
    show_DiogramEMG_Norm();
    QModelIndex firstIndex = modelDiogramList->index(0, 0);
    ui->m_listView_diogram->setCurrentIndex(firstIndex);
    ui->m_listView_diogram->clicked(firstIndex);
}


void Playback_Form::on_m_pushButton_eeg_clicked()
{
    m_currentSignal = ListData::SignalEFS::EEG;
    show_DiogramEEG_Norm();
    QModelIndex firstIndex = modelDiogramList->index(0, 0);
    ui->m_listView_diogram->setCurrentIndex(firstIndex);
    ui->m_listView_diogram->clicked(firstIndex);
}

void Playback_Form::show_DiogramEKG_Norm()
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

void Playback_Form::show_DiogramEMG_Norm()
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

void Playback_Form::show_DiogramEEG_Norm()
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

void Playback_Form::startGen(bool in)
{
    m_plot->startGen(in);
}

void Playback_Form::setIsPlay(bool in)
{
    m_plot->setIsPlay(in);
}


