Giai đoạn 3: Hoàn thiện và Tối ưu hóa Cốt lõi (Core Completion & Optimization)
Mục tiêu: Đảm bảo game chạy ổn định, không lỗi và có trải nghiệm cơ bản tốt nhất. Đây là giai đoạn kiểm tra và tinh chỉnh mã nguồn hiện có.

Tác vụ:
1.1. Kiểm tra và Sửa lỗi Logic Game:

[ ] Xác minh chính xác điều kiện isHitWall() và isBiteItself().

[ ] Đảm bảo genApple() luôn tạo ra táo ở vị trí không bị rắn chiếm giữ.

[ ] Kiểm tra logic tăng tốc độ rắn khi ăn táo (speed = 600 - t * 100). Đảm bảo tốc độ tăng hợp lý và không quá nhanh ở các cấp độ cao.

1.2. Kiểm tra và Tối ưu hóa Hiển thị Console:

[ ] Đảm bảo drawHeadnTail() hoạt động chính xác, không để lại các ký tự thừa trên màn hình khi rắn di chuyển.

[ ] Kiểm tra hiển thị điểm số displayScore() để đảm bảo nó luôn cập nhật đúng và rõ ràng.

[ ] Đảm bảo khung game drawBox() hiển thị chính xác trên các kích thước console khác nhau (nếu có thể).

1.3. Cải thiện Xử lý Đầu vào:

[ ] Xử lý trường hợp người dùng nhấn phím điều hướng quá nhanh, đảm bảo hướng di chuyển của rắn được cập nhật mượt mà và không bị "nhảy" hướng.

[ ] Cải thiện xử lý đầu vào trong showStartMenu() và showEndMenu() để tránh lỗi khi người dùng nhập ký tự không phải số hoặc lựa chọn không hợp lệ.

1.4. Quản lý Trạng thái Game:

[ ] Đảm bảo resetSnake() đặt lại tất cả các biến toàn cục về trạng thái ban đầu một cách chính xác khi bắt đầu game mới.