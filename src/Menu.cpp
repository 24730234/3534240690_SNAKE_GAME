#include "Menu.h"

vector<string> menu = {"Play", "Settings", "Exit"};

void printMenu(vector<string>& menu, int& selectedIndex)
{   
    system("cls");
    cout << "\033[1m\033[37m" // bold + trắng
    R"(  _____ _   _          _  ________    _____          __  __ ______ 
 / ____| \ | |   /\   | |/ /  ____|  / ____|   /\   |  \/  |  ____|
| (___ |  \| |  /  \  | ' /| |__    | |  __   /  \  | \  / | |__   
 \___ \| . ` | / /\ \ |  < |  __|   | | |_ | / /\ \ | |\/| |  __|  
 ____) | |\  |/ ____ \| . \| |____  | |__| |/ ____ \| |  | | |____ 
|_____/|_| \_/_/    \_\_|\_\______|  \_____/_/    \_\_|  |_|______|)" 
    << "\033[0m\n";
    
    cout << endl << endl << "------------Menu------------" << endl;
    for(int i = 0; i < menu.size(); i++)
    {   
        if (selectedIndex == i)
        {
            cout << "\033[41m\033[37m" << menu[i] << "\033[0m" << endl;
        }
        else 
        {
            cout << menu[i] << endl;
        }
        
    }
}

int returnSelectedIndex(Control control, char key, int& selectedIndex)
{   
    key = _getch(); // Lấy phím bấm không cần Enter
        control.updateDirectionMenu(key);
        if (control.getDirection() != NONINPUT) // Kiểm tra có ấn phím khác ngoài các phím chức năng
        {
            if (control.getDirection() == ENTER ) // Enter
            { 
                return selectedIndex; 
            }
            else if (control.getDirection() == ESC) // ESC
            {   
                return 2;
            }
            // Điều khiển lên/xuống dựa vào enum Direction của bạn
            if (control.getDirection() == UP || control.getDirection() == LEFT) 
            {
                selectedIndex--;
                if (selectedIndex < 0) selectedIndex = menu.size() - 1;
            } 
            else if 
            (control.getDirection() == DOWN || control.getDirection() == RIGHT)
            {
                selectedIndex++;
                if (selectedIndex >= menu.size()) selectedIndex = 0;
            }
            
        }
    return -1;
}

void showStartMenu()
{
    Control control;
    int selectedIndex = 0, choose = -1;
    SnakeFunction snakeFunction(control);
    char key;
    menuStartSound();
    while (true) {
        printMenu(menu, selectedIndex);
        choose = returnSelectedIndex(control, key, selectedIndex); 
        if (choose == 0) {
            cout << "Game Start" << endl;
            startGame(snakeFunction, control);
            // se o day
            system("pause");
        }
        else if (choose == 2)
        {
            cout << "Goodbye" << endl;
            // thoat game se o day
            exit(1);
            system("pause");
            break;
        }
         
    }
}

void showEndMenu()
{
	system("cls");
	gotoxy(0, 0);
	cout << "Kết thúc trò chơi!" << endl;
	cout << "Điểm của bạn: " << score << endl;
	cout << "Bạn có muốn chơi nữa không ([y]/[n]): ";
	char option;
	cin >> option;
	option = tolower(option);
	if (option == 'y')
	{
		//resetSnake();
		//startGame();
	}
	else if (option == 'n')
		exit(1);
}

void startGame(SnakeFunction &snakeFunction, Control &control)
{
    system("cls");
    // ShowConsoleCursor(false);
    drawBox();
    snakeFunction.drawSnake();
    genPrey();
    displayScore();
    while (true)
    {
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == -32 || ch == 0xE0) // Arrow key prefix
            {
                ch = _getch(); // Get the second byte
                control.updateDirection(ch);
                // switch (ch)
                // {
                // case 72: // Up arrow
                //     if (control.getDirection() != Direction::DOWN)
                //         control.updateDirection(72);
                //     break;
                // case 77: // Right arrow
                //     if (direction != Direction::LEFT)
                //         direction = Direction::RIGHT;
                //     break;
                // case 80: // Down arrow
                //     if (direction != Direction::UP)
                //         direction = Direction::DOWN;
                //     break;
                // case 75: // Left arrow
                //     if (direction != Direction::RIGHT)
                //         direction = Direction::LEFT;
                //     break;
                // }
            }
            else if (ch == 'q') // Thoát trò chơi
            {
                showEndMenu();
                break;
            }
        }
        snakeFunction.move();
        snakeFunction.drawHeadnTail();
        if (snakeFunction.isAtePrey())
        {
            score++;
            displayScore();
            snakeFunction.growing();
            genPrey();
        }
        if (snakeFunction.isBiteItself())
        {
            // ShowConsoleCursor(true);
            showEndMenu();
            break;
        }
        if (snakeFunction.isHitWall())
        {
            // ShowConsoleCursor(true);
            showEndMenu();
            break;
        }
        Sleep(speed);
    }
}