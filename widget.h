#ifndef WIDGET_H
#define WIDGET_H
#include "game.h"
#include <QWidget>
#include <QKeyEvent>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    QColor tileB;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void paintEvent(QPaintEvent *event);
    void drawMap();
    void drawTile(QPainter painter);
    Ui::Widget *ui;
};

#endif // WIDGET_H
