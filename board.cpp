#include "game.h"
#include <iostream>
#include <iomanip>

void board() {
    std::cout << std::setfill('-') << std::setw(20) << "\n";
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] == 0) {
                std::cout << ".";
            } else {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    addNewTile();
    std::cout << std::setfill('-') << std::setw(20) << "\n";
}
