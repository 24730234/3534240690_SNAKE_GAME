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
    void move();// Hàm chi chuyển rắn.
    bool isHitWall();// Hàm kiểm tra rắn đụng tường.
    bool isBiteItself();// Hàm kiểm tra rắn tự cắn.
    void growing();// Hàm rắn lớn lên.
    bool isAtePrey();// Hàm kiểm tra ăn mồi.
    void drawSnakePart(Point p);// Hàm hiển thị thành phần của rắn.
    void drawSnake();// Hàm vẽ con rắn.
    void drawHeadnTail();// Hàm vẽ đầu và đuôi rắn.
};

#endif //SNAKE_H
