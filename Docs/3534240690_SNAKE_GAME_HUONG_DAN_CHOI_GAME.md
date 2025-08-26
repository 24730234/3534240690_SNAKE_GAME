**Giới thiệu & Lịch sử Snake Game**

Snake Game (Rắn săn mồi) là một trong những trò chơi điện tử kinh điển
nhất. Người chơi điều khiển con rắn để ăn mồi, làm rắn dài ra, đồng thời
phải tránh va vào tường hoặc tự cắn vào chính mình.

- 1976: Trò chơi đầu tiên mang cơ chế này là *Blockade* (arcade).

- 1980s: Xuất hiện trên nhiều hệ máy gia đình (Atari, Commodore, BBC
  Micro).

- 1997: Trở thành huyền thoại toàn cầu khi Nokia tích hợp trên điện
  thoại.

- Ngày nay: Snake thường được dùng làm bài tập lập trình căn bản vì dễ
  hiểu nhưng bao quát nhiều kỹ thuật (console, bàn phím, vòng lặp game).

Phiên bản trong project này viết bằng C++ console cho Windows, sử dụng
ký tự để hiển thị rắn (■), mồi (♥), khung (╔═╗...╚═╝) và điểm số.

**1) Tổng quan**

- Con rắn: ký hiệu ■ (đầu và thân giống nhau).

- Mồi: ký hiệu ♥.

- Khung viền: ╔═╗ ... ║ ║ ... ╚═╝.

- Điểm số: hiển thị ở bên phải console.

**2) Yêu cầu hệ thống**

- Chạy trên Windows (Windows 10/11).

- Người dùng cuối không cần IDE như VS Code hay CLion.

- Chỉ cần có file thực thi .exe là có thể chơi ngay.

**3) Cách chạy**

**3.1. Chạy trực tiếp (dành cho người dùng cuối)**

- Tìm file thực thi, ví dụ: Game.exe.

- Nhấp đúp vào file .exe để mở cửa sổ console và chơi.

- Không cần mở Visual Studio hay bất kỳ IDE nào.

**3.2. Build từ source (dành cho nhà phát triển)**

- Có thể build bằng Visual Studio hoặc MinGW/CLion với CMakeLists.txt.

- Sau khi build, file .exe nằm trong thư mục build (ví dụ:
  out/build/x64-Debug/).

**4) Giao diện game**

**Menu chính**

- Khi khởi động game, màn hình menu chính xuất hiện.

- Dùng phím mũi tên ↑ / ↓ để di chuyển con trỏ lựa chọn giữa các mục
  Play, Settings, Exit.

- Nhấn Enter để xác nhận mục đang chọn.

- Nếu đang ở trong Settings:

  - Có thể dùng phím số 1--5 hoặc mũi tên để chọn cấp độ (Level).

  - Nhấn Enter để lưu lựa chọn.

- Nhấn Esc ở menu chính → thoát game ngay.

**Gameplay**

- Rắn: ■

- Mồi: ♥

- Khung: ╔═╗...╚═╝

- Điểm số: hiện bên phải màn hình console

**5) Điều khiển**

- **Trong menu:**

  - ↑/↓/←/→ để chọn

  - Enter xác nhận

  - Esc thoát

- **Trong game:**

  - ←/→/↑/↓ để đổi hướng (không được quay 180° ngay lập tức)

  - Esc thoát về màn hình kết thúc (Game Over)

**6) Cách chơi**

1.  Từ menu chính, chọn Play.

2.  Nếu muốn, vào Settings để chọn cấp độ (1--5).

    - Công thức tốc độ: speed = 600 − level × 100 (ms/tick).

    - Ví dụ: Level 3 → 300 ms.

3.  Ăn mồi ♥ để tăng điểm và làm rắn dài hơn.

4.  Rắn di chuyển liên tục, người chơi đổi hướng bằng phím mũi tên.

Game Over khi:

- Rắn va vào tường

- Rắn tự cắn vào thân

- Người chơi nhấn ESC trong lúc chơi

**7) Tính điểm & cấp độ**

- Ăn một mồi → +1 điểm.

- Cấp độ càng cao → tốc độ di chuyển càng nhanh.

- Điểm được cập nhật và hiển thị ngay trong console.

**8) Mẹo chơi**

- Tránh rẽ 180° đột ngột → dễ tự cắn.

- Khi thân dài, ưu tiên đi dọc viền để giữ trung tâm trống.

- Tập phản xạ từ cấp 1--2 rồi tăng dần.

\-\-\-\-- KẾT THÚC \-\-\-\--
