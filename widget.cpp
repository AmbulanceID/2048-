#include "widget.h"
#include "ui_widget.h"
Game *mainGame = new Game();
QKeyEvent keyEvent(QEvent::KeyPress,Qt::Key_Left,Qt::NoModifier);
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{   
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));


    timer->start(1000/40);
    resize(WIDTH,HEIGHT);

    setColor();

    tileB.setRed(100);
    tileB.setGreen(65);
    tileB.setBlue(0);
    tileB.setAlpha(150);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setColor(){
    tile2.setRed(230);
    tile2.setGreen(230);
    tile2.setBlue(0);

    tile4.setRed(230);
    tile4.setGreen(180);
    tile4.setBlue(0);

    tile8.setRed(230);
    tile8.setGreen(130);
    tile8.setBlue(0);

    tile16.setRed(230);
    tile16.setGreen(80);
    tile16.setBlue(0);

    tile32.setRed(230);
    tile32.setGreen(30);
    tile32.setBlue(0);
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
            mainGame->coordinates[i][j].setX(80+space*(i+1)+(i*50));
            mainGame->coordinates[i][j].setY(40+(j*50)+space*(j+1));
        }
    }

    drawTile();
}

void Widget::drawTile(){
    int tX,tY;
    QPainter painter(this);
    painter.setFont(mainGame->font);
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            tX = mainGame->coordinates[i][j].x();
            tY = mainGame->coordinates[i][j].y();
            QRect rect(tX,tY,50,50);
            std::cout << mainGame->map[i][j];
            if(mainGame->map[i][j] == 2){
                painter.setBrush(tile2);
                painter.drawRect(rect);
                painter.drawText(rect,Qt::AlignCenter,tr("2"));
            }
            if(mainGame->map[i][j] == 4){
                painter.setBrush(tile4);
                painter.drawRect(rect);
                painter.drawText(rect,Qt::AlignCenter,tr("4"));
            }

        }
        std::cout << "" <<std::endl;
    }
}


void Widget::paintEvent(QPaintEvent *){
    drawMap();
}

void Widget::keyPressEvent(QKeyEvent *e){
    switch(e->key()){
    case Qt::Key_Down:
        mainGame->updateTile();
        break;
    case Qt::Key_Up:
        mainGame->updateTile();
        break;
    case Qt::Key_Left:
        mainGame->updateTile();
        break;
    case Qt::Key_Right:
        mainGame->updateTile();
        break;
    }
}

