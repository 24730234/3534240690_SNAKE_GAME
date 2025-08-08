#include <iostream>
#include <ctime> // dung cho srand
#include "Menu.h"
#include "Control.h"

using namespace std;

const int width = 20; //chieu rong
const int height = 20; //chieu cao
const int Moi = 10; //so luong moi

// Khai bao bien toan cuc
int x, y; // toa do cua ran
int DiemSo; // diem so
int nDot; // so luong dot ran
int DotX[100], DotY[100]; // Mang luu toa do cua dot ran
int MoiX, MoiY; // toa do moi
int MoiDaAn; // kiem tra so moi da an
bool GameOver = false ; // kiem tra ket thuc tro choi
bool MoiHienTai = false; // kiem tra moi hien tai
int Score;
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
// Ham ve giao dien
void VeGiaoDien() {
    system("cls"); // xoa man hinh console
    for (int i = 0; i < width + 2; i++) cout << "#"; // ve duong vien
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
        if (j == 0) cout <<"#";
        bool print = false;
        // In dau ran
        if (i == y && j == x) {
            cout << char(248); // hinh tron
            print = true;
        }
        // In than ran
        else {
            for (int k = 0; k < nDot; k++) {
                if (DotX[k] == j && DotY[k] == i) {
                    cout << char(248); // hinh tron
                    print = true;
                    break;
                }
            }
        }               
        // In moi
        if (!print && MoiHienTai && MoiX == j && MoiY == i) {
            cout << char(248); // hinh vuong
            print = true;
        }
        // In khoang trang
        if (!print) cout << " ";
        if (j == width - 1) cout << "#"; // ve duong vien
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++) cout << "#"; // ve duong vien
    cout << endl;
    cout << "Diem so: " << DiemSo << endl; // hien thi diem so  
    cout << "So moi da an: " << MoiDaAn << "/" << Moi << endl; // hien thi so moi da an
    cout << "Chieu dai con ran: " << nDot + 1   << endl; // hien thi chieu dai con ran
}


int main() {
    showStartMenu();

    return 0;
}