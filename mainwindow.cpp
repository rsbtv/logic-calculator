#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::my_func() //тело функции

{
    bool op1, op2; //операнды
    bool res; //результат У нас будет bool
    int index; //код операции
    //сейчас 0-серый, 1 зеленый, 2 - красный, 3 - синий
    //у нас будет false - красный, true - зеленый

    //if (ui->comboBox_OP1->currentIndex()==0)
    //op1=false;
    //else
    //op1=true;
    //так как выше делать НЕ НАДО

    op1=ui->comboBox_OP1->currentIndex()==1;
    op2=ui->comboBox_OP2->currentIndex()==1;
    index=ui->comboBox_Oper->currentIndex(); //формируем код операции

    QPalette pal; //палитра
    pal=ui->centralWidget->palette(); //берем текущую палитру

    switch (index)
    {
    case 0:
        res=0;
        break;
    case 1: // по боксу 1
        if (op1)
            res=1;
        else
            res=2;
        break;
    case 2: // по боксу 2
        if (op2)
            res=1;
        else
            res=2;
        break;
    case 3: // всегда зеленый
        res=1;
        break;
    case 4: //незнамо что
    default: //на всякий случай
        res=3;
        break;



    }//у нас будут логические выражения так как res типа bool. if быть не должно
    switch (res)
    {
    case 0:
        pal.setColor(QPalette:: Window,Qt:: gray);
        break;
    case 1:
        pal.setColor(QPalette:: Window,Qt:: green);
        break;
    case 2:
        pal.setColor(QPalette:: Window,Qt:: red);
        break;
    case 3:
    default:
        pal.setColor(QPalette:: Window,Qt:: blue);
        break;
    }
    // у нас будет один if так как res будет bool
    ui->centralWidget->setAutoFillBackground(true); //включаем автозаливку
    ui->centralWidget->setPalette(pal); //присваиваем палитру
}

void MainWindow::on_comboBox_Oper_currentIndexChanged(int index)
    {
    bool op1, op2; //операнды
    bool res; //результат У нас будет bool
    //сейчас 0-серый, 1 зеленый, 2 - красный, 3 - синий
    //у нас будет false - красный, true - зеленый

    //if (ui->comboBox_OP1->currentIndex()==0)
    //op1=false;
    //else
    //op1=true;
    //так как выше делать НЕ НАДО

    op1=ui->comboBox_OP1->currentIndex()==1;
    op2=ui->comboBox_OP2->currentIndex()==1;

    QPalette pal; //палитра
    pal=ui->centralWidget->palette(); //берем текущую палитру

    switch (index)
    {
        case 0:
            res=0;
            break;
        case 1: // по боксу 1
            if (op1)
                res=1;
            else
                res=2;
            break;
        case 2: // по боксу 2
            if (op2)
                res=1;
            else
                res=2;
            break;
        case 3: // всегда зеленый
            res=1;
            break;
        case 4: //незнамо что
        default: //на всякий случай
            res=3;
            break;



    }//у нас будут логические выражения так как res типа bool. if быть не должно
switch (res)
{
    case 0:
        pal.setColor(QPalette:: Window,Qt:: gray);
        break;
    case 1:
        pal.setColor(QPalette:: Window,Qt:: green);
        break;
    case 2:
        pal.setColor(QPalette:: Window,Qt:: red);
        break;
    case 3:
    default:
        pal.setColor(QPalette:: Window,Qt:: blue);
        break;
}
// у нас будет один if так как res будет bool
ui->centralWidget->setAutoFillBackground(true); //включаем автозаливку
ui->centralWidget->setPalette(pal); //присваиваем палитру

}

void MainWindow::on_comboBox_OP1_currentIndexChanged(int)
{
    my_func(); //вызов функции
}

void MainWindow::on_comboBox_OP2_currentIndexChanged(int)
{
    my_func(); //вызов функции
}
