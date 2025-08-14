//
// Created by Asus on 8/9/2025.
//
#include "Common.h"

#include <Menu.h>
#include <SnakeFunction.h>

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

// Tạo một quả táo ngẫu nhiên trên bảng
void genApple()
{
	srand(time(0));
    int x, y;
    bool conflict;
	do
    {
        x = rand() % (WIDTH - 1) + 1;
        y = rand() % (HEIGHT - 1) + 1;
        prey = {
            x,
            y,
        };
        // Xác định mồi có trùng với thân rắn hay không
        conflict = std::any_of(snake.begin(), snake.end(),
            [&](const Point& p) { return p.x == prey.x && p.y == prey.y;});
    } while (conflict);
	gotoxy(x, y);
	std::cout << PREY;
}

// Hiển thị điểm số
void displayScore()
{
    gotoxy(WIDTH + 5, 2);
    std::cout << "Diem so cua ban " << score;
}
#pragma region Hàm giao diện console
// Đi tới vị trí (x, y)
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

// Vẽ khung trò chơi
void drawBox()
{
    for (size_t i = 0; i < WIDTH; i++)
        cout << '=';
    gotoxy(0, HEIGHT);
    for (size_t i = 0; i < WIDTH; i++)
        cout << '=';
    for (size_t i = 1; i < HEIGHT; i++)
    {
        gotoxy(0, i);
        cout << '|';
    }
    for (size_t i = 1; i < HEIGHT; i++)
    {
        gotoxy(WIDTH, i);
        cout << '|';
    }
}

#pragma endregion
