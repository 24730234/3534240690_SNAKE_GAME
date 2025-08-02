#include <iostream>
#include <ctime> // dung cho srand
#include <window.h> // dung cho console
using namespace std;
const int width = 20; //chieu rong
const int height = 20; //chieu cao
const int Moi = 10; //so luong moi

// Khai bao bien toan cuc
int x, y; // toa do cua ran
int Score; // diem so
int nDot; // so luong dot ran
int DotX[100], DotY[100]; // Mang luu toa do cua dot ran
int MoiX, MoiY; // toa do moi
int MoiDaAn; // kiem tra so moi da an
bool GameOver = false ; // kiem tra ket thuc tro choi

// Ham sinh moi
void SinhMoi() {
    MoiX = rand() % width;
    MoiY = rand() % height;
    MoiDaAn = 0; // reset moi da an
}
// Ham khoi tao tro choi
void KhoiTao() {
    x = width / 2;
    y = height / 2;
    Score = 0;
    nDot = 0;
    MoiDaAn = 0;
    SinhMoi();
    GameOver = false;
}


int main() {
    // Thọ test (test lần 3)
    // Kiên Test Again
    // Hai test up code
    return 0;
}