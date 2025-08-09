#pragma region Thư viện
#include <iostream>
#include <windows.h>
#include <vector>
#include "include/Common.h"
#include "include/Snake.h"
#include "include/Control.h"
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
// Hiển thị điểm số
void displayScore()
{
    gotoxy(WIDTH + 5, 2);
    cout << "Diem so cua ban " << score;
}

// Hiển thị menu kết thúc trò chơi
void showEndMenu()
{
    system("cls");
    gotoxy(0, 0);
    cout << "Ket thuc tro choi!" << endl;
    cout << "Diem cua ban: " << score << endl;
    cout << "Ban co muon choi nua khong ([y]/[n]): ";
    char option;
    cin >> option;
    option = tolower(option);
    if (option == 'y')
    {
        resetSnake();
        startGame();
    }
    else if (option == 'n')
        exit(1);
}

// Bắt đầu trò chơi
void startGame()
{
    system("cls");
    ShowConsoleCursor(false);
    drawBox();
    drawSnake();
    genApple();
    displayScore();
    while (true)
    {
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == -32 || ch == 0xE0) // Arrow key prefix
            {
                ch = _getch(); // Get the second byte
                switch (ch)
                {
                case 72: // Up arrow
                    if (direction != Direction::down)
                        direction = Direction::up;
                    break;
                case 77: // Right arrow
                    if (direction != Direction::left)
                        direction = Direction::right;
                    break;
                case 80: // Down arrow
                    if (direction != Direction::up)
                        direction = Direction::down;
                    break;
                case 75: // Left arrow
                    if (direction != Direction::right)
                        direction = Direction::left;
                    break;
                }
            }
            else if (ch == 'q') // Thoát trò chơi
            {
                showEndMenu();
                break;
            }
        }
        move();
        drawHeadnTail();
        if (isAteApple())
        {
            score++;
            displayScore();
            growing();
            genApple();
        }
        if (isBiteItself())
        {
            ShowConsoleCursor(true);
            showEndMenu();
            break;
        }
        if (isHitWall())
        {
            ShowConsoleCursor(true);
            showEndMenu();
            break;
        }
        Sleep(speed);
    }
}
// Hiển thị menu bắt đầu trò chơi
void showStartMenu()
{
    system("cls");
    cout << "\t===== Ran San Moi====!" << endl;
    cout << "\tTuy chinh:" << endl;
    cout << "\t1. Bat Dau" << endl;
    cout << "\t2. Ket thuc" << endl;
    cout << "\tLua chon cua ban: ";
    int option;
    cin >> option;
    if (option == 1)
    {
        system("cls");
        cout << "Chon cap do choi (1 - 5): ";
        int t;
        cin >> t;
        speed = 600 - t * 100; // Tính tốc độ dựa trên cấp độ
        system("cls");
        cout << "Meo: khi choi game, ban co the nhan 'q' de thoat" << endl;
        gotoxy(0, 2);
        cout << "San sang!";
        Sleep(1000);
        for (size_t i = 3; i > 0; i--)
        {
            system("cls");
            cout << "Meo: khi choi game, ban co the nhan 'q' de thoat" << endl;
            gotoxy(0, 2);
            cout << "Dem nguoc: " << i;
            Sleep(1000);
        }
        system("cls");
        cout << "Meo: khi choi game, ban co the nhan 'q' de thoat" << endl;
        gotoxy(0, 2);
        cout << "Choi !";
        Sleep(1000);
        startGame();
    }
    else if (option == 2)
        exit(1);
}
#pragma endregion

int main() {
    SetConsoleOutputCP(CP_UTF8); // Cho phép hiển thị ký tự UTF-8
    showStartMenu();
    return 0;
}