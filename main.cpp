// Vẽ khung trò chơi
void drawBox()
{
    for (size_t i = 0; i < WIDTH; i++)
        cout << '=';
    gotoxy(0, HEIGHT);
    for (size_t i = 0; i < WIDTH; i++)
        cout << '=';
    for (size_t i = 1; i < HEIGHT; i++)
    {
        gotoxy(0, i);
        cout << '|';
    }
    for (size_t i = 1; i < HEIGHT; i++)
    {
        gotoxy(WIDTH, i);
        cout << '|';
    }
}