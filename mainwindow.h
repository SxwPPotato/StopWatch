#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stop_watch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotTimerAlarm();

    void CircleSlotTimerAlarm();

    void on_ph_b_start_clicked();

    void on_ph_b_clear_clicked();

    void on_ph_b_circle_clicked();


private:
    Ui::MainWindow *ui;

    stop_watch q;

    bool flag = true;

    QTimer *timer;

    QTimer *tx_timer;

    int ms, s, m;

    int tx_ms, tx_s, tx_m;

    int count = 1;

};
#endif // MAINWINDOW_H
