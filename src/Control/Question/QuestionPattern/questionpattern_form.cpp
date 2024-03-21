#include "questionpattern_form.h"
#include "ui_questionpattern_form.h"

QuestionPattern_Form::QuestionPattern_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionPattern_Form)
{
    ui->setupUi(this);

    auto level_1 = new level1_Form;
    auto level_2 = new level2_Form;
    auto level_3 = new level3_Form;
    auto level_4 = new level4;
    auto level_5 = new level5;
    auto level_6 = new level6;
    auto level_7 = new level7;
    auto level_8 = new level8;
    auto level_9 = new level9;
    auto level_10 = new level10;
    auto level_11 = new level11;
    auto level_12 = new level12;

    ui->m_stackedWidget->addWidget(level_1);
    ui->m_stackedWidget->addWidget(level_2);
    ui->m_stackedWidget->addWidget(level_3);
    ui->m_stackedWidget->addWidget(level_4);
    ui->m_stackedWidget->addWidget(level_5);
    ui->m_stackedWidget->addWidget(level_6);
    ui->m_stackedWidget->addWidget(level_7);
    ui->m_stackedWidget->addWidget(level_8);
    ui->m_stackedWidget->addWidget(level_9);
    ui->m_stackedWidget->addWidget(level_10);
    ui->m_stackedWidget->addWidget(level_11);
    ui->m_stackedWidget->addWidget(level_12);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->m_radioButton_1);
    buttonGroup->addButton(ui->m_radioButton_2);
    buttonGroup->addButton(ui->m_radioButton_3);

    buttonGroup->setExclusive(true);    
}

QuestionPattern_Form::~QuestionPattern_Form()
{
    delete ui;
}

void QuestionPattern_Form::init()
{
    m_set_widget.clear();
    for(int i = 0; i < ui->m_stackedWidget->count(); ++i) {
        m_set_widget.insert(i);
    }
    randCurrentWidget();
}

void QuestionPattern_Form::randCurrentWidget()
{

    int indexWidget = randCurent();
    ui->m_stackedWidget->setCurrentIndex(indexWidget);
    auto widget = dynamic_cast<level*>(ui->m_stackedWidget->currentWidget());
    if(widget) {
        ui->m_label_question->setText(widget->getQuestion());

        auto map = widget->getMapAnswer();
        randMapAnswer(map);
    }
}

int QuestionPattern_Form::randCurent()
{
    srand(time(NULL));

    int randomIndex = rand() % m_set_widget.size();

    auto it = m_set_widget.begin();
    std::advance(it, randomIndex);
    const int index = *it;
    m_set_widget.remove(*it);

    return index;
}

void QuestionPattern_Form::randMapAnswer(QMap<int, QString> map)
{
    QStringList answers;
    for(auto item : map.values())
        answers.append(item);

    std::random_shuffle(std::begin(answers), std::end(answers));

    ui->m_radioButton_1->setText(QString(answers[0]+";"));
    ui->m_radioButton_2->setText(QString(answers[1]+";"));
    ui->m_radioButton_3->setText(QString(answers[2]+"."));

    auto widget = dynamic_cast<level*>(ui->m_stackedWidget->currentWidget());
    correctAnswer = map[widget->getResult()];

    connect(ui->m_radioButton_1, &QRadioButton::clicked, [this](){
        auto result = ui->m_radioButton_1->text();
        result.resize(result.size() - 1);
        if (result == correctAnswer) {
            m_right = true;
        } else {
            m_right = false;
        }
        emit si_checkRadioButton();
    });
    connect(ui->m_radioButton_2, &QRadioButton::clicked, [this](){
        auto result = ui->m_radioButton_1->text();
        result.resize(result.size() - 1);
        if (result == correctAnswer) {
            m_right = true;
        } else {
            m_right = false;
        }
        emit si_checkRadioButton();
    });
    connect(ui->m_radioButton_3, &QRadioButton::clicked, [this](){
        auto result = ui->m_radioButton_1->text();
        result.resize(result.size() - 1);
        if (result == correctAnswer) {
            m_right = true;
        } else {
            m_right = false;
        }
        emit si_checkRadioButton();
    });

    buttonGroup->setExclusive(false);
    ui->m_radioButton_1->setChecked(false);
    ui->m_radioButton_2->setChecked(false);
    ui->m_radioButton_3->setChecked(false);
    buttonGroup->setExclusive(true);
}

bool QuestionPattern_Form::isWidget()
{
    return m_set_widget.count();
}

bool QuestionPattern_Form::checkAnswer()
{
    bool isCheck = false;
    for(auto item : buttonGroup->buttons()) {
        if(item->isChecked()) {
            isCheck = true;
            break;
        }
    }

    if(isCheck) {
        auto widget = dynamic_cast<level*>(ui->m_stackedWidget->currentWidget());
        if(widget) {
            ui->m_label_question->setText(widget->getQuestion());

            auto map = widget->getMapAnswer();
        }
        return true;

    } else {
        return false;
    }
}

bool QuestionPattern_Form::getAnswer()
{
    return m_right;
}

int QuestionPattern_Form::getWidget()
{
    return ui->m_stackedWidget->count();
}
