Bản thiết kế Chi tiết (Detailed Design)
Mã nguồn C++

1.1. Cấu trúc Dữ liệu (Data Structures)
Point struct:

int x: Tọa độ hoành độ.

int y: Tọa độ tung độ.

Được sử dụng để biểu diễn vị trí của các đoạn thân rắn, đầu rắn, và quả táo.

Direction enum class:

up, right, down, left: Định nghĩa các hướng di chuyển của rắn. Sử dụng enum class giúp tránh xung đột tên và cải thiện tính an toàn kiểu dữ liệu.

1.2. Biến Toàn cục (Global Variables)
vector<Point> snake: Lưu trữ các tọa độ của từng đoạn thân rắn.

Direction direction: Hướng di chuyển hiện tại của rắn.

Point apple: Vị trí hiện tại của quả táo.

int score: Điểm số hiện tại của người chơi.

int speed: Tốc độ di chuyển của rắn (thời gian chờ giữa các lần cập nhật, tính bằng mili giây).

Point prevTail: Lưu trữ vị trí đuôi rắn trước khi di chuyển để xóa dấu vết cũ trên console.

WIDTH, HEIGHT macros: Định nghĩa kích thước của khung game.

BODY, APPLE macros: Ký tự đại diện cho thân rắn và quả táo.

1.3. Các Hàm Chức năng Chính (Core Functions)
Mã nguồn đã được tổ chức tốt thành các hàm với mục đích rõ ràng:

Hàm liên quan đến Console:

gotoxy(int x, int y): Di chuyển con trỏ console đến tọa độ (x, y).

ShowConsoleCursor(bool showFlag): Ẩn/hiện con trỏ console.

Hàm liên quan đến Vẽ:

drawBox(): Vẽ khung viền cho khu vực chơi game.

drawSnakePart(Point p): Vẽ một đoạn thân rắn tại điểm p.

drawSnake(): Vẽ toàn bộ con rắn.

drawHeadnTail(): Cập nhật vị trí đầu và xóa đuôi cũ sau mỗi lần di chuyển.

Hàm liên quan đến Game Logic:

move(): Cập nhật vị trí của rắn dựa trên hướng hiện tại.

isHitWall(): Kiểm tra rắn có va chạm với tường không.

isBiteItself(): Kiểm tra rắn có tự cắn vào thân không.

genApple(): Tạo ngẫu nhiên vị trí mới cho quả táo.

isAteApple(): Kiểm tra rắn có ăn táo không.

growing(): Tăng chiều dài rắn khi ăn táo.

displayScore(): Hiển thị điểm số hiện tại.

Hàm liên quan đến Menu/Trạng thái Game:

showStartMenu(): Hiển thị menu bắt đầu game, cho phép chọn độ khó.

startGame(): Logic chính của game loop, xử lý đầu vào, cập nhật trạng thái và kiểm tra điều kiện kết thúc.

showEndMenu(): Hiển thị menu kết thúc game, cho phép chơi lại.

resetSnake(): Đặt lại trạng thái rắn về ban đầu để chơi lại.