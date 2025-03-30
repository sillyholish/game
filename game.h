//Xử lý logic game
#ifndef GAME_H
#define GAME_H

const int size = 4;

extern int matrix[size][size];

    void addNewTile();
    void hand();
    void moveup();
    void movedown();
    void moveright(int col[size]);
    void moveleft(int row[size]);
    bool isWinGame(int matrix[][size]);
    bool canMove();
    bool isgameover();
    void moveleftall();
    void moverightall();

#endif
