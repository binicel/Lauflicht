#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_state = 0;
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle); // Verbindung Timer Timeout (Signal) -> Gui Label Toggle (Slot)
    m_timer->start(TIMEOUT);//periodischer Timer, sendet alle 1000ms Signal "Timeout"

}
// 0 - 1 - 0 - 1
void Gui::toggle()
{
    m_state = !m_state; //inverted
    led_25->setNum(m_state);
}

void Gui::on_horizontalSlider_valueChanged(int value)
{
    m_timer->start(1000/value); // T = 1000ms ..... 100ms -> 1...10 Hz
}
