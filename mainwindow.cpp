#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    /*ms = 0;
    s = 0;
    m = 0;
    tx_ms = 0;
    tx_s = 0;
    tx_m = 0;
    timer = new QTimer();*/

    connect(q.timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    ui->ph_b_start->setText("Старт");


    connect(q.tx_timer, SIGNAL(timeout()), this, SLOT(CircleSlotTimerAlarm()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ph_b_start_clicked()
{
    flag = !flag;

    if(flag){
        ui->ph_b_start->setText("Старт");
        q.timer_stop();

    }

    else {
        ui->ph_b_start->setText("Стоп");
        q.timer_start();

    }
}

void MainWindow::slotTimerAlarm()
{

    q.circle_timer();

    ui->lb->setText(QString::number(q.m) + " : " + QString::number(q.s) + " : " + QString::number(q.ms));
}

void MainWindow::CircleSlotTimerAlarm()
{
    q.circle_tx_timer();

}

void MainWindow::on_ph_b_circle_clicked()
{

    ui->tx_br_circle->insertPlainText("Круг " + QString::number(q.count) + ", Время " + QString::number(q.tx_m) + " : " + QString::number(q.tx_s) + " : " + QString::number(q.tx_ms));
    ui->tx_br_circle->append("");
    q.tx_m  = 0 ;
    q.tx_s = 0;
    q.tx_ms = 0;
    q.count++;
}

void MainWindow::on_ph_b_clear_clicked()
{
    q.clear();
    ui->lb->setText(QString::number(q.m) + " : " + QString::number(q.s) + " : " + QString::number(q.ms));
    ui->tx_br_circle->clear();
}
