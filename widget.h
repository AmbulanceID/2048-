#ifndef WIDGET_H
#define WIDGET_H
#include "game.h"
#include <QWidget>
#include <iostream>
#include <QKeyEvent>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    QColor tileB;
    QColor tile2,tile4,tile8,tile16,tile32;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *e);
    void drawMap();
    void drawTile();
    void setColor();
    Ui::Widget *ui;
};

#endif // WIDGET_H
