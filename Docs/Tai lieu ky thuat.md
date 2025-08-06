Tài liệu Kỹ thuật Game Rắn Săn Mồi (C++ Console)
Tài liệu này cung cấp cái nhìn sâu sắc về cấu trúc kỹ thuật, cách thức hoạt động của các hàm và các thuật toán cốt lõi trong game Rắn Săn Mồi phiên bản console C++ đã được cung cấp.

1. Mô tả Kỹ thuật Chung
Game Rắn Săn Mồi này được xây dựng như một ứng dụng console đơn giản trên nền tảng Windows, sử dụng các thư viện chuẩn C++ và các hàm API của Windows để điều khiển màn hình console. Game hoạt động dựa trên một vòng lặp chính (game loop) liên tục cập nhật trạng thái game và vẽ lại giao diện. Các đối tượng trong game (rắn, táo, tường) được biểu diễn bằng các ký tự ASCII và vị trí của chúng được quản lý thông qua hệ tọa độ (x, y) trên console.

2. Cấu trúc Dữ liệu và Biến Toàn cục
Các cấu trúc dữ liệu và biến toàn cục đóng vai trò quan trọng trong việc quản lý trạng thái của game.

#define WIDTH 40 & #define HEIGHT 20:

Mô tả: Các macro định nghĩa kích thước chiều rộng và chiều cao của khu vực chơi game (bảng game) trên console, tính bằng số ký tự.

Cách sử dụng: Được dùng để xác định biên của game và kích thước của các vòng lặp khi vẽ khung hoặc tạo vị trí ngẫu nhiên.

#define BODY '*' & #define APPLE 'O':

Mô tả: Các macro định nghĩa ký tự ASCII sẽ được dùng để biểu diễn các phần của rắn và quả táo trên màn hình console.

Cách sử dụng: Được in ra console tại các tọa độ tương ứng để vẽ các đối tượng game.

enum class Direction { up, right, down, left };:

Mô tả: Một kiểu liệt kê (enum class) định nghĩa bốn hướng di chuyển cơ bản của rắn. Việc sử dụng enum class giúp tạo ra các hằng số có phạm vi riêng, tránh xung đột tên với các biến hoặc hàm khác.

Cách sử dụng: Biến direction sẽ lưu trữ một trong các giá trị này để xác định hướng di chuyển tiếp theo của đầu rắn.

struct Point { int x; int y; };:

Mô tả: Một cấu trúc đơn giản để lưu trữ tọa độ Descartes (x, y) trên màn hình console.

Cách sử dụng: Được dùng để biểu diễn vị trí của từng đoạn thân rắn, đầu rắn, đuôi rắn, và quả táo.

vector<Point> snake:

Mô tả: Một std::vector chứa các đối tượng Point, đại diện cho tất cả các đoạn thân của con rắn. Phần tử đầu tiên (snake[0]) luôn là đầu rắn.

Cách sử dụng: Được cập nhật trong mỗi khung hình để mô phỏng chuyển động của rắn. Kích thước của vector thay đổi khi rắn ăn táo hoặc khi game khởi tạo/reset.

Direction direction:

Mô tả: Biến toàn cục kiểu Direction lưu trữ hướng di chuyển hiện tại của đầu rắn.

Cách sử dụng: Được cập nhật dựa trên đầu vào của người chơi và được dùng để tính toán vị trí mới của đầu rắn.

Point apple:

Mô tả: Một đối tượng Point lưu trữ tọa độ hiện tại của quả táo.

Cách sử dụng: Được cập nhật khi rắn ăn táo, và được dùng để vẽ táo trên màn hình.

int score:

Mô tả: Biến toàn cục lưu trữ điểm số hiện tại của người chơi.

Cách sử dụng: Tăng lên mỗi khi rắn ăn táo và được hiển thị trên console.

int speed:

Mô tả: Biến toàn cục xác định tốc độ của game, tính bằng mili giây. Đây là thời gian chờ giữa mỗi lần cập nhật trạng thái game. Giá trị nhỏ hơn tương ứng với tốc độ nhanh hơn.

Cách sử dụng: Được điều chỉnh dựa trên cấp độ chơi mà người dùng chọn trong menu bắt đầu.

Point prevTail:

Mô tả: Một đối tượng Point lưu trữ tọa độ của đoạn đuôi rắn trước khi nó di chuyển.

Cách sử dụng: Dùng để xóa ký tự của đoạn đuôi cũ trên console sau khi rắn di chuyển, tạo hiệu ứng chuyển động mượt mà.

3. Mô tả Chi tiết Hàm và Cách Sử dụng
Các hàm được tổ chức thành các nhóm chức năng chính.

3.1. Hàm Giao diện Console (Console Interface Functions)
void gotoxy(int x, int y)

Mô tả: Di chuyển con trỏ console đến vị trí (x, y) đã chỉ định. Đây là một hàm API của Windows.

Cách sử dụng: Được gọi