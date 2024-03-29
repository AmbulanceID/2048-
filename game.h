#ifndef GAME_H
#define GAME_H

#include "widget.h"
#include <QPainter>
#include <cstdlib>
#include <QString>
#include <iostream>
#include <QImage>
#include <QTimer>
#include <QFont>
#include <QColor>

const int WIDTH = 400;
const int HEIGHT = 300;
const int FPS = 30;
const int tileSize = 50;

class Game
{

    QTimer *timer ;
    int time;
    int spawnDoubleProcent;

public:
    QFont font;
    int map[4][4];
    QPoint coordinates[4][4];
    QColor background;
    QColor tileColor;
    int score;

public:
    Game();
    void updateTile();
    int height();
    int width();
};

#endif // GAME_H
