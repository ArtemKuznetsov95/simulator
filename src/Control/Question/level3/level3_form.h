#ifndef LEVEL3_FORM_H
#define LEVEL3_FORM_H

#include <QWidget>
#include <QMap>
#include <Utilities/qcustomplot.h>
#include <Control/Question/level/level.h>
#include <Diograms/Diograms_Data/diograms_data.h>
#include <Diograms/Diograms_Fun/diograms_fun.h>

namespace Ui {
class level3_Form;
}

class level3_Form : public QWidget,  public level
{
    Q_OBJECT

public:
    explicit level3_Form(QWidget *parent = nullptr);
    ~level3_Form();

    QMap<int, QString> getMapAnswer() override;
    int getResult() override;
    QString getQuestion() override;

private slots:
    void createPlot();
    void createAnswer();
    void createQuestion();

private:
    Ui::level3_Form *ui;
    QString m_nameQuestin = "Вопрос3";
    QMap<int, QString> m_mapAnswer;
    int m_result = 1;

    _data_pqrst_ data_pqrst;
    QVector<_data_pqrst_> v_data_pqrst;
};

#endif // LEVEL3_FORM_H
