#include "game.h"
#include "board.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main() {
    std::srand(time(0));
    std::cout << "Welcome to 2048 Game!\n";
    //test git
    // Khởi tạo bàn cờ ban đầu
    addNewTile();
    addNewTile();
    
    // Hiển thị bảng đầu tiên
    board();
    // Vòng lặp chính của game (nếu chưa có)
    while (!isgameover()) {
        hand(check);
        if(check == true) {
            return 0;
        }
        board(); // Cập nhật bảng sau mỗi lượt đi
    }

    std::cout << "Thanks for playing.\n";
    return 0;
}
