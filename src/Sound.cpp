#include "Sound.h"

void menuStartSound()
{
    PlaySound(TEXT("assets/sounds/start.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}

void atePreySound()
{
    PlaySound(TEXT("assets/sounds/bite.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}

void gameOverSound()
{
    PlaySound(TEXT("assets/sounds/gameover.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}
