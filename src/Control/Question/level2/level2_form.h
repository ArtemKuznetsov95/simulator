#ifndef LEVEL2_FORM_H
#define LEVEL2_FORM_H

#include <QWidget>
#include <QMap>
#include <Utilities/qcustomplot.h>
#include <Control/Question/level/level.h>
#include <Diograms/Diograms_Data/diograms_data.h>
#include <Diograms/Diograms_Fun/diograms_fun.h>

namespace Ui {
class level2_Form;
}

class level2_Form : public QWidget,  public level
{
    Q_OBJECT

public:
    explicit level2_Form(QWidget *parent = nullptr);
    ~level2_Form();

    QMap<int, QString> getMapAnswer() override;
    int getResult() override;
    QString getQuestion() override;

private slots:
    void createPlot();
    void createAnswer();
    void createQuestion();

private:
    Ui::level2_Form *ui;
    QString m_nameQuestin = "Вопрос2";
    QMap<int, QString> m_mapAnswer;
    int m_result = 3;

    _data_pqrst_ data_pqrst;
    QVector<_data_pqrst_> v_data_pqrst;
};

#endif // LEVEL2_FORM_H
