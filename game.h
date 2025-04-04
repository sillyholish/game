//Xử lý logic game
#ifndef GAME_H
#define GAME_H

const int size = 4;

extern int matrix[size][size];
extern bool check;

    void moveleft(int row[size]);
    void moveleftall();
    void moveright(int col[size]);
    void moverightall();
    void moveup();
    void movedown();
    bool canMove();
    bool isgameover();
    void hand(bool& check);
    void addNewTile();
    bool isWinGame();

#endif 
