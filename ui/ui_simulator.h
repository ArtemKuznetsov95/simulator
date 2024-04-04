/********************************************************************************
** Form generated from reading UI file 'simulator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATOR_H
#define UI_SIMULATOR_H

#include <../src/Utilities/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simulator
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *action_exit;
    QAction *action_start;
    QAction *action_rec;
    QAction *action_view_gen;
    QAction *action_view_play;
    QAction *action_training;
    QAction *action_playback;
    QAction *action_control;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_12;
    QWidget *m_widget_play;
    QHBoxLayout *horizontalLayout_14;
    QWidget *widget_gen;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_pushButton_ecg;
    QPushButton *m_pushButton_emg;
    QPushButton *m_pushButton_eeg;
    QListView *m_listView_diogram;
    QWidget *widget_sig;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *gb_sig_amp;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *dsb_sig_amp;
    QGroupBox *gb_sig_frec;
    QGridLayout *gridLayout;
    QDoubleSpinBox *dsb_sig_frec;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_pqrst;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidget;
    QWidget *widget_edit_row;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_begin;
    QLabel *label_begin_val;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_dur;
    QDoubleSpinBox *dsb_dur;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_end;
    QDoubleSpinBox *dsb_end;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_amp;
    QDoubleSpinBox *dsb_amp;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_time_shift;
    QDoubleSpinBox *dsb_time_shift;
    QLabel *label_uch;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_amp_shift;
    QDoubleSpinBox *dsb_amp_shift;
    QHBoxLayout *horizontalLayout;
    QLabel *label_vid_uch;
    QComboBox *cb_pqrst;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_add;
    QPushButton *pb_del;
    QPushButton *pb_edit;
    QWidget *w1;
    QVBoxLayout *verticalLayout;
    QComboBox *cbNameSig;
    QCustomPlot *plot;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_sliderX0;
    QSlider *sliderX0;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_sliderX;
    QSlider *sliderX;
    QStackedWidget *m_stackedWidget;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menu_action;
    QMenu *menu_view;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Simulator)
    {
        if (Simulator->objectName().isEmpty())
            Simulator->setObjectName(QString::fromUtf8("Simulator"));
        Simulator->resize(1472, 880);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Simulator->sizePolicy().hasHeightForWidth());
        Simulator->setSizePolicy(sizePolicy);
        Simulator->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graph.png"), QSize(), QIcon::Normal, QIcon::Off);
        Simulator->setWindowIcon(icon);
        action_open = new QAction(Simulator);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon1);
        action_open->setIconVisibleInMenu(true);
        action_save = new QAction(Simulator);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon2);
        action_save->setIconVisibleInMenu(true);
        action_exit = new QAction(Simulator);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon3);
        action_exit->setIconVisibleInMenu(true);
        action_start = new QAction(Simulator);
        action_start->setObjectName(QString::fromUtf8("action_start"));
        action_start->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_start->setIcon(icon4);
        action_start->setIconVisibleInMenu(true);
        action_rec = new QAction(Simulator);
        action_rec->setObjectName(QString::fromUtf8("action_rec"));
        action_rec->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_rec->setIcon(icon5);
        action_rec->setIconVisibleInMenu(true);
        action_view_gen = new QAction(Simulator);
        action_view_gen->setObjectName(QString::fromUtf8("action_view_gen"));
        action_view_gen->setCheckable(true);
        action_view_gen->setChecked(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/lines.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_view_gen->setIcon(icon6);
        action_view_gen->setIconVisibleInMenu(true);
        action_view_play = new QAction(Simulator);
        action_view_play->setObjectName(QString::fromUtf8("action_view_play"));
        action_view_play->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_view_play->setIcon(icon7);
        action_view_play->setIconVisibleInMenu(true);
        action_training = new QAction(Simulator);
        action_training->setObjectName(QString::fromUtf8("action_training"));
        action_training->setCheckable(true);
        action_training->setChecked(false);
        action_playback = new QAction(Simulator);
        action_playback->setObjectName(QString::fromUtf8("action_playback"));
        action_playback->setCheckable(true);
        action_playback->setChecked(true);
        action_control = new QAction(Simulator);
        action_control->setObjectName(QString::fromUtf8("action_control"));
        action_control->setCheckable(true);
        centralWidget = new QWidget(Simulator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_12 = new QHBoxLayout(centralWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setSizeConstraint(QLayout::SetMaximumSize);
        m_widget_play = new QWidget(centralWidget);
        m_widget_play->setObjectName(QString::fromUtf8("m_widget_play"));
        m_widget_play->setMinimumSize(QSize(300, 0));
        horizontalLayout_14 = new QHBoxLayout(m_widget_play);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        widget_gen = new QWidget(m_widget_play);
        widget_gen->setObjectName(QString::fromUtf8("widget_gen"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_gen->sizePolicy().hasHeightForWidth());
        widget_gen->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget_gen);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(widget_gen);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, -1, 1, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_pushButton_ecg = new QPushButton(widget);
        m_pushButton_ecg->setObjectName(QString::fromUtf8("m_pushButton_ecg"));
        m_pushButton_ecg->setCheckable(true);
        m_pushButton_ecg->setChecked(true);

        horizontalLayout_4->addWidget(m_pushButton_ecg);

        m_pushButton_emg = new QPushButton(widget);
        m_pushButton_emg->setObjectName(QString::fromUtf8("m_pushButton_emg"));
        m_pushButton_emg->setCheckable(true);

        horizontalLayout_4->addWidget(m_pushButton_emg);

        m_pushButton_eeg = new QPushButton(widget);
        m_pushButton_eeg->setObjectName(QString::fromUtf8("m_pushButton_eeg"));
        m_pushButton_eeg->setCheckable(true);

        horizontalLayout_4->addWidget(m_pushButton_eeg);


        verticalLayout_5->addLayout(horizontalLayout_4);

        m_listView_diogram = new QListView(widget);
        m_listView_diogram->setObjectName(QString::fromUtf8("m_listView_diogram"));

        verticalLayout_5->addWidget(m_listView_diogram);


        verticalLayout_2->addWidget(widget);

        widget_sig = new QWidget(widget_gen);
        widget_sig->setObjectName(QString::fromUtf8("widget_sig"));
        verticalLayout_3 = new QVBoxLayout(widget_sig);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gb_sig_amp = new QGroupBox(widget_sig);
        gb_sig_amp->setObjectName(QString::fromUtf8("gb_sig_amp"));
        gb_sig_amp->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(gb_sig_amp);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, -1, 0, 0);
        dsb_sig_amp = new QDoubleSpinBox(gb_sig_amp);
        dsb_sig_amp->setObjectName(QString::fromUtf8("dsb_sig_amp"));
        dsb_sig_amp->setSingleStep(0.010000000000000);

        gridLayout_2->addWidget(dsb_sig_amp, 0, 0, 1, 1);


        verticalLayout_4->addWidget(gb_sig_amp);

        gb_sig_frec = new QGroupBox(widget_sig);
        gb_sig_frec->setObjectName(QString::fromUtf8("gb_sig_frec"));
        gb_sig_frec->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(gb_sig_frec);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, 0);
        dsb_sig_frec = new QDoubleSpinBox(gb_sig_frec);
        dsb_sig_frec->setObjectName(QString::fromUtf8("dsb_sig_frec"));
        dsb_sig_frec->setSingleStep(0.010000000000000);

        gridLayout->addWidget(dsb_sig_frec, 0, 0, 1, 1);


        verticalLayout_4->addWidget(gb_sig_frec);


        verticalLayout_3->addLayout(verticalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        verticalLayout_2->addWidget(widget_sig);

        widget_pqrst = new QWidget(widget_gen);
        widget_pqrst->setObjectName(QString::fromUtf8("widget_pqrst"));
        gridLayout_5 = new QGridLayout(widget_pqrst);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget_pqrst);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 9)
            tableWidget->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(6, 1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(7, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(8, 1, __qtablewidgetitem28);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(130);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_5->addWidget(tableWidget, 2, 0, 1, 1);

        widget_edit_row = new QWidget(widget_pqrst);
        widget_edit_row->setObjectName(QString::fromUtf8("widget_edit_row"));
        gridLayout_4 = new QGridLayout(widget_edit_row);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_begin = new QLabel(widget_edit_row);
        label_begin->setObjectName(QString::fromUtf8("label_begin"));

        horizontalLayout_5->addWidget(label_begin);

        label_begin_val = new QLabel(widget_edit_row);
        label_begin_val->setObjectName(QString::fromUtf8("label_begin_val"));

        horizontalLayout_5->addWidget(label_begin_val);


        gridLayout_4->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_dur = new QLabel(widget_edit_row);
        label_dur->setObjectName(QString::fromUtf8("label_dur"));
        label_dur->setEnabled(false);

        horizontalLayout_7->addWidget(label_dur);

        dsb_dur = new QDoubleSpinBox(widget_edit_row);
        dsb_dur->setObjectName(QString::fromUtf8("dsb_dur"));
        dsb_dur->setEnabled(false);
        dsb_dur->setMinimum(0.010000000000000);
        dsb_dur->setSingleStep(0.010000000000000);
        dsb_dur->setValue(0.040000000000000);

        horizontalLayout_7->addWidget(dsb_dur);


        gridLayout_4->addLayout(horizontalLayout_7, 5, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_end = new QLabel(widget_edit_row);
        label_end->setObjectName(QString::fromUtf8("label_end"));

        horizontalLayout_6->addWidget(label_end);

        dsb_end = new QDoubleSpinBox(widget_edit_row);
        dsb_end->setObjectName(QString::fromUtf8("dsb_end"));
        dsb_end->setMinimum(0.010000000000000);
        dsb_end->setSingleStep(0.010000000000000);
        dsb_end->setValue(0.040000000000000);

        horizontalLayout_6->addWidget(dsb_end);


        gridLayout_4->addLayout(horizontalLayout_6, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_amp = new QLabel(widget_edit_row);
        label_amp->setObjectName(QString::fromUtf8("label_amp"));

        horizontalLayout_8->addWidget(label_amp);

        dsb_amp = new QDoubleSpinBox(widget_edit_row);
        dsb_amp->setObjectName(QString::fromUtf8("dsb_amp"));
        dsb_amp->setMinimum(-1000.000000000000000);
        dsb_amp->setMaximum(1000.000000000000000);
        dsb_amp->setSingleStep(0.010000000000000);
        dsb_amp->setValue(0.500000000000000);

        horizontalLayout_8->addWidget(dsb_amp);


        gridLayout_4->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_time_shift = new QLabel(widget_edit_row);
        label_time_shift->setObjectName(QString::fromUtf8("label_time_shift"));

        horizontalLayout_10->addWidget(label_time_shift);

        dsb_time_shift = new QDoubleSpinBox(widget_edit_row);
        dsb_time_shift->setObjectName(QString::fromUtf8("dsb_time_shift"));
        dsb_time_shift->setMinimum(-100.000000000000000);
        dsb_time_shift->setMaximum(100.000000000000000);
        dsb_time_shift->setSingleStep(0.010000000000000);

        horizontalLayout_10->addWidget(dsb_time_shift);


        gridLayout_4->addLayout(horizontalLayout_10, 6, 0, 1, 1);

        label_uch = new QLabel(widget_edit_row);
        label_uch->setObjectName(QString::fromUtf8("label_uch"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_uch->setFont(font);

        gridLayout_4->addWidget(label_uch, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_amp_shift = new QLabel(widget_edit_row);
        label_amp_shift->setObjectName(QString::fromUtf8("label_amp_shift"));

        horizontalLayout_9->addWidget(label_amp_shift);

        dsb_amp_shift = new QDoubleSpinBox(widget_edit_row);
        dsb_amp_shift->setObjectName(QString::fromUtf8("dsb_amp_shift"));
        dsb_amp_shift->setMinimum(-1000.000000000000000);
        dsb_amp_shift->setMaximum(100.000000000000000);
        dsb_amp_shift->setSingleStep(0.010000000000000);
        dsb_amp_shift->setValue(0.500000000000000);

        horizontalLayout_9->addWidget(dsb_amp_shift);


        gridLayout_4->addLayout(horizontalLayout_9, 8, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_vid_uch = new QLabel(widget_edit_row);
        label_vid_uch->setObjectName(QString::fromUtf8("label_vid_uch"));

        horizontalLayout->addWidget(label_vid_uch);

        cb_pqrst = new QComboBox(widget_edit_row);
        cb_pqrst->addItem(QString());
        cb_pqrst->addItem(QString());
        cb_pqrst->addItem(QString());
        cb_pqrst->addItem(QString());
        cb_pqrst->addItem(QString());
        cb_pqrst->addItem(QString());
        cb_pqrst->addItem(QString());
        cb_pqrst->setObjectName(QString::fromUtf8("cb_pqrst"));

        horizontalLayout->addWidget(cb_pqrst);


        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 9, 0, 1, 1);


        gridLayout_5->addWidget(widget_edit_row, 3, 0, 1, 1);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer);

        pb_add = new QPushButton(widget_pqrst);
        pb_add->setObjectName(QString::fromUtf8("pb_add"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_add->sizePolicy().hasHeightForWidth());
        pb_add->setSizePolicy(sizePolicy2);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_add->setIcon(icon8);

        horizontalLayout_20->addWidget(pb_add);

        pb_del = new QPushButton(widget_pqrst);
        pb_del->setObjectName(QString::fromUtf8("pb_del"));
        sizePolicy2.setHeightForWidth(pb_del->sizePolicy().hasHeightForWidth());
        pb_del->setSizePolicy(sizePolicy2);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_del->setIcon(icon9);

        horizontalLayout_20->addWidget(pb_del);

        pb_edit = new QPushButton(widget_pqrst);
        pb_edit->setObjectName(QString::fromUtf8("pb_edit"));
        sizePolicy2.setHeightForWidth(pb_edit->sizePolicy().hasHeightForWidth());
        pb_edit->setSizePolicy(sizePolicy2);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_edit->setIcon(icon10);
        pb_edit->setCheckable(true);

        horizontalLayout_20->addWidget(pb_edit);


        gridLayout_5->addLayout(horizontalLayout_20, 1, 0, 1, 1);


        verticalLayout_2->addWidget(widget_pqrst);


        horizontalLayout_14->addWidget(widget_gen);

        w1 = new QWidget(m_widget_play);
        w1->setObjectName(QString::fromUtf8("w1"));
        verticalLayout = new QVBoxLayout(w1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cbNameSig = new QComboBox(w1);
        cbNameSig->setObjectName(QString::fromUtf8("cbNameSig"));

        verticalLayout->addWidget(cbNameSig);

        plot = new QCustomPlot(w1);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setFont(font);

        verticalLayout->addWidget(plot);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_sliderX0 = new QLabel(w1);
        label_sliderX0->setObjectName(QString::fromUtf8("label_sliderX0"));

        horizontalLayout_3->addWidget(label_sliderX0);

        sliderX0 = new QSlider(w1);
        sliderX0->setObjectName(QString::fromUtf8("sliderX0"));
        sliderX0->setMaximum(999);
        sliderX0->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderX0);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_sliderX = new QLabel(w1);
        label_sliderX->setObjectName(QString::fromUtf8("label_sliderX"));

        horizontalLayout_2->addWidget(label_sliderX);

        sliderX = new QSlider(w1);
        sliderX->setObjectName(QString::fromUtf8("sliderX"));
        sliderX->setMinimum(1);
        sliderX->setMaximum(999);
        sliderX->setValue(10);
        sliderX->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderX);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 1);

        horizontalLayout_14->addWidget(w1);


        horizontalLayout_12->addWidget(m_widget_play);

        m_stackedWidget = new QStackedWidget(centralWidget);
        m_stackedWidget->setObjectName(QString::fromUtf8("m_stackedWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_stackedWidget->sizePolicy().hasHeightForWidth());
        m_stackedWidget->setSizePolicy(sizePolicy3);
        m_stackedWidget->setMinimumSize(QSize(0, 0));

        horizontalLayout_12->addWidget(m_stackedWidget);

        Simulator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Simulator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1472, 22));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_action = new QMenu(menuBar);
        menu_action->setObjectName(QString::fromUtf8("menu_action"));
        menu_view = new QMenu(menuBar);
        menu_view->setObjectName(QString::fromUtf8("menu_view"));
        Simulator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Simulator);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Simulator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Simulator);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Simulator->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_action->menuAction());
        menuBar->addAction(menu_view->menuAction());
        menu_file->addAction(action_open);
        menu_file->addSeparator();
        menu_file->addAction(action_exit);
        menu_action->addAction(action_playback);
        menu_action->addAction(action_training);
        menu_action->addAction(action_control);
        menu_view->addAction(action_view_gen);
        menu_view->addAction(action_view_play);

        retranslateUi(Simulator);
        QObject::connect(action_exit, SIGNAL(triggered()), Simulator, SLOT(close()));

        cb_pqrst->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Simulator);
    } // setupUi

    void retranslateUi(QMainWindow *Simulator)
    {
        Simulator->setWindowTitle(QCoreApplication::translate("Simulator", "Simulator", nullptr));
        action_open->setText(QCoreApplication::translate("Simulator", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        action_save->setText(QCoreApplication::translate("Simulator", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        action_exit->setText(QCoreApplication::translate("Simulator", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_start->setText(QCoreApplication::translate("Simulator", "\320\222\320\276\321\201\320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\320\265", nullptr));
        action_rec->setText(QCoreApplication::translate("Simulator", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        action_view_gen->setText(QCoreApplication::translate("Simulator", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
#if QT_CONFIG(tooltip)
        action_view_gen->setToolTip(QCoreApplication::translate("Simulator", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        action_view_play->setText(QCoreApplication::translate("Simulator", "\320\222\320\276\321\201\320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\320\265", nullptr));
        action_training->setText(QCoreApplication::translate("Simulator", "\320\236\320\261\321\203\321\207\320\265\320\275\320\270\320\265", nullptr));
        action_playback->setText(QCoreApplication::translate("Simulator", "\320\222\320\276\321\201\320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\320\265", nullptr));
        action_control->setText(QCoreApplication::translate("Simulator", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214", nullptr));
        m_pushButton_ecg->setText(QCoreApplication::translate("Simulator", "\320\255\320\232\320\223", nullptr));
        m_pushButton_emg->setText(QCoreApplication::translate("Simulator", "\320\255\320\234\320\223", nullptr));
        m_pushButton_eeg->setText(QCoreApplication::translate("Simulator", "\320\255\320\255\320\223", nullptr));
        gb_sig_amp->setTitle(QCoreApplication::translate("Simulator", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260, \320\274\320\222", nullptr));
        gb_sig_frec->setTitle(QCoreApplication::translate("Simulator", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260, \320\223\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Simulator", "\320\243\321\207\320\260\321\201\321\202\320\276\320\272 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Simulator", "\320\222\320\270\320\264 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Simulator", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Simulator", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Simulator", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Simulator", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Simulator", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Simulator", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Simulator", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Simulator", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Simulator", "8", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Simulator", "\320\264\320\276 \320\240 \320\267\321\203\320\261\321\206\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Simulator", "P \320\267\321\203\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(2, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Simulator", "PQ \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(2, 1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(3, 0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Simulator", "Q \320\267\321\203\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(3, 1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(4, 0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Simulator", "R \320\267\321\203\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(4, 1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(5, 0);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Simulator", "S \320\267\321\203\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(5, 1);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(6, 0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Simulator", "ST \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(6, 1);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(7, 0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Simulator", "T \320\267\321\203\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(7, 1);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(8, 0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("Simulator", "\320\277\320\276\321\201\320\273\320\265 T \320\267\321\203\320\261\321\206\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(8, 1);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_begin->setText(QCoreApplication::translate("Simulator", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        label_begin_val->setText(QCoreApplication::translate("Simulator", "0,00", nullptr));
        label_dur->setText(QCoreApplication::translate("Simulator", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_end->setText(QCoreApplication::translate("Simulator", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        label_amp->setText(QCoreApplication::translate("Simulator", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260", nullptr));
        label_time_shift->setText(QCoreApplication::translate("Simulator", "\320\241\320\264\320\262\320\270\320\263", nullptr));
        label_uch->setText(QCoreApplication::translate("Simulator", "\320\264\320\276 \320\240 \320\267\321\203\320\261\321\206\320\260", nullptr));
        label_amp_shift->setText(QCoreApplication::translate("Simulator", "\320\236\321\201\321\214", nullptr));
        label_vid_uch->setText(QCoreApplication::translate("Simulator", "\320\222\320\270\320\264 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", nullptr));
        cb_pqrst->setItemText(0, QCoreApplication::translate("Simulator", "\320\275\320\265\321\202", nullptr));
        cb_pqrst->setItemText(1, QCoreApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        cb_pqrst->setItemText(2, QCoreApplication::translate("Simulator", "\320\272\320\276\321\201\320\270\320\275\321\203\321\201\320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\275\321\213\320\271", nullptr));
        cb_pqrst->setItemText(3, QCoreApplication::translate("Simulator", "\320\272\320\276\320\273\320\276\320\272\320\276\320\273\320\276\320\276\320\261\321\200\320\260\320\267\320\275\321\213\320\271", nullptr));
        cb_pqrst->setItemText(4, QCoreApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", nullptr));
        cb_pqrst->setItemText(5, QCoreApplication::translate("Simulator", "\321\202\320\276\321\207\320\272\320\260", nullptr));
        cb_pqrst->setItemText(6, QCoreApplication::translate("Simulator", "\320\273\320\270\320\275\320\270\321\217", nullptr));

        label_sliderX0->setText(QCoreApplication::translate("Simulator", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        label_sliderX->setText(QCoreApplication::translate("Simulator", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        menu_file->setTitle(QCoreApplication::translate("Simulator", "\320\244\320\260\320\271\320\273", nullptr));
        menu_action->setTitle(QCoreApplication::translate("Simulator", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
        menu_view->setTitle(QCoreApplication::translate("Simulator", "\320\222\320\270\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simulator: public Ui_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
