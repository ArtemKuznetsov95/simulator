/********************************************************************************
** Form generated from reading UI file 'simulator.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATOR_H
#define UI_SIMULATOR_H

#include <../src/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QWidget *widget_gen;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_noise;
    QComboBox *cb_noise;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_sig;
    QComboBox *cb_sig;
    QWidget *widget_sig;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *gb_sig_frec;
    QGridLayout *gridLayout;
    QDoubleSpinBox *dsb_sig_frec;
    QGroupBox *gb_sig_amp;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *dsb_sig_amp;
    QSpacerItem *verticalSpacer;
    QWidget *widget_pqrst;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_amp_shift;
    QDoubleSpinBox *dsb_amp_shift;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_amp;
    QDoubleSpinBox *dsb_amp;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_add;
    QPushButton *pb_del;
    QComboBox *cb_pqrst;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_end;
    QDoubleSpinBox *dsb_end;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_dur;
    QDoubleSpinBox *dsb_dur;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_begin;
    QLabel *label_begin_val;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_time_shift;
    QDoubleSpinBox *dsb_time_shift;
    QVBoxLayout *verticalLayout;
    QComboBox *cbNameSig;
    QLabel *label_plot;
    QCustomPlot *plot;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_sliderX0;
    QSlider *sliderX0;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_sliderX;
    QSlider *sliderX;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menu_action;
    QMenu *menu_view;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Simulator)
    {
        if (Simulator->objectName().isEmpty())
            Simulator->setObjectName(QStringLiteral("Simulator"));
        Simulator->resize(839, 655);
        QIcon icon;
        icon.addFile(QStringLiteral(":/graph.png"), QSize(), QIcon::Normal, QIcon::Off);
        Simulator->setWindowIcon(icon);
        action_open = new QAction(Simulator);
        action_open->setObjectName(QStringLiteral("action_open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/open.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon1);
        action_open->setIconVisibleInMenu(true);
        action_save = new QAction(Simulator);
        action_save->setObjectName(QStringLiteral("action_save"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon2);
        action_save->setIconVisibleInMenu(true);
        action_exit = new QAction(Simulator);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/exit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon3);
        action_exit->setIconVisibleInMenu(true);
        action_start = new QAction(Simulator);
        action_start->setObjectName(QStringLiteral("action_start"));
        action_start->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/start.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_start->setIcon(icon4);
        action_start->setIconVisibleInMenu(true);
        action_rec = new QAction(Simulator);
        action_rec->setObjectName(QStringLiteral("action_rec"));
        action_rec->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/record.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_rec->setIcon(icon5);
        action_rec->setIconVisibleInMenu(true);
        action_view_gen = new QAction(Simulator);
        action_view_gen->setObjectName(QStringLiteral("action_view_gen"));
        action_view_gen->setCheckable(true);
        action_view_gen->setChecked(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lines.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_view_gen->setIcon(icon6);
        action_view_gen->setIconVisibleInMenu(true);
        action_view_play = new QAction(Simulator);
        action_view_play->setObjectName(QStringLiteral("action_view_play"));
        action_view_play->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_view_play->setIcon(icon7);
        action_view_play->setIconVisibleInMenu(true);
        centralWidget = new QWidget(Simulator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget_gen = new QWidget(centralWidget);
        widget_gen->setObjectName(QStringLiteral("widget_gen"));
        verticalLayout_2 = new QVBoxLayout(widget_gen);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_noise = new QLabel(widget_gen);
        label_noise->setObjectName(QStringLiteral("label_noise"));

        horizontalLayout_4->addWidget(label_noise);

        cb_noise = new QComboBox(widget_gen);
        cb_noise->setObjectName(QStringLiteral("cb_noise"));

        horizontalLayout_4->addWidget(cb_noise);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_sig = new QLabel(widget_gen);
        label_sig->setObjectName(QStringLiteral("label_sig"));

        horizontalLayout_11->addWidget(label_sig);

        cb_sig = new QComboBox(widget_gen);
        cb_sig->setObjectName(QStringLiteral("cb_sig"));

        horizontalLayout_11->addWidget(cb_sig);


        verticalLayout_2->addLayout(horizontalLayout_11);

        widget_sig = new QWidget(widget_gen);
        widget_sig->setObjectName(QStringLiteral("widget_sig"));
        verticalLayout_3 = new QVBoxLayout(widget_sig);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        gb_sig_frec = new QGroupBox(widget_sig);
        gb_sig_frec->setObjectName(QStringLiteral("gb_sig_frec"));
        gb_sig_frec->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(gb_sig_frec);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, 0);
        dsb_sig_frec = new QDoubleSpinBox(gb_sig_frec);
        dsb_sig_frec->setObjectName(QStringLiteral("dsb_sig_frec"));
        dsb_sig_frec->setSingleStep(0.1);

        gridLayout->addWidget(dsb_sig_frec, 0, 0, 1, 1);


        horizontalLayout_12->addWidget(gb_sig_frec);

        gb_sig_amp = new QGroupBox(widget_sig);
        gb_sig_amp->setObjectName(QStringLiteral("gb_sig_amp"));
        gb_sig_amp->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(gb_sig_amp);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, -1, 0, 0);
        dsb_sig_amp = new QDoubleSpinBox(gb_sig_amp);
        dsb_sig_amp->setObjectName(QStringLiteral("dsb_sig_amp"));
        dsb_sig_amp->setSingleStep(0.1);

        gridLayout_2->addWidget(dsb_sig_amp, 0, 0, 1, 1);


        horizontalLayout_12->addWidget(gb_sig_amp);


        verticalLayout_3->addLayout(horizontalLayout_12);

        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_2->addWidget(widget_sig);

        widget_pqrst = new QWidget(widget_gen);
        widget_pqrst->setObjectName(QStringLiteral("widget_pqrst"));
        gridLayout_5 = new QGridLayout(widget_pqrst);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_amp_shift = new QLabel(widget_pqrst);
        label_amp_shift->setObjectName(QStringLiteral("label_amp_shift"));

        horizontalLayout_9->addWidget(label_amp_shift);

        dsb_amp_shift = new QDoubleSpinBox(widget_pqrst);
        dsb_amp_shift->setObjectName(QStringLiteral("dsb_amp_shift"));
        dsb_amp_shift->setMinimum(-10);
        dsb_amp_shift->setMaximum(10);
        dsb_amp_shift->setSingleStep(0.1);
        dsb_amp_shift->setValue(0.5);

        horizontalLayout_9->addWidget(dsb_amp_shift);


        gridLayout_5->addLayout(horizontalLayout_9, 7, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_amp = new QLabel(widget_pqrst);
        label_amp->setObjectName(QStringLiteral("label_amp"));

        horizontalLayout_8->addWidget(label_amp);

        dsb_amp = new QDoubleSpinBox(widget_pqrst);
        dsb_amp->setObjectName(QStringLiteral("dsb_amp"));
        dsb_amp->setMinimum(-10);
        dsb_amp->setMaximum(10);
        dsb_amp->setSingleStep(0.1);
        dsb_amp->setValue(0.5);

        horizontalLayout_8->addWidget(dsb_amp);


        gridLayout_5->addLayout(horizontalLayout_8, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pb_add = new QPushButton(widget_pqrst);
        pb_add->setObjectName(QStringLiteral("pb_add"));
        pb_add->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pb_add);

        pb_del = new QPushButton(widget_pqrst);
        pb_del->setObjectName(QStringLiteral("pb_del"));
        pb_del->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pb_del);

        cb_pqrst = new QComboBox(widget_pqrst);
        cb_pqrst->setObjectName(QStringLiteral("cb_pqrst"));

        horizontalLayout->addWidget(cb_pqrst);


        gridLayout_5->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_end = new QLabel(widget_pqrst);
        label_end->setObjectName(QStringLiteral("label_end"));

        horizontalLayout_6->addWidget(label_end);

        dsb_end = new QDoubleSpinBox(widget_pqrst);
        dsb_end->setObjectName(QStringLiteral("dsb_end"));
        dsb_end->setMinimum(0.01);
        dsb_end->setSingleStep(0.1);
        dsb_end->setValue(0.04);

        horizontalLayout_6->addWidget(dsb_end);


        gridLayout_5->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_dur = new QLabel(widget_pqrst);
        label_dur->setObjectName(QStringLiteral("label_dur"));
        label_dur->setEnabled(false);

        horizontalLayout_7->addWidget(label_dur);

        dsb_dur = new QDoubleSpinBox(widget_pqrst);
        dsb_dur->setObjectName(QStringLiteral("dsb_dur"));
        dsb_dur->setEnabled(false);
        dsb_dur->setMinimum(0.01);
        dsb_dur->setSingleStep(0.1);
        dsb_dur->setValue(0.04);

        horizontalLayout_7->addWidget(dsb_dur);


        gridLayout_5->addLayout(horizontalLayout_7, 4, 0, 1, 1);

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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(130);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_5->addWidget(tableWidget, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_begin = new QLabel(widget_pqrst);
        label_begin->setObjectName(QStringLiteral("label_begin"));

        horizontalLayout_5->addWidget(label_begin);

        label_begin_val = new QLabel(widget_pqrst);
        label_begin_val->setObjectName(QStringLiteral("label_begin_val"));

        horizontalLayout_5->addWidget(label_begin_val);


        gridLayout_5->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_time_shift = new QLabel(widget_pqrst);
        label_time_shift->setObjectName(QStringLiteral("label_time_shift"));

        horizontalLayout_10->addWidget(label_time_shift);

        dsb_time_shift = new QDoubleSpinBox(widget_pqrst);
        dsb_time_shift->setObjectName(QStringLiteral("dsb_time_shift"));
        dsb_time_shift->setMinimum(-10);
        dsb_time_shift->setMaximum(10);
        dsb_time_shift->setSingleStep(0.1);

        horizontalLayout_10->addWidget(dsb_time_shift);


        gridLayout_5->addLayout(horizontalLayout_10, 5, 0, 1, 1);


        verticalLayout_2->addWidget(widget_pqrst);


        gridLayout_3->addWidget(widget_gen, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cbNameSig = new QComboBox(centralWidget);
        cbNameSig->setObjectName(QStringLiteral("cbNameSig"));

        verticalLayout->addWidget(cbNameSig);

        label_plot = new QLabel(centralWidget);
        label_plot->setObjectName(QStringLiteral("label_plot"));
        label_plot->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_plot);

        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        plot->setFont(font);

        verticalLayout->addWidget(plot);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_sliderX0 = new QLabel(centralWidget);
        label_sliderX0->setObjectName(QStringLiteral("label_sliderX0"));

        horizontalLayout_3->addWidget(label_sliderX0);

        sliderX0 = new QSlider(centralWidget);
        sliderX0->setObjectName(QStringLiteral("sliderX0"));
        sliderX0->setMaximum(999);
        sliderX0->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderX0);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_sliderX = new QLabel(centralWidget);
        label_sliderX->setObjectName(QStringLiteral("label_sliderX"));

        horizontalLayout_2->addWidget(label_sliderX);

        sliderX = new QSlider(centralWidget);
        sliderX->setObjectName(QStringLiteral("sliderX"));
        sliderX->setMinimum(1);
        sliderX->setMaximum(999);
        sliderX->setValue(10);
        sliderX->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderX);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(2, 1);

        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(1, 1);
        Simulator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Simulator);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 839, 21));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_action = new QMenu(menuBar);
        menu_action->setObjectName(QStringLiteral("menu_action"));
        menu_view = new QMenu(menuBar);
        menu_view->setObjectName(QStringLiteral("menu_view"));
        Simulator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Simulator);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Simulator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Simulator);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Simulator->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_action->menuAction());
        menuBar->addAction(menu_view->menuAction());
        menu_file->addAction(action_open);
        menu_file->addSeparator();
        menu_file->addAction(action_exit);
        menu_action->addAction(action_start);
        menu_view->addAction(action_view_gen);
        menu_view->addAction(action_view_play);

        retranslateUi(Simulator);
        QObject::connect(action_exit, SIGNAL(triggered()), Simulator, SLOT(close()));

        cb_pqrst->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Simulator);
    } // setupUi

    void retranslateUi(QMainWindow *Simulator)
    {
        Simulator->setWindowTitle(QApplication::translate("Simulator", "Simulator", 0));
        action_open->setText(QApplication::translate("Simulator", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0));
        action_save->setText(QApplication::translate("Simulator", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        action_exit->setText(QApplication::translate("Simulator", "\320\222\321\213\321\205\320\276\320\264", 0));
        action_start->setText(QApplication::translate("Simulator", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        action_rec->setText(QApplication::translate("Simulator", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0));
        action_view_gen->setText(QApplication::translate("Simulator", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
#ifndef QT_NO_TOOLTIP
        action_view_gen->setToolTip(QApplication::translate("Simulator", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
#endif // QT_NO_TOOLTIP
        action_view_play->setText(QApplication::translate("Simulator", "\320\222\320\276\321\201\320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\320\265", 0));
        label_noise->setText(QApplication::translate("Simulator", "\320\250\321\203\320\274", 0));
        cb_noise->clear();
        cb_noise->insertItems(0, QStringList()
         << QApplication::translate("Simulator", "\320\235\320\265\321\202", 0)
         << QApplication::translate("Simulator", "\320\221\320\265\320\273\321\213\320\271 \321\210\321\203\320\274 (\320\221\320\250)", 0)
         << QApplication::translate("Simulator", "\320\241\320\265\321\202\320\265\320\262\320\260\321\217 \320\277\320\276\320\274\320\265\321\205\320\260 (\320\241\320\237)", 0)
         << QApplication::translate("Simulator", "\320\224\321\200\320\265\320\271\321\204 (\320\224)", 0)
         << QApplication::translate("Simulator", "\320\221\320\250+\320\241\320\237", 0)
         << QApplication::translate("Simulator", "\320\221\320\250+\320\224", 0)
         << QApplication::translate("Simulator", "\320\241\320\237+\320\224", 0)
         << QApplication::translate("Simulator", "\320\221\320\250+\320\241\320\237+\320\224", 0)
        );
        label_sig->setText(QApplication::translate("Simulator", "\320\241\320\270\320\263\320\275\320\260\320\273", 0));
        cb_sig->clear();
        cb_sig->insertItems(0, QStringList()
         << QApplication::translate("Simulator", "\320\241\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", 0)
         << QApplication::translate("Simulator", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\321\213\320\271", 0)
         << QApplication::translate("Simulator", "\320\242\321\200\320\260\320\277\320\265\321\206\320\265\320\262\320\270\320\264\320\275\321\213\320\271", 0)
         << QApplication::translate("Simulator", "\320\237\320\260\321\200\320\260\320\261\320\276\320\273\320\270\321\207\320\265\321\201\320\272\320\270\320\271", 0)
         << QApplication::translate("Simulator", "\320\230\320\274\320\277\321\203\320\273\321\214\321\201\320\275\321\213\320\271", 0)
         << QApplication::translate("Simulator", "PQRST", 0)
        );
        gb_sig_frec->setTitle(QApplication::translate("Simulator", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260, \320\223\321\206", 0));
        gb_sig_amp->setTitle(QApplication::translate("Simulator", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260, \320\274\320\222", 0));
        label_amp_shift->setText(QApplication::translate("Simulator", "\320\236\321\201\321\214", 0));
        label_amp->setText(QApplication::translate("Simulator", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260", 0));
        pb_add->setText(QApplication::translate("Simulator", "+", 0));
        pb_del->setText(QApplication::translate("Simulator", "-", 0));
        cb_pqrst->clear();
        cb_pqrst->insertItems(0, QStringList()
         << QApplication::translate("Simulator", "\320\275\320\265\321\202", 0)
         << QApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", 0)
         << QApplication::translate("Simulator", "\320\272\320\276\321\201\320\270\320\275\321\203\321\201\320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\275\321\213\320\271", 0)
         << QApplication::translate("Simulator", "\320\272\320\276\320\273\320\276\320\272\320\276\320\273\320\276\320\276\320\261\321\200\320\260\320\267\320\275\321\213\320\271", 0)
         << QApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", 0)
        );
        label_end->setText(QApplication::translate("Simulator", "\320\232\320\276\320\275\320\265\321\206", 0));
        label_dur->setText(QApplication::translate("Simulator", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Simulator", "\320\243\321\207\320\260\321\201\321\202\320\276\320\272 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Simulator", "\320\222\320\270\320\264 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("Simulator", "1", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("Simulator", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("Simulator", "2", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("Simulator", "3", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("Simulator", "4", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("Simulator", "5", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("Simulator", "6", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("Simulator", "7", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("Simulator", "8", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("Simulator", "\320\264\320\276 \320\240 \320\267\321\203\320\261\321\206\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 1);
        ___qtablewidgetitem12->setText(QApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("Simulator", "P \320\267\321\203\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 1);
        ___qtablewidgetitem14->setText(QApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(2, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("Simulator", "PQ \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(2, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(3, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("Simulator", "Q \320\267\321\203\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(3, 1);
        ___qtablewidgetitem18->setText(QApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(4, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("Simulator", "R \320\267\321\203\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(4, 1);
        ___qtablewidgetitem20->setText(QApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(5, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("Simulator", "S \320\267\321\203\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(5, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(6, 0);
        ___qtablewidgetitem23->setText(QApplication::translate("Simulator", "ST \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(6, 1);
        ___qtablewidgetitem24->setText(QApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(7, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("Simulator", "T \320\267\321\203\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(7, 1);
        ___qtablewidgetitem26->setText(QApplication::translate("Simulator", "\321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\321\213\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(8, 0);
        ___qtablewidgetitem27->setText(QApplication::translate("Simulator", "\320\277\320\276\321\201\320\273\320\265 T \320\267\321\203\320\261\321\206\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(8, 1);
        ___qtablewidgetitem28->setText(QApplication::translate("Simulator", "\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\271", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_begin->setText(QApplication::translate("Simulator", "\320\235\320\260\321\207\320\260\320\273\320\276", 0));
        label_begin_val->setText(QApplication::translate("Simulator", "0,00", 0));
        label_time_shift->setText(QApplication::translate("Simulator", "\320\241\320\264\320\262\320\270\320\263", 0));
        label_plot->setText(QApplication::translate("Simulator", "TextLabel", 0));
        label_sliderX0->setText(QApplication::translate("Simulator", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", 0));
        label_sliderX->setText(QApplication::translate("Simulator", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", 0));
        menu_file->setTitle(QApplication::translate("Simulator", "\320\244\320\260\320\271\320\273", 0));
        menu_action->setTitle(QApplication::translate("Simulator", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\320\265", 0));
        menu_view->setTitle(QApplication::translate("Simulator", "\320\222\320\270\320\264", 0));
    } // retranslateUi

};

namespace Ui {
    class Simulator: public Ui_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
