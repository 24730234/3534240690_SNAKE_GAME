Tài liệu Kỹ thuật Game Rắn Săn Mồi (C++ Console)
Tài liệu này cung cấp cái nhìn sâu sắc về cấu trúc kỹ thuật, cách thức hoạt động của các hàm và các thuật toán cốt lõi trong game Rắn Săn Mồi phiên bản console C++.
I. Giai đoạn xây dựng code
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

II. Giai đoạn kiểm thử và sửa lỗi
1.1. Kiểm tra và Sửa lỗi Logic Game
Mục tiêu: Đảm bảo các quy tắc cơ bản của game được thực thi đúng, tránh các tình huống không mong muốn hoặc lỗi logic.

1.1.1. Xác minh điều kiện isHitWall():

Chi tiết kỹ thuật: Hàm này kiểm tra xem đầu rắn (snake[0]) có chạm vào bất kỳ biên nào của khung game hay không. Các điều kiện cần được xác minh là:

snake[0].x == 0: Rắn chạm biên trái.

snake[0].x == WIDTH: Rắn chạm biên phải.

snake[0].y == 0: Rắn chạm biên trên.

snake[0].y == HEIGHT: Rắn chạm biên dưới.

Kiểm thử:

Di chuyển rắn chủ động vào từng biên (trái, phải, trên, dưới) để xác nhận game kết thúc.

Kiểm tra các trường hợp đặc biệt: rắn xuất phát ngay sát biên, rắn rất dài chạm biên.

1.1.2. Xác minh điều kiện isBiteItself():

Chi tiết kỹ thuật: Hàm này kiểm tra xem đầu rắn (snake[0]) có trùng tọa độ với bất kỳ phần thân nào của nó (từ snake[1] trở đi) hay không. Vòng lặp phải bắt đầu từ phần thân thứ hai để tránh so sánh đầu rắn với chính nó.

Kiểm thử:

Cho rắn di chuyển thành hình chữ U hoặc hình tròn để đầu rắn chạm vào thân.

Kiểm tra với rắn có độ dài khác nhau (ngắn, trung bình, rất dài).

1.1.3. Đảm bảo genApple() tạo táo hợp lệ:

Chi tiết kỹ thuật: Hàm này phải tạo ra tọa độ (x, y) ngẫu nhiên cho táo sao cho nó nằm trong khung game (1 <= x < WIDTH, 1 <= y < HEIGHT) và không trùng với bất kỳ phần nào của thân rắn. Mã nguồn hiện tại đã có vòng lặp do-while để kiểm tra trùng với rắn, cần đảm bảo vòng lặp này hoạt động hiệu quả.

Kiểm thử:

Chơi game nhiều lần, quan sát vị trí táo xuất hiện.

Kiểm tra khi rắn rất dài, chiếm gần hết màn hình, táo vẫn phải xuất hiện ở vị trí hợp lệ.

1.1.4. Kiểm tra logic tăng tốc độ rắn:

Chi tiết kỹ thuật: Logic speed = 600 - t * 100 (trong đó t là cấp độ chơi) điều chỉnh tốc độ game. Cần đảm bảo rằng tốc độ tăng tuyến tính và có giới hạn hợp lý (ví dụ: không quá nhanh đến mức không thể điều khiển, hoặc không quá chậm).

Kiểm thử:

Chơi ở các cấp độ khác nhau (1 đến 5) để cảm nhận sự thay đổi tốc độ.

Kiểm tra xem Sleep(speed) có hoạt động đúng với giá trị speed được tính toán hay không.

1.2. Kiểm tra và Tối ưu hóa Hiển thị Console
Mục tiêu: Đảm bảo giao diện game trên console được vẽ chính xác, rõ ràng và không có lỗi hiển thị.

1.2.1. Đảm bảo drawHeadnTail() hoạt động chính xác:

Chi tiết kỹ thuật: Hàm này có nhiệm vụ vẽ đầu rắn mới và xóa đuôi rắn cũ. Điều quan trọng là ký tự ' ' (khoảng trắng) phải được in đúng vị trí prevTail để xóa dấu vết của đuôi rắn cũ.

Kiểm thử:

Quan sát kỹ chuyển động của rắn: không được có các ký tự BODY cũ còn sót lại trên đường đi của rắn.

