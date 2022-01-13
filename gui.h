#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include <QTimer>
const int TIMEOUT = 1000;

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void toggle();

private:
    QTimer* m_timer;
    bool m_state;
};

#endif // GUI_H
