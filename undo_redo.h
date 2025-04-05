#include "game.h"
#ifndef undo_redo_H
#define undo_redo_H

const int size = 4;

struct Node
{
    int matrix[size][size];
    Node* next;
};

class undo_redo{
    private:
        int board[size][size];
    public:
        struct Stack 
        {
            void push(int board[size][size]);
            bool pop(int board[size][size]);
            bool empty();
            void clear();
        };
        void undo(int b[size][size]);
        void redo(int b[size][size]);
        void saveSate(int b[size][size]);
};


#endif