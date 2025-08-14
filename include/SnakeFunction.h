//
// Created by Asus on 8/8/2025.
//
#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <vector>
#include <conio.h>
#include "Control.h"
#include "Common.h"

class SnakeFunction {
  private:
    Control* _control;
  public:
    SnakeFunction();
    SnakeFunction(Control &control);
    void move();
    bool isHitWall();
    bool isBiteItself();
    void growing();
    bool isAtePrey();
    void drawSnakePart(Point p);// Hàm hiển thị thành phần của rắn.
    void drawSnake();// Hàm vẽ con rắn.
    void drawHeadnTail();// Hàm vẽ đầu và đuôi rắn.
};

#endif //SNAKE_H
