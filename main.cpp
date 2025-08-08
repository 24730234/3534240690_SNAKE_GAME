#include <iostream>
#include <conio.h>// dung cho _kbhit() getch() nhan du lieu tu ban phim
#include <ctime> // dung cho srand
#include <windows.h> // dung cho console
#include <locale>
using namespace std;
const int width = 40; //chieu rong
const int height = 20; //chieu cao
const int Moi = 10; //so luong moi

enum HuongDi {
    DUNG=0, LEN, XUONG, TRAI, PHAI
};
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
HuongDi huongDi;
// Ham sinh moi
void SinhMoi() {
    MoiX = rand() % width;
    MoiY = rand() % height;
    // MoiDaAn = 0; // reset moi da an
}
// Ham khoi tao tro choi
void KhoiTao() {
    huongDi = LEN;// cho ran bat dau di chuyen LEN
    x = width / 2;
    y = height / 2;
    Score = 0;
    nDot = 0;
    MoiDaAn = 0;
    SinhMoi();
    MoiHienTai = true;
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
            cout << char(3); // hinh trai tim
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

void chonPhimDiChuyen() {
    if (_kbhit()) { // _kbhit() dung de kiem tra co tin hieu tu ban phim khong va khong can cho
        switch (_getch()) {
            case 'w': {
                if (huongDi != XUONG) { // dieu kien tranh di chuyen dau ran vao than khi di chuyen len
                    huongDi = LEN;
                }
                break;
            }
            case 's': {
                if (huongDi != LEN) { // dieu kien tranh di chuyen dau ran vao than khi di chuyen xuong
                    huongDi = XUONG;
                }
                break;
            }
            case 'a': {
                if (huongDi != PHAI) { // dieu kien tranh di chuyen dau ran vao than khi di chuyen trai
                    huongDi = TRAI;
                }
                break;
            }
            case 'd': {
                if (huongDi != TRAI) { // dieu kien tranh di chuyen dau ran vao than khi di chuyen phai
                    huongDi = PHAI;
                }
                break;
            }
            default:
                break;
        }
    }
}

void diChuyenRan() {
    int luiX = DotX[0];
    int luiY = DotY[0];
    DotX[0] = x;
    DotY[0] = y;
    int lui2X, lui2Y;
    for (int i = 1; i < width; i++) {
        lui2X = DotX[i];
        lui2Y = DotY[i];
        DotX[i] = luiX;
        DotY[i] = luiY;
        luiX = lui2X;
        luiY = lui2Y;
    }
    switch (huongDi) {
        case LEN: {
            y --;
            break;
        }
        case XUONG: {
            y ++;
            break;
        }
        case TRAI: {
            x --;
            break;
        }
        case PHAI: {
            x ++;
            break;
        }
        default:
            break;
    }

    for (int i = 0; i < nDot; i++) {
        if (x == DotX[i] && y == DotY[i]) {
            GameOver = true;
        }
    }

    if (x < 0 || x > width || y < 0 || y > height) {
        GameOver = true;
    }

    if (x == MoiX && y == MoiY) {
        DiemSo += 10;
        MoiDaAn++;
        nDot++;
        SinhMoi();
    }
}

int main() {
    showStartMenu();

    return 0;
}