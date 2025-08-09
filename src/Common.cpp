//
// Created by Asus on 8/9/2025.
//
#include "Common.h"

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
