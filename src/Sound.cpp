#include "Sound.h"

// Hàm chạy âm thanh khi bắt đầu danh mục.
void menuStartSound()
{
    PlaySound(TEXT("assets/sounds/start.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}

// Hàm chạy âm thanh khi ăn mồi.
void atePreySound()
{
    PlaySound(TEXT("assets/sounds/bite.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}

// Hàm chạy âm thanh khi kết thúc trò chơi.
void gameOverSound()
{
    PlaySound(TEXT("assets/sounds/gameover.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}
