//
// Created by Asus on 8/8/2025.
//

#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <algorithm>
using namespace std;

struct Point { int x, y; };// Cấu trúc tọa độ.
#pragma region Định nghĩa hằng số
#define WIDTH 40 // Chiều rộng của khung trò chơi.
#define HEIGHT 20 // Chiều cao của khung trò chơi.
#define BODY "■" // Thành phần thân rắn.
#define PREY "♥" // Mồi của rắn.
#pragma endregion

void genPrey();// Hàm tạo mồi ngẫu nhiên.
void gotoxy(int x, int y); // Hàm di chuyển con trỏ đến vị trí (x, y).
void displayScore();// Hàm hiển thị điểm số.
void drawBox(); // Hàm vẽ khung trò chơi.
void chooseLevel(); // Hàm chọn cấp độ chơi.
void initGame(); // Hàm khởi tạo trò chơi.
void ShowConsoleCursor(bool showFlag);// Hàm tắt mở con nháy.


extern vector<Point> snake;// Biến toàn cục danh sách các điểm tạo thành thân rắn.
extern Point prey;// Biến toàn cục điểm hiển thị mồi.
extern int score;// Biến toàn cục điểm số.
extern int speed;// Biến toàn cục tốc độ di chuyển của rắn.
extern Point prevTail;// Biến toàn cục lưu vị trí đuôi rắn trước khi di chuyển.
#endif //COMMON_H
