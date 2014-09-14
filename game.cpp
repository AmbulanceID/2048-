#include "game.h"

Game::Game()
{
    score = 0;

    font.setStyleHint(QFont::OldEnglish);
    font.setBold(true);
    font.setPointSize(14);

    spawnDoubleProcent = 90;

    //timer->start();

    background.setBlue(240);
    background.setRed(256);
    background.setAlpha(130);
    background.setGreen(256);

    tileColor.setRed(256);
    tileColor.setGreen(256);
    tileColor.setBlue(240);
    tileColor.setAlpha(65);

    for(int i = 0;i<4;i++)
        for(int j = 0;j<4;j++)
            map[i][j] = 0;
}


int Game::height(){
    return HEIGHT;
}


void Game::updateTile(){

    int x = rand() % 4;
    int y = rand() % 4;

    if(map[x][y] != 0)updateTile();

    int chance = 100 - spawnDoubleProcent;
    if(rand() % (chance+1) == 1){
        if(map[x][y]==0)
        map[x][y] = 4;
    }
    else {
        if(map[x][y] == 0)
        map[x][y] = 2;
    }

    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            std::cout << map[i][j];

        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int Game::width(){
    return WIDTH;
}
