#ifndef MENU_H
#define MENU_H
#include <vector>
#include <conio.h>
#include "Control.h"
#include <windows.h>
#include "Sound.h"
#include <iostream>

using namespace std;

extern vector<string> menu;

/// @brief Hàm in menu
/// @param menu các lựa chọn trong menu
/// @param selectedIndex vị trí đang được lựa chọn
void printMenu(vector<string>& menu, int& selectedIndex);

int returnSelectedIndex(Control control, char key, int& selectedIndex);

void showStartMenu();

#endif // MENU_H