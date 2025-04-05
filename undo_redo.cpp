#include "undo_redo.h"
#include "game.h"
#include <iostream>

int matrix[size][size];
Stack undostack, redostack;

struct Node
{
    int matrix[size][size];
    Node* next;
};

struct Stack
{
    Node* top = nullptr; //Con trỏ đầu của stack;
    //Lưu trạng thái hiện tại của ma trận
    void push(int board[size][size]) {
        Node* newNode = new Node;
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                newNode->matrix[i][j] = board[i][j];
            }
        }
        newNode->next = top;
        top = newNode;
    }
    //Lấy trạng thái đã lưu gần nhất của ma trận ra
    bool pop(int board[size][size]) {
        if(!top) {
            std::cout << "Khong the undo!!!" << "\n";
            return false;
        }
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                board[i][j] = top->matrix[i][j];
            }
        }
        Node* tmp = top;
        top = top->next;
        delete tmp;
        return true;
    }

    bool empty() {
        return top == nullptr;
    }
    //Xóa trạng thái dùng khi undo và thao tác hoặc ngược lại
    void clear() {
        if(!top) {
            return;
        }
        while(top) {
            Node* tmp = top;
            delete tmp;
            top = top->next;
        }
    }
};

void undo_redo::undo(int b[size][size]) {
    redostack.push(b);
    undostack.pop(b);
}

void undo_redo::redo(int b[size][size]) {
    undostack.push(b);
    redostack.pop(b);
}

//Lưu trạng thái trước khi di chuyển
void undo_redo::saveSate(int b[size][size]) {
    undostack.push(b);
    redostack.clear();
}