#ifndef STOP_WATCH_H
#define STOP_WATCH_H

#include <QTimer>
#include <QTime>

class stop_watch: public QObject
{
    Q_OBJECT
public:
    stop_watch();

    void circle_timer();

    void circle_tx_timer();

    void clear();

    void timer_start();

    void timer_stop();

    QTimer *timer;

    QTimer *tx_timer;

    int ms, s, m;

    int tx_ms, tx_s, tx_m;

    int count = 1;



};

#endif // STOP_WATCH_H
