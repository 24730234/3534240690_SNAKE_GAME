//
// Created by Asus on 8/9/2025.
//
#include "SnakeFunction.h"

SnakeFunction::SnakeFunction(Control& control) {
    _control = &control;
}

void SnakeFunction::move() {
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


void SnakeFunction::growing() {
    snake.push_back(prevTail);
}

bool SnakeFunction::isHitWall() {
    return snake[0].x == 0 || snake[0].y == 0 || snake[0].x == WIDTH || snake[0].y == HEIGHT;
}

bool SnakeFunction::isBiteItself() {
    Point head = snake[0];
    for (size_t i = 1; i < snake.size(); i++)
        if (head.x == snake[i].x && head.y == snake[i].y)
            return true;
    return false;
}

bool SnakeFunction::isAtePrey() {
    return snake[0].x == prey.x && snake[0].y == prey.y;
}

void SnakeFunction::drawHeadnTail() {
    gotoxy(snake[0].x, snake[0].y);
    std::cout << BODY;
    gotoxy(prevTail.x, prevTail.y);
    std::cout << ' '; // Clear the old tail
}

void SnakeFunction::drawSnakePart(Point p) {
    gotoxy(p.x, p.y);
    std::cout << BODY;
}

void SnakeFunction::drawSnake() {
    for (size_t i = 0; i < snake.size(); i++)
        drawSnakePart(snake[i]);
}

