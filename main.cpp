#pragma region Thư viện
#include <iostream>
#include <windows.h>
#include <vector>
#pragma endregion

using namespace std;

#pragma region Định nghĩa hằng số
#define WIDTH 40 // Chiều rộng của khung trò chơi
#define HEIGHT 20 // Chiều cao của khung trò chơi
#define BODY "■" // Thành phần thân rắn
#define PREY "♥" // Mồi của rắn
#pragma endregion

// Enum điều hướng
enum class Direction
{
	up,
	right,
	down,
	left
};

// Cấu trúc tọa độ điểm
struct Point
{
	int x;
	int y;
};

#pragma region Biến toàn cục
// Khởi tạo vị trí con rắn chính giữa khung hình khi bắt đầu trò chơi.
vector<Point> snake = {
	Point{ WIDTH / 2 + 2, HEIGHT / 2 },
	Point{ WIDTH / 2 + 1, HEIGHT / 2 },
	Point{ WIDTH / 2, HEIGHT / 2 },
	Point{ WIDTH / 2 - 1, HEIGHT / 2 },
	Point{ WIDTH / 2 - 2, HEIGHT / 2 }
};
Direction direction = Direction::right;// Khởi tạo hướng di chuyển của rắn là sang phải
Point prey;// Khởi tạo biến mồi của rắn
int score = 0;// Khởi tạo biến điểm số.
int speed = 300;// Khởi tạo biến tốc độ di chuyển của rắn
Point prevTail;// Khởi tạo biến lưu đuôi rắn trước khi di chuyển
#pragma endregion

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

#pragma endregion

int main() {
    SetConsoleOutputCP(CP_UTF8); // Cho phép hiển thị ký tự UTF-8

    return 0;
}