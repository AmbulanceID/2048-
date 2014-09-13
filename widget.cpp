#include "widget.h"
#include "ui_widget.h"
Game *mainGame = new Game();
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{   
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));


    timer->start(1000/40);
    resize(WIDTH,HEIGHT);

    tileB.setRed(100);
    tileB.setGreen(65);
    tileB.setBlue(0);
    tileB.setAlpha(150);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::drawMap(){
    QPainter painter(this);

    painter.setBrush(mainGame->background);
    painter.drawRect(0,0,WIDTH,HEIGHT);
    painter.setBrush(tileB);
    painter.drawRect(80,40,240,240);

    painter.setBrush(mainGame->tileColor);

    int space =8;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            painter.drawRect(80+space*(i+1)+(i*50),40+(j*50)+space*(j+1),50,50);
        }
    }


}

void Widget::drawTile(QPainter painter){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(mainGame->map[i][j] == 2)
                painter.drawImage(80+8*(i+1)+(i*50),40+(j*50)+8*(j+1),mainGame->tile2);
            if(mainGame->map[i][j] == 4)
                painter.drawImage(80+8*(i+1)+(i*50),40+(j*50)+8*(j+1),mainGame->tile4);
        }
    }
}


void Widget::paintEvent(QPaintEvent *){
    drawMap();
}

