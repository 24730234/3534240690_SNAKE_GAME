//
// Created by Asus on 8/8/2025.
//

#ifndef COMMON_H
#define COMMON_H
#include <vector>
// Cấu trúc tọa độ điểm


struct Point { int x, y; };

#include "../include/Common.h"
#include <vector>
#pragma region Định nghĩa hằng số
#define WIDTH 40 // Chiều rộng của khung trò chơi
#define HEIGHT 20 // Chiều cao của khung trò chơi
#define BODY "■" // Thành phần thân rắn
#define PREY "♥" // Mồi của rắn
#pragma endregion

#pragma region Biến toàn cục
// Khởi tạo vị trí con rắn chính giữa khung hình khi bắt đầu trò chơi.
std::vector<Point> snake = {
    Point{ WIDTH / 2 + 2, HEIGHT / 2 },
    Point{ WIDTH / 2 + 1, HEIGHT / 2 },
    Point{ WIDTH / 2, HEIGHT / 2 },
    Point{ WIDTH / 2 - 1, HEIGHT / 2 },
    Point{ WIDTH / 2 - 2, HEIGHT / 2 }
};
// Direction direction = Direction::right;// Khởi tạo hướng di chuyển của rắn là sang phải
Point prey;// Khởi tạo biến mồi của rắn
int score = 0;// Khởi tạo biến điểm số.
int speed = 300;// Khởi tạo biến tốc độ di chuyển của rắn
Point prevTail;// Khởi tạo biến lưu đuôi rắn trước khi di chuyển
#pragma endregion

#endif //COMMON_H
