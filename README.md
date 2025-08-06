TÀI LIỆU KỸ THUẬT
Trò Chơi Rắn Săn Mồi
1. Giới Thiệu
Trò chơi Rắn săn mồi là một trò chơi cổ điển được lập trình bằng C++ trên nền tảng console Windows, sử dụng Windows console API. Người chơi điều khiển một con rắn di chuyển trong một lưới có giới hạn, ăn táo để dài ra và tăng điểm số. Trò chơi kết thúc nếu rắn va vào tường hoặc cắn vào chính mình. Trò chơi hỗ trợ các cấp độ khó, menu bắt đầu và menu kết thúc để chơi lại hoặc thoát.
Các Chức Năng Chính
•	Hiển Thị Lưới Trò Chơi: Hiển thị lưới hình chữ nhật (40x20) với tường bao quanh, con rắn và táo.
•	Di Chuyển Rắn: Rắn di chuyển liên tục theo một trong bốn hướng (lên, xuống, trái, phải), được điều khiển bằng các phím mũi tên.
•	Ăn Táo: Rắn dài ra và điểm số tăng khi ăn táo, sau đó táo xuất hiện ngẫu nhiên ở vị trí mới.
•	Phát Hiện Va Chạm: Kiểm tra va chạm với tường hoặc thân rắn, kết thúc trò chơi nếu xảy ra.
•	Cấp Độ Khó: Người chơi chọn cấp độ khó (1–5), điều chỉnh tốc độ di chuyển của rắn.
•	Giao Diện Người Dùng: Bao gồm menu bắt đầu để khởi động hoặc thoát, đếm ngược trước khi chơi, và menu kết thúc để chơi lại hoặc thoát.
•	Hiển Thị Điểm Số: Hiển thị điểm số hiện tại bên ngoài lưới trò chơi.
•	Thoát Trò Chơi: Nhấn phím 'q' trong khi chơi để mở menu kết thúc.
2. Các Class/Struct Quan Trọng
Struct: Point
•	Mục Đích: Biểu diễn tọa độ 2D trên lưới trò chơi.
•	Thành Phần:
o	int x: Tọa độ ngang (x).
o	int y: Tọa độ dọc (y).
•	Sử Dụng: Lưu trữ vị trí của các đoạn rắn và táo.
Enum Class: Direction
•	Mục Đích: Xác định bốn hướng di chuyển có thể của rắn.
•	Giá Trị:
o	up (lên)
o	right (phải)
o	down (xuống)
o	left (trái)
•	Sử Dụng: Điều khiển hướng di chuyển của rắn và ngăn chặn thay đổi hướng không hợp lệ (ví dụ: đi trái khi đang đi phải).
3. Cấu Trúc Chương Trình
Chương trình được tổ chức thành các hàm mô-đun, được nhóm bằng #pragma region để tăng tính rõ ràng. Các thành phần chính bao gồm:
Hàm Main
•	Điểm bắt đầu chương trình, gọi showStartMenu() để khởi động luồng trò chơi.
Các Nhóm Hàm
1.	Biến Toàn Cục:
o	vector<Point> snake: Lưu trữ các đoạn rắn dưới dạng danh sách các struct Point.
o	Direction direction: Hướng di chuyển hiện tại.
o	Point apple: Vị trí của táo.
o	int score: Theo dõi điểm số của người chơi.
o	int speed: Điều khiển tốc độ trò chơi (mili giây mỗi bước di chuyển).
o	Point prevTail: Lưu trữ vị trí đuôi trước đó để vẽ và phát triển rắn.
2.	Hàm Xử Lý Logic Trò Chơi:
o	drawBox(): Vẽ viền lưới trò chơi.
o	isHitWall(): Kiểm tra xem rắn có va vào tường không.
o	genApple(): Tạo vị trí ngẫu nhiên cho táo.
o	isAteApple(): Kiểm tra xem đầu rắn có ở vị trí táo không.
o	displayScore(): Hiển thị điểm số hiện tại.
o	showEndMenu(): Hiển thị menu kết thúc với tùy chọn chơi lại hoặc thoát.
o	startGame(): Vòng lặp trò chơi chính, xử lý đầu vào, di chuyển và va chạm.
o	resetSnake(): Đặt lại rắn về trạng thái ban đầu.
o	showStartMenu(): Hiển thị menu bắt đầu và xử lý lựa chọn cấp độ khó.
3.	Hàm Vẽ Rắn:
o	drawSnakePart(Point): Vẽ một đoạn rắn.
o	drawSnake(): Vẽ toàn bộ con rắn.
o	move(): Cập nhật vị trí rắn dựa trên hướng hiện tại.
o	drawHeadnTail(): Cập nhật hiển thị cho đầu và đuôi rắn.
o	isBiteItself(): Kiểm tra xem rắn có cắn vào thân mình không.
o	growing(): Thêm đoạn mới vào rắn sau khi ăn táo.
4.	Hàm Giao Diện Console:
o	gotoxy(int, int): Di chuyển con trỏ console đến vị trí xác định.
o	ShowConsoleCursor(bool): Bật/tắt hiển thị con trỏ console.
4. Tổ Chức Cấu Trúc Dữ Liệu
•	Biểu Diễn Rắn:
o	Rắn được lưu trữ dưới dạng vector<Point>, với mỗi Point đại diện cho tọa độ của một đoạn rắn.
o	Đầu rắn nằm ở chỉ số 0, đuôi ở chỉ số cuối cùng.
o	Cấu trúc này cho phép dễ dàng thêm đoạn (push_back) và di chuyển bằng cách dịch chuyển các phần tử.
•	Táo: Lưu trữ dưới dạng một struct Point, được cập nhật với tọa độ ngẫu nhiên khi bị ăn.
•	Hướng Di Chuyển: Sử dụng enum class để đảm bảo an toàn kiểu và rõ ràng.
•	Trạng Thái Trò Chơi:
o	Các biến toàn cục (score, speed, prevTail) duy trì trạng thái trò chơi.
o	Biến prevTail theo dõi vị trí đuôi trước đó để vẽ và phát triển rắn hiệu quả.
5. Giải Thuật
Di Chuyển Rắn
•	Giải Thuật:
1.	Lưu vị trí đuôi hiện tại vào prevTail.
2.	Dịch chuyển tất cả các đoạn: mỗi đoạn lấy vị trí của đoạn trước đó (snake[i] = snake[i-1]).
3.	Cập nhật vị trí đầu rắn dựa trên direction:
	Lên: Giảm y đi 1.
	Xuống: Tăng y thêm 1.
	Trái: Giảm x đi 1.
	Phải: Tăng x thêm 1.
