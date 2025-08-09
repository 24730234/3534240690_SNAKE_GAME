//
// Created by Asus on 8/9/2025.
//
#include "Snake.h"

Snake::Snake(Control& control) {
    _control = &control;
}

void Snake::move() {
    std::cout << "SNAKE MOVE";
    Direction direction = _control->getDirection();
    prevTail = snake.back();
    for (size_t i = snake.size() - 1; i > 0; i--)
        snake[i] = snake[i - 1];
    if (direction == UP)
        snake[0].y -= 1;
    else if (direction == DOWN)
        snake[0].y += 1;
    else if (direction == LEFT)
        snake[0].x -= 1;
    else if (direction == RIGHT)
        snake[0].x += 1;
}


void Snake::growing() {
    snake.push_back(prevTail);
}

bool Snake::isHitWall() {
    return snake[0].x == 0 || snake[0].y == 0 || snake[0].x == WIDTH || snake[0].y == HEIGHT;
}

bool Snake::isBiteItself() {
    Point head = snake[0];
    for (size_t i = 1; i < snake.size(); i++)
        if (head.x == snake[i].x && head.y == snake[i].y)
            return true;
    return false;
}

bool Snake::isAtePrey() {
    return snake[0].x == prey.x && snake[0].y == prey.y;
}