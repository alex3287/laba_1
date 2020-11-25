#include "testqtimer.h"
#include "QTextStream"
#include "QString"

TestQTimer::TestQTimer(QObject* parent) : QObject(parent)
{
    connect( &m_timer, SIGNAL( timeout() ), SLOT( set_file() ) );
    m_timer.start( 1000 ); // Таймер будет срабатывать каждые 1000 миллисекунд, т.е. каждую секунду
}

TestQTimer::~TestQTimer(){}

void TestQTimer::set_file()
{
    QTextStream out(stdout);
    QTextStream cin(stdin);
    out<<"input file name -> "<<endl;
    QString fname;
    cin>>fname;
    out<<"see "<<fname<<endl;
}
