#ifndef LEVEL1_FORM_H
#define LEVEL1_FORM_H

#include <QWidget>
#include <QMap>
#include <qcustomplot.h>
#include <Control/Question/level/level.h>
#include <Diograms/Diograms_Data/diograms_data.h>
#include <Diograms/Diograms_Fun/diograms_fun.h>

namespace Ui {
class level1_Form;
}

class level1_Form : public QWidget,  public level
{
    Q_OBJECT

public:
    explicit level1_Form(QWidget *parent = nullptr);
    ~level1_Form();

    QMap<int, QString> getMapAnswer() override;
    int getResult() override;
    QString getQuestion() override;

private slots:
    void createPlot();
    void createAnswer();
    void createQuestion();

private:
    Ui::level1_Form *ui;
    QString m_nameQuestin = "Вопрос1";
    QMap<int, QString> m_mapAnswer;
    int m_result = 1;

    _data_pqrst_ data_pqrst;
    QVector<_data_pqrst_> v_data_pqrst;

};

#endif // LEVEL1_FORM_H
