//
// Created by Asus on 8/8/2025.
//

#ifndef COMMON_H
#define COMMON_H
#include <vector>
#include <conio.h>
#include <windows.h>

struct Point { int x, y; };
#pragma region Định nghĩa hằng số
#define WIDTH 40 // Chiều rộng của khung trò chơi
#define HEIGHT 20 // Chiều cao của khung trò chơi
#define BODY "■" // Thành phần thân rắn
#define PREY "♥" // Mồi của rắn
#pragma endregion

// Đi tới vị trí (x, y)
void gotoxy(int x, int y);

extern std::vector<Point> snake;
extern Point prey;
extern int score;
extern int speed;
extern Point prevTail;
#endif //COMMON_H
