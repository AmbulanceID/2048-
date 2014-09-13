#include "game.h"

Game::Game()
{
    score = 0;

    spawnDoubleProcent = 20;

    //timer->start();

    background.setBlue(240);
    background.setRed(256);
    background.setAlpha(130);
    background.setGreen(256);

    tileColor.setRed(256);
    tileColor.setGreen(256);
    tileColor.setBlue(240);
    tileColor.setAlpha(65);
}


int Game::height(){
    return HEIGHT;
}

void Game::updateTile(){
    int x = rand() % 5;
    int y = rand() % 5;

    int chance = 100/spawnDoubleProcent;
    if(rand() % chance+1 == 0){
        map[x][y] = 4;
    }
    else map[x][y] = 2;
}

int Game::width(){
    return WIDTH;
}
