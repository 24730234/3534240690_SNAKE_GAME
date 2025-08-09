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

class Snake {
  private:
    Control* _control;
  public:
    Snake(Control &control);
    void move();
    bool isHitWall();
    bool isBiteItself();
    void growing();
    bool isAtePrey();
};

#endif //SNAKE_H