•	Độ Phức Tạp: O(n) mỗi bước di chuyển, với n là chiều dài rắn do việc dịch chuyển các đoạn.
Phát Hiện Va Chạm
•	Va Chạm Tường (isHitWall):
o	Kiểm tra xem tọa độ đầu rắn có nằm ở biên lưới (x == 0, y == 0, x == WIDTH, y == HEIGHT).
o	Độ Phức Tạp: O(1).
•	Va Chạm Thân (isBiteItself):
o	So sánh tọa độ đầu rắn với tọa độ mỗi đoạn thân.
o	Trả về true nếu có sự trùng lặp.
o	Độ Phức Tạp: O(n), với n là chiều dài rắn.
Tạo Táo (genApple)
•	Giải Thuật:
1.	Sử dụng rand() với hạt giống time(0) để tạo x (1 đến WIDTH-1) và y (1 đến HEIGHT-1) ngẫu nhiên.
2.	Gán tọa độ vào struct apple và vẽ táo.
•	Lưu Ý: Hiện tại, giải thuật không kiểm tra xem táo có xuất hiện trên thân rắn hay không, điều này có thể được cải thiện.
•	Độ Phức Tạp: O(1).
Phát Triển Rắn (growing)
•	Giải Thuật:
o	Thêm prevTail vào vector snake khi ăn táo.
•	Độ Phức Tạp: O(1) cho thao tác push_back.
Xử Lý Đầu Vào
•	Giải Thuật:
1.	Sử dụng _kbhit() để phát hiện phím bấm.
2.	Đọc đầu vào bằng _getch(). Với phím mũi tên, phát hiện tiền tố (0xE0 hoặc -32) và đọc byte thứ hai (72 cho lên, 77 cho phải, 80 cho xuống, 75 cho trái).
3.	Cập nhật direction nếu đầu vào hợp lệ (ví dụ: không thể đi trái nếu đang đi phải).
4.	Xử lý phím 'q' để thoát trò chơi.
•	Độ Phức Tạp: O(1) mỗi lần kiểm tra đầu vào.
Vẽ Hình
•	Vẽ Lưới (drawBox):
o	Vẽ viền trên/dưới (WIDTH ký tự) và viền trái/phải (HEIGHT ký tự).
o	Độ Phức Tạp: O(WIDTH + HEIGHT).
•	Vẽ Rắn (drawSnake, drawHeadnTail):
o	drawSnake: Vẽ tất cả các đoạn (dùng khi khởi tạo).
o	drawHeadnTail: Chỉ cập nhật đầu và xóa đuôi cũ để tăng hiệu quả.
o	Độ Phức Tạp: O(n) cho drawSnake, O(1) cho drawHeadnTail.
6. Ghi Chú:
•	Phụ Thuộc Nền Tảng: Trò chơi sử dụng các thư viện Windows (<windows.h>, <conio.h>) cho việc điều khiển console và xử lý đầu vào, hạn chế khả năng chạy trên các nền tảng khác.

