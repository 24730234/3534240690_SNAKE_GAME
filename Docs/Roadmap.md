Lộ trình Dự án Game Rắn Săn Mồi
Lộ trình này phác thảo các giai đoạn và tác vụ cần thực hiện trước khi bắt đầu viết mã nguồn cho dự án game Rắn Săn Mồi. Đây là các bước quan trọng để đảm bảo dự án có định hướng rõ ràng, thiết kế vững chắc và kế hoạch thực hiện hiệu quả.

Giai đoạn 1: Khởi tạo & Nghiên cứu (Initiation & Research)
Mục tiêu: Định hình ý tưởng ban đầu, xác định phạm vi dự án và thu thập thông tin cần thiết.

Tác vụ:
1.1. Xác định Phạm vi Dự án và Mục tiêu:

[ ] Xác định loại game: Game console, web-based, mobile? (Ví dụ: Game console C++ như mã nguồn đã cung cấp).

[ ] Tính năng cốt lõi: Di chuyển rắn, ăn mồi, tăng chiều dài, va chạm tường/thân, điểm số.

[ ] Mục tiêu dự án: Học tập, giải trí cá nhân, sản phẩm demo?

1.2. Nghiên cứu Thị trường & Đối thủ (nếu có):

[ ] Phân tích các phiên bản game Rắn săn mồi hiện có (cả console và các nền tảng khác) để học hỏi và tìm ý tưởng độc đáo.

[ ] Xác định các tính năng phổ biến và những điểm có thể cải thiện.

1.3. Xác định Nền tảng và Công nghệ Mục tiêu:

[ ] Nền tảng: Windows Console (như mã nguồn đã cung cấp).

[ ] Ngôn ngữ: C++.

[ ] Thư viện/Framework: Các thư viện console cơ bản (windows.h, conio.h).

Giai đoạn 2: Phân tích Yêu cầu & Thiết kế Kiến trúc (Requirements Analysis & Architectural Design)
Mục tiêu: Chuyển đổi ý tưởng thành các yêu cầu cụ thể và phác thảo cấu trúc hệ thống tổng thể.

Tác vụ:
2.1. Phân tích Yêu cầu Chức năng (Functional Requirements):

[ ] Luật chơi chi tiết:

Quy tắc di chuyển của rắn.

Cơ chế ăn mồi và tăng điểm.

Điều kiện game over (va chạm tường, tự cắn).

Cơ chế tăng tốc độ rắn theo điểm số.

[ ] Giao diện người dùng (Console):

Màn hình bắt đầu (Start Menu): Chọn độ khó, tùy chọn thoát.

Màn hình chơi game: Hiển thị bảng game, rắn, mồi, điểm số.

Màn hình kết thúc game (End Menu): Hiển thị điểm cuối cùng, tùy chọn chơi lại/thoát.

[ ] Đầu vào: Phím mũi tên để điều khiển, phím 'q' để thoát, phím Enter/số để chọn menu.

2.2. Phân tích Yêu cầu Phi chức năng (Non-Functional Requirements):

[ ] Hiệu suất: Game chạy mượt mà trên console, không giật lag.

[ ] Khả năng bảo trì: Mã nguồn dễ đọc, dễ hiểu, dễ mở rộng.

[ ] Khả năng tương thích: Chạy trên các phiên bản Windows khác nhau.

2.3. Thiết kế Kiến trúc Tổng thể:

[ ] Cấu trúc Module: Phân chia game thành các module logic rõ ràng (Game Logic, Console I/O, Menu Management, Data Structures).

[ ] Luồng điều khiển: Phác thảo luồng chính của game (khởi động -> menu -> chơi game -> kết thúc -> menu kết thúc).

[ ] Quản lý trạng thái: Xác định các biến toàn cục cần thiết để quản lý trạng thái game (vị trí rắn, hướng, điểm, vị trí táo, tốc độ, v.v.).

Giai đoạn 3: Thiết kế Chi tiết (Detailed Design)
Mục tiêu: Chuyển đổi kiến trúc tổng thể thành các bản thiết kế cụ thể, sẵn sàng cho việc lập trình.

Tác vụ:
3.1. Thiết kế Cấu trúc Dữ liệu Chi tiết:

[ ] Point struct: Định nghĩa x, y.

[ ] Direction enum class: up, right, down, left.

[ ] snake: std::vector<Point>.

[ ] apple: Point.

3.2. Thiết kế Logic Game Chi tiết (Flowcharts/Pseudocode):

[ ] initializeGame(): Chi tiết các bước khởi tạo rắn, táo, điểm số.

[ ] updateGame() / Game Loop:

Luồng xử lý đầu vào.

Luồng di chuyển rắn.

Luồng kiểm tra va chạm (tường, thân).

Luồng kiểm tra ăn táo và tăng điểm/chiều dài.

[ ] genApple(): Thuật toán tạo táo ngẫu nhiên không trùng với thân rắn.

[ ] endGame(): Các bước khi game kết thúc.

3.3. Thiết kế Giao diện Console (Text-based UI):

[ ] Kích thước bảng game: Xác định WIDTH và HEIGHT tối ưu cho console.

[ ] Ký tự đại diện: Chọn ký tự cho rắn (BODY), táo (APPLE), tường (=, |).

[ ] Bố cục màn hình: Xác định vị trí hiển thị điểm số, thông báo.

3.4. Thiết kế Các Hàm và Prototype:

[ ] Liệt kê tất cả các hàm cần thiết và định nghĩa prototype của chúng (như đã có trong mã nguồn).

[ ] Xác định rõ ràng nhiệm vụ của từng hàm.


