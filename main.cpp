#pragma region Thư viện
#include <iostream>
#include <windows.h>
#include <vector>
#include "include/Common.h"
#pragma endregion

using namespace std;
// Enum điều hướng
// enum class Direction
// {
// 	up,
// 	right,
// 	down,
// 	left
// };
//
// // Cấu trúc tọa độ điểm
// struct Point
// {
// 	int x;
// 	int y;
// };

#pragma region Khởi tạo tên hàm
void showConsoleCursor(bool);// Hiển trị con trỏ chuột.
void gotoxy(int, int);// Đi tới vị trí x, y
void drawBox();// Vẽ khung trò chơi
void gameName();// Hàm hiển thị tên trò chơi.

void move();// Di chuyển rắn.
bool isHitWall();// Hàm kiểm tra rắn đâm vào tường
bool isBiteItself();// Hàm kiểm tra rắn tự cắn đuôi.
void drawHeadnTail();// Hàm vẽ đầu và đuôi rắn.
bool isAtePrey();// Hàm kiểm tra rắn ăn mồi.
void growing();// Hàm rắn phát triển (rắn dài ra khi ăn mồi).
void drawSnakePart(Point);// Hàm hiển thị thành phần của rắn.
void drawSnake();// Hàm vẽ con rắn.

void showStartMenu();// Hàm hiển thị danh mục lúc bắt đầu trò chơi.
void showEndMenu();// Hàm hiển thị danh mục lúc kết thúc trò chơi.
void genPrey();// Tạo ngẫu nhiên vị trí mồi.
void displayScore();// Hàm hiển thị điểm số khi rắn ăn mồi.
void startGame();// Hàm bắt đầu chơi game.
void resetSnake();// Hàm khôi phục vị trí của rắn về ban đầu.
#pragma endregion

#pragma region Định nghĩa hàm
// Mọi người viết hàm ở đây nhé.





// Hiển thị menu kết thúc trò chơi
// void showEndMenu()
// {
//     system("cls");
//     gotoxy(0, 0);
//     cout << "Ket thuc tro choi!" << endl;
//     cout << "Diem cua ban: " << score << endl;
//     cout << "Ban co muon choi nua khong ([y]/[n]): ";
//     char option;
//     cin >> option;
//     option = tolower(option);
//     if (option == 'y')
//     {
//         resetSnake();
//         startGame();
//     }
//     else if (option == 'n')
//         exit(1);
// }
// Bắt đầu trò chơi

// Hiển thị menu bắt đầu trò chơi
// void showStartMenu()
// {
//     system("cls");
//     cout << "\t===== Ran San Moi====!" << endl;
//     cout << "\tTuy chinh:" << endl;
//     cout << "\t1. Bat Dau" << endl;
//     cout << "\t2. Ket thuc" << endl;
//     cout << "\tLua chon cua ban: ";
//     int option;
//     cin >> option;
//     if (option == 1)
//     {
//         system("cls");
//         cout << "Chon cap do choi (1 - 5): ";
//         int t;
//         cin >> t;
//         speed = 600 - t * 100; // Tính tốc độ dựa trên cấp độ
//         system("cls");
//         cout << "Meo: khi choi game, ban co the nhan 'q' de thoat" << endl;
//         gotoxy(0, 2);
//         cout << "San sang!";
//         Sleep(1000);
//         for (size_t i = 3; i > 0; i--)
//         {
//             system("cls");
//             cout << "Meo: khi choi game, ban co the nhan 'q' de thoat" << endl;
//             gotoxy(0, 2);
//             cout << "Dem nguoc: " << i;
//             Sleep(1000);
//         }
//         system("cls");
//         cout << "Meo: khi choi game, ban co the nhan 'q' de thoat" << endl;
//         gotoxy(0, 2);
//         cout << "Choi !";
//         Sleep(1000);
//         startGame();
//     }
//     else if (option == 2)
//         exit(1);
// }
#pragma endregion

int main() {
    SetConsoleOutputCP(CP_UTF8); // Cho phép hiển thị ký tự UTF-8
    showStartMenu();
    return 0;
}