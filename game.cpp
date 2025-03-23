#include "game.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

int matrix[size][size] = {0}; // Khởi tạo ma trận 

//hàm xử lí di chuyển của 1 hàng sang trái
void moveleft(int row[size]) {
    int tmp[size] = {0};
    int index = 0;

    // Bước 1: Dồn số về bên trái
    for(int i = 0; i < size; ++i) {
        if(row[i] != 0) tmp[index++] = row[i];
    }

    // Bước 2: Gộp số giống nhau
    for(int i = 0; i < size - 1; ++i) {
        if(tmp[i] == tmp[i + 1] && tmp[i] != 0) {
            tmp[i] *= 2;
            tmp[i + 1] = 0;
        }
    }

    // Bước 3: Dồn số về trái một lần nữa
    int res[size] = {0}, idx = 0;
    for(int i = 0; i < size; ++i) {
        if(tmp[i] != 0) res[idx++] = tmp[i];
    }

    // Bước 4: Sao chép lại vào hàng gốc
    for(int i = 0; i < size; ++i) row[i] = res[i];
}


//hàm di chuyển của thao tác sang trái
void moveleftall() {
    for(int i = 0; i < size; ++i) {
        moveleft(matrix[i]);
    }
}

void moveright(int col[size] ) {
    int tmp[size] = {0};
    //Sao chép vào mảng để gộp 
    for(int i = 0; i < size; ++i) {
        tmp[i] = col[i];
    }
    //Gộp ô
    std::reverse(tmp, tmp + size);
    moveleft(tmp);
    std::reverse(tmp, tmp + size);
    //Sao chép vào mảng gốc
    for(int i = 0; i < size; ++i) {
        col[i] = tmp[i];
    }
}

void moverightall() {
    for(int i = 0; i < size; ++i) {
        moveright(matrix[i]);
    }
}

void moveup() {
    //Sao chép cột di chuyển
    for(int i = 0; i < size; ++i) {
        int tmp[size] = {0}; 
        // sao chép từng cột
        for(int j = 0; j < size; ++j) {
            tmp[j] = matrix[j][i];
        }
        //Gộp ô
        moveleft(tmp);
        //Cập nhật lại ma trận
        for(int j = 0; j < size; ++j) {
            matrix[j][i] = tmp[j];
        }
    }
}

void movedown() {
    //Sao chép cột di chuyển
    for(int i = 0; i < size; ++i) {
        int tmp[size] = {0}; 
        // sao chép từng cột
        for(int j = 0; j < size; ++j) {
            tmp[j] = matrix[j][i];
        }
        //Gộp ô
        std::reverse(tmp, tmp + size);
        moveleft(tmp);
        std::reverse(tmp, tmp + size);
        //Cập nhật lại ma trận
        for(int j = 0; j < size; ++j) {
            matrix[j][i] = tmp[j];
        }
    }
}

bool canMove() {
    //Kiểm tra xem còn ô trống để di chuyển không
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] == 0) {
                return true;
            }
        }
    }
    //Kiểm tra xem các ô còn lại còn có khả năng gộp không 
    for(int i = 0; i < size; ++i) {
        //Kiểm tra xem hàng ngang còn ô gộp được không
        for(int j = 0; j < size - 1; ++j) {
            if(matrix[i][j] == matrix[i][j + 1]) {
                return true;
            }
        }
    }
    //Kiểm tra xem hàng dọc còn ô gộp được không
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size - 1; ++j) {
            if(matrix[j][i] == matrix[j + 1][i]) {
                return true;
            }
        }
    }
    return false; //Không còn ô di chuyển được và cũng không còn ô có khả năng gộp được
}

bool isgameover() {
    return !canMove(); //Nếu không còn khả năng di chuyển hay gộp nữa thì trò chơi kết thúc 
}

void hand() {
    char c;
    std::cout << "Nhap cach di chuyen theo huong dan duoi day: \n\n";
    std::cout << "Nhap W neu muon di chuyen len\n";
    std::cout << "Nhap S neu muon di chuyen xuong\n";
    std::cout << "Nhap A neu muon di chuyen sang trai\n";
    std::cout << "Nhap D neu muon di chuyen sang phai\n";
    std::cout << "\n";
    std::cin >> c;
    c = (char)std::toupper(c); //Biến đổi thanh in hoa nếu người dùng lỡ nhập kí tự thường
    while(c != 'W' && c != 'S' && c != 'A' && c != 'D') {
        std::cout << "Ban vua nhap ki tu khong hop le. De tiep tuc tro choi, hay nhap ki tu dung vơi huong dan\n";
        std::cout << "Con neu ban muon ket thuc tro choi thi vui long bam so 0\n";
        std::cin >> c;
        if(c == '0') {
            std::cout << "Tro choi da ket thuc dung voi yeu cau!\n";
            return;
        }
    }
    if(c == 'A') {
        moveleftall();
    } else if(c == 'D') {
        moverightall();
    } else if(c == 'W') {
        moveup();
    } else if(c == 'S') {
        movedown();
    }
    if(isgameover()) {
        std::cout << "\nGAME OVER\n";
    } else {
        addNewTile(); //Thêm ô mới sau mỗi lần di chuyển 
    }
}

void addNewTile() {
    std::srand(time(0));
    std::vector< std::pair<int, int> > v;
    int count = 0; //Dùng để đếm số ô trống
    //Lưu tọa độ của các ô đang trống
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] == 0) {
                v.push_back({i, j});
            }
        }
    }
    count = v.size();
    std::pair <int, int> ran = v[rand() % count]; //Lưu tọa độ ô trống của số ngẫu nhiên
    int x = ran.first;
    int y = ran.second;
    //90% sẽ sinh 2, 10% sẽ sinh 4
    matrix[x][y] = rand() % 10 < 9 ? 2 : 4; //Lưu 1 số ngẫu nhiên đã được phát sinh vào 1 ô được chọn ngẫu nhiên

}

