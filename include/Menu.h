#ifndef MENU_H
#define MENU_H
#include <vector>
#include <conio.h>
#include "Control.h"
#include <windows.h>
#include "Sound.h"
#include <iostream>
#include "Common.h"
#include "SnakeFunction.h"
using namespace std;

extern vector<string> menu;

/// @brief Hàm in menu
/// @param menu các lựa chọn trong menu
/// @param selectedIndex vị trí đang được lựa chọn
void printMenu(vector<string>& menu, int& selectedIndex);

// Xử lý di chuyển trong danh mục dựa vào phím bấm.
int returnSelectedIndex(Control control, char key, int& selectedIndex);

// Hiển thị danh mục bắt đầu game.
void showStartMenu();

// Hiển thị danh mục kết thúc game.
void showEndMenu();

void startGame(SnakeFunction &snakeFunction, Control &control);

#endif // MENU_H