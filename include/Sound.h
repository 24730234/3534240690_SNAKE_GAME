#ifndef SOUND_H
#define SOUND_H
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

// Âm thanh chạy file .exe
void menuStartSound();

// Âm thanh rắn ăn mồi
void atePreySound();

// Âm thanh gameover
void gameOverSound();
#endif // SOUND_H