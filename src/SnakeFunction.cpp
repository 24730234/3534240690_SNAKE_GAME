//
// Created by Asus on 8/9/2025.
//
#include "SnakeFunction.h"
using namespace std;

SnakeFunction::SnakeFunction() {
}

SnakeFunction::SnakeFunction(Control& control) {
    _control = &control;
}

void SnakeFunction::move() {
    Direction direction = _control->getDirection();
    prevTail = snake.back();// Lưu lại vị trí đuôi cũ của rắn để có thể dùng khi cần vẽ lại hoặc khi rắn lớn lên.
    // Dịch toàn bộ thân rắn: mỗi đoạn thân lấy vị trí đoạn liền trước.
    for (size_t i = snake.size() - 1; i > 0; i--)
        snake[i] = snake[i - 1];
    // Cập nhật vị trí đầu rắn theo hướng người chơi bấm.
    if (direction == UP)
        snake[0].y -= 1;
    else if (direction == DOWN)
        snake[0].y += 1;
    else if (direction == LEFT)
        snake[0].x -= 1;
    else if (direction == RIGHT)
        snake[0].x += 1;
}

// Hàm rắn lớn lên.
void SnakeFunction::growing() {
    // Khi rắn ăn mồi thì thêm một đoạn thân mới vào cuối, đúng chỗ đuôi cũ.
    snake.push_back(prevTail);
}

// Hàm kiểm tra rắn có đụng tường không.
bool SnakeFunction::isHitWall() {
    // Nếu đầu rắn chạm mép khung thì trả về true.
    return snake[0].x == 0 || snake[0].y == 0 || snake[0].x == WIDTH || snake[0].y == HEIGHT;
}

// Hàm kiểm tra rắn có cắn đuôi không.
bool SnakeFunction::isBiteItself() {
    Point head = snake[0];// Lấy vị trí đầu rắn.
    // Duyệt toàn bộ thân (từ đoạn 1 trở đi).
    // Nếu đầu rắn trùng tọa độ với bất kỳ đoạn thân nào thì rắn cắn vào chính mình.
    for (size_t i = 1; i < snake.size(); i++)
        if (head.x == snake[i].x && head.y == snake[i].y)
            return true;
    return false;
}

// Hàm kiểm tra rắn có ăn mồi không.
bool SnakeFunction::isAtePrey() {
    // So sánh vị trí đầu rắn với mồi. Nếu trùng nhau thì trả về true.
    return snake[0].x == prey.x && snake[0].y == prey.y;
}

// Hàm vẽ lại đầu rắn và xóa đuôi.
void SnakeFunction::drawHeadnTail() {
    // Đưa con trỏ console đến vị trí đầu rắn để in ký tự của thân rắn.
    gotoxy(snake[0].x, snake[0].y);
    cout << BODY;
    // Đưa con trỏ về vị trí đuôi cũ và in khoảng trắng ' ' để xóa đuôi.
    gotoxy(prevTail.x, prevTail.y);
    cout << ' ';
}

// Hàm vẽ đoạn rắn tại điểm p.
void SnakeFunction::drawSnakePart(Point p) {
    gotoxy(p.x, p.y);
    cout << BODY;
}

// Hàm vẽ toàn bộ rắn.
void SnakeFunction::drawSnake() {
    for (size_t i = 0; i < snake.size(); i++)
        drawSnakePart(snake[i]);
}

