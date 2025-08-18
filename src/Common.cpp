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
void genPrey()
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
	cout << "╔";// Vẽ góc trên bên trái của khung.
	for (size_t i = 1; i < WIDTH; i++)
		cout << "═";
	cout << "╗" << endl;// Vẽ góc trên bên phải của khung.

	for (size_t i = 1; i < HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << "║";
		gotoxy(WIDTH, i);
		cout << "║";
	}
	gotoxy(0, HEIGHT);
	cout << "╚";
	for (size_t i = 1; i < WIDTH; i++)
		cout << "═";
	cout << "╝";// Vẽ góc dưới bên phải của khung.
}

// Hiển thị hoặc ẩn con trỏ trong console
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void chooseLevel()
{
    system("cls");
        cout << "Chon cap do choi (1 - 5): ";
        int t;
        cin >> t;
        if (t >= 1 && t <= 5) {
            speed = 600 - t * 100; // Tính tốc độ dựa trên cấp độ
        } else 
        {
            speed = 300;
        }
        
        system("cls");
        cout << "Meo: khi choi game, ban co the nhan 'ESC' de thoat" << endl;
        gotoxy(0, 2);
        cout << "San sang!";
        Sleep(1000);
        for (size_t i = 3; i > 0; i--)
        {
            system("cls");
            cout << "Meo: khi choi game, ban co the nhan 'ESC' de thoat" << endl;
            gotoxy(0, 2);
            cout << "Dem nguoc: " << i;
            Sleep(1000);
        }
        system("cls");
        cout << "Meo: khi choi game, ban co the nhan 'ESC' de thoat" << endl;
        gotoxy(0, 2);
        cout << "Choi !";
        Sleep(1000);
}

void initGame()
{
    score = 0;// Khởi tạo biến điểm số.
    speed = 300;// Khởi tạo biến tốc độ di chuyển của rắn
    snake = {
    Point{ WIDTH / 2 + 2, HEIGHT / 2 },
    Point{ WIDTH / 2 + 1, HEIGHT / 2 },
    Point{ WIDTH / 2, HEIGHT / 2 },
    Point{ WIDTH / 2 - 1, HEIGHT / 2 },
    Point{ WIDTH / 2 - 2, HEIGHT / 2 }
    };
}

#pragma endregion
