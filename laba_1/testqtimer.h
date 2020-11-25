#ifndef TESTQTIMER_H
#define TESTQTIMER_H

#include <QTimer>

class TestQTimer : public QObject
{
    Q_OBJECT
public:
    TestQTimer(QObject* parent = 0);
    ~TestQTimer();
private slots:
    void set_file();
private:
    QTimer m_timer;
};

#endif // TESTQTIMER_H
