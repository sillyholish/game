#include "board.h"
#include <iostream>


void board() {
    std::cout << "------GAME 2048------\n\n";
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] == 0) {
                std::cout << "." << ' ';
            } else {
                std::cout << matrix[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
    addNewTile();
    addNewTile();
    std::cout << "------------------------\n";
}
