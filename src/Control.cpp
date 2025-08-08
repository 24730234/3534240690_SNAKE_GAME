#include "Control.h"

Control::Control() {
    currentDir = RIGHT; // Ban đầu rắn đi sang phải
}

Direction Control::getDirection() const {
    return currentDir;
}

void Control::updateDirection(char key) {
    Direction newDir = currentDir;

    switch (key) {
        case 'w': case 'W':
            newDir = UP;
            break;
        case 's': case 'S':
            newDir = DOWN;
            break;
        case 'a': case 'A':
            newDir = LEFT;
            break;
        case 'd': case 'D':
            newDir = RIGHT;
            break;
    }

    // Chỉ đổi hướng nếu không phải hướng ngược lại
    if (!isOpposite(newDir)) {
        currentDir = newDir;
    }
}

void Control::updateDirectionMenu(char key)
{
    Direction newDir = currentDir;

    switch (key) {
        case 'w': case 'W':
            newDir = UP;
            break;
        case 's': case 'S':
            newDir = DOWN;
            break;
        case 'a': case 'A':
            newDir = LEFT;
            break;
        case 'd': case 'D':
            newDir = RIGHT;
            break;
        case '\r': 
            newDir = ENTER;
            break;
        case '\x1B':
            newDir = ESC;
            break;
        default:
            newDir = NONINPUT;
            break;
    }

    currentDir = newDir;
}

bool Control::isOpposite(Direction newDir) const {
    return (currentDir == UP && newDir == DOWN) ||
           (currentDir == DOWN && newDir == UP) ||
           (currentDir == LEFT && newDir == RIGHT) ||
           (currentDir == RIGHT && newDir == LEFT);
}