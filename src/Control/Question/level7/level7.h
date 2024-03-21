#ifndef LEVEL7_H
#define LEVEL7_H

#include <QWidget>
#include <QMap>
#include <qcustomplot.h>
#include <Control/Question/level/level.h>
#include <QVBoxLayout>
#include <Diograms/Diograms_Data/diograms_data.h>
#include <Diograms/Diograms_Fun/diograms_fun.h>

class level7 : public QWidget,  public level
{
    Q_OBJECT
public:
    level7(QWidget *parent = nullptr);
    ~level7();

    QMap<int, QString> getMapAnswer() override;
    int getResult() override;
    QString getQuestion() override;

private slots:
    void createPlot();
    void createAnswer();
    void createQuestion();

private:
    QCustomPlot* widget_plot;
    QString m_nameQuestin = "Вопрос7";
    QMap<int, QString> m_mapAnswer;
    int m_result = 2;

    _data_pqrst_ data_pqrst;
    QVector<_data_pqrst_> v_data_pqrst;
};

#endif // LEVEL7_H
