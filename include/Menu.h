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
#include "Common.h"
extern vector<string> menu;

/// @brief Hàm in menu
/// @param menu các lựa chọn trong menu
/// @param selectedIndex vị trí đang được lựa chọn
void printMenu(vector<string>& menu, int& selectedIndex);

int returnSelectedIndex(Control control, char key, int& selectedIndex);

void showStartMenu();

void showEndMenu();

void startGame(SnakeFunction &snakeFunction, Control &control);

#endif // MENU_H