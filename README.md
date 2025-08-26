# 📘 Tài liệu Kỹ thuật Game Rắn Săn Mồi (C++ Console)

## I. Giới thiệu
Game **Rắn Săn Mồi** được xây dựng trên nền tảng **C++ console (Windows)**, sử dụng thư viện chuẩn C++ kết hợp với **Windows API** để điều khiển màn hình console.  
Game chạy theo **game loop** liên tục: nhận input → cập nhật trạng thái rắn/mồi → vẽ lại giao diện.

---

## II. Cấu trúc mã nguồn
- **Common.cpp**: Biến toàn cục, vẽ khung, khởi tạo game, chọn cấp độ, hiển thị điểm số.  
- **Control.cpp**: Quản lý hướng di chuyển (rắn và menu).  
- **Menu.cpp**: Menu chính, menu kết thúc, vòng lặp game.  
- **SnakeFunction.cpp**: Các thao tác với rắn (di chuyển, lớn lên, kiểm tra va chạm).  
- **Sound.cpp**: Quản lý âm thanh (bắt đầu, ăn mồi, thua).  

---

## III. Cấu trúc dữ liệu và biến toàn cục

```cpp
#define WIDTH  40
#define HEIGHT 20
#define BODY "■"  Thành phần thân rắn
#define PREY "♥"  Mồi của rắn
```

- `WIDTH`, `HEIGHT`: kích thước khu vực chơi.  
- `BODY`: ký tự thân rắn.  
- `PREY`: ký tự mồi.  

```cpp
struct Point { int x; int y; };
```
- Lưu tọa độ (x, y) trên console.  

```cpp
std::vector<Point> snake;
Point prey;
Point prevTail;
int score;
int speed;
```
- `snake`: danh sách các đoạn thân.  
- `prey`: vị trí mồi hiện tại.  
- `prevTail`: lưu đuôi cũ để xóa.  
- `score`: điểm số.  
- `speed`: tốc độ (ms).  

```cpp
enum Direction { UP, DOWN, LEFT, RIGHT, ENTER, ESC, NONINPUT };
```
- Hướng di chuyển và phím chức năng.  

---

## IV. Các nhóm hàm chính

### 1. Giao diện console (Common.cpp)
- `gotoxy(x,y)`: di chuyển con trỏ console.  
- `drawBox()`: vẽ khung game bằng ASCII.  
- `ShowConsoleCursor(bool)`: ẩn/hiện con trỏ.  
- `displayScore()`: hiển thị điểm số bên phải khung.  
- `chooseLevel()`: cho phép chọn cấp độ (1–5) → tính tốc độ `speed = 600 - t*100`.  
- `initGame()`: reset rắn, điểm, tốc độ.  
- `genPrey()`: sinh mồi mới, tránh trùng thân rắn.  

### 2. Quản lý điều khiển (Control.cpp)
- `updateDirection(char key)`: đổi hướng rắn bằng phím mũi tên.  
- `updateDirectionMenu(char key)`: xử lý input trong menu (↑ ↓ ← → Enter Esc).  
- `isOpposite(newDir)`: ngăn rắn quay ngược 180°.  

### 3. Menu & vòng lặp chính (Menu.cpp)
- `printMenu()`: in menu với highlight.  
- `showStartMenu()`: menu khởi động (Play/Exit).  
- `showEndMenu()`: hiển thị điểm khi thua, hỏi chơi lại.  
- `startGame()`: vòng lặp game: di chuyển rắn, kiểm tra va chạm, cập nhật điểm.  

### 4. Hàm xử lý rắn (SnakeFunction.cpp)
- `move()`: di chuyển rắn theo hướng.  
- `growing()`: thêm một đoạn vào đuôi.  
- `isHitWall()`: kiểm tra chạm tường.  
- `isBiteItself()`: kiểm tra cắn thân.  
- `isAtePrey()`: kiểm tra ăn mồi.  
- `drawSnake()`, `drawHeadnTail()`: vẽ rắn và cập nhật từng bước.  

### 5. Âm thanh (Sound.cpp)
- `menuStartSound()`: nhạc khi vào menu.  
- `atePreySound()`: hiệu ứng ăn mồi.  
- `gameOverSound()`: hiệu ứng khi thua.  

---

## V. Quy trình kiểm thử
1. **Va chạm tường**: đảm bảo `isHitWall()` trả về đúng.  
2. **Cắn thân**: kiểm tra `isBiteItself()`.  
3. **Ăn mồi**: `genPrey()` luôn sinh mồi hợp lệ.  
4. **Tốc độ**: test các cấp độ từ 1–5.  
5. **Hiển thị**: khung không lỗi, điểm số rõ ràng, rắn không bị “nhấp nháy”.  
6. **Menu**: di chuyển mượt bằng phím mũi tên, Enter, ESC.  
7. **Âm thanh**: sự kiện tương ứng phát đúng file `.wav`.  