Kiểm tra ở tốc độ cao để đảm bảo không có hiện tượng "nhấp nháy" hoặc "vết mờ" do xóa không kịp.

1.2.2. Kiểm tra hiển thị điểm số displayScore():

Chi tiết kỹ thuật: Hàm này in điểm số ra một vị trí cố định ngoài khung game. Cần đảm bảo vị trí in không bị chồng lấn với khung game hoặc các thông báo khác, và điểm số được cập nhật ngay lập tức sau khi rắn ăn táo.

Kiểm thử:

Quan sát điểm số khi chơi game, đảm bảo nó tăng đúng và hiển thị rõ ràng.

Kiểm tra khi điểm số đạt các giá trị lớn (ví dụ: 10, 100) để đảm bảo không bị tràn hoặc lệch vị trí.

1.2.3. Đảm bảo khung game drawBox() hiển thị chính xác:

Chi tiết kỹ thuật: Hàm này vẽ các ký tự = và | để tạo khung. Cần đảm bảo các ký tự này được in đúng vị trí (0,0) đến (WIDTH, HEIGHT) và tạo thành một hình chữ nhật kín.

Kiểm thử:

Kiểm tra hình dạng của khung game khi khởi động.

Thay đổi giá trị WIDTH và HEIGHT (trong MACRO) để xem khung có tự điều chỉnh đúng không.

1.3. Cải thiện Xử lý Đầu vào
Mục tiêu: Đảm bảo người chơi có thể điều khiển rắn mượt mà và các tùy chọn menu phản hồi chính xác.

1.3.1. Xử lý trường hợp nhấn phím điều hướng quá nhanh:

Chi tiết kỹ thuật: Trong game loop, _kbhit() kiểm tra xem có phím nào được nhấn không, sau đó _getch() đọc phím đó. Nếu người chơi nhấn nhiều phím nhanh chóng giữa các lần cập nhật game, có thể xảy ra tình trạng mất hoặc bỏ qua đầu vào. Cần đảm bảo rằng chỉ một hướng được ghi nhận mỗi lần cập nhật game để tránh rắn "quay đầu" không mong muốn. Logic hiện tại đã có kiểm tra if (direction != Direction::down) để ngăn quay ngược 180 độ, cần đảm bảo nó đủ mạnh.

Kiểm thử:

Nhấn liên tục các phím điều hướng để xem rắn có di chuyển mượt mà hay không.

Thử nhấn nhanh các phím ngược chiều (ví dụ: đang đi lên, nhấn xuống ngay lập tức) để xác nhận rắn không quay đầu.

1.3.2. Cải thiện xử lý đầu vào trong menu:

Chi tiết kỹ thuật: Trong showStartMenu() và showEndMenu(), cin >> option được sử dụng để lấy đầu vào. Nếu người dùng nhập ký tự không phải số hoặc một chuỗi, cin có thể gặp lỗi và gây ra vòng lặp vô hạn hoặc hành vi không mong muốn.

Kiểm thử:

Nhập các ký tự chữ cái hoặc chuỗi vào menu thay vì số.

Nhập các số không hợp lệ (ví dụ: 0, 3 khi chỉ có 1, 2).

Giải pháp đề xuất: Sử dụng cin.fail() và cin.clear(), cin.ignore() để xử lý lỗi đầu vào và xóa bộ đệm.

1.4. Quản lý Trạng thái Game
Mục tiêu: Đảm bảo game có thể được khởi động lại hoặc đặt lại về trạng thái ban đầu một cách chính xác.

1.4.1. Đảm bảo resetSnake() đặt lại tất cả biến toàn cục:

Chi tiết kỹ thuật: Hàm này phải đặt lại score, direction, và cấu trúc snake về các giá trị khởi tạo ban đầu. Cần kiểm tra xem có biến toàn cục nào khác cần được đặt lại (ví dụ: speed nếu nó thay đổi trong quá trình chơi) hay không.

Kiểm thử:

Chơi game, đạt điểm cao, sau đó chọn chơi lại. Đảm bảo điểm số về 0, rắn về vị trí ban đầu, và tốc độ game cũng được reset.

Kiểm tra sau khi game over và chọn chơi lại, game có thực sự bắt đầu lại từ đầu không.

