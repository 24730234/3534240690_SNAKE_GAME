Mô tả & Hướng dẫn chơi Game Rắn Săn Mồi (C++ Console)
Đây là tài liệu mô tả chi tiết về game Rắn Săn Mồi được phát triển trên môi trường console C++, cùng với hướng dẫn cách chơi để bạn có thể bắt đầu ngay lập tức.

1. Mô tả chi tiết về Game 🐍🍎
Game Rắn Săn Mồi phiên bản console C++ là một trò chơi cổ điển, nơi người chơi điều khiển một con rắn di chuyển trên một khu vực giới hạn để ăn mồi. Mục tiêu chính là làm cho con rắn dài ra càng nhiều càng tốt bằng cách ăn các quả táo xuất hiện ngẫu nhiên, đồng thời tránh va chạm với tường hoặc chính thân rắn.

Đồ họa: Game sử dụng các ký tự ASCII (=, |, *, O) để tạo hình ảnh và khung cảnh trên màn hình console đen trắng.

Khung game được tạo bởi các ký tự = (trên/dưới) và | (trái/phải).

Con rắn được biểu diễn bằng các ký tự *.

Quả táo (mồi) được biểu diễn bằng ký tự O.

Cơ chế chơi:

Di chuyển: Rắn di chuyển liên tục theo một hướng nhất định. Người chơi có thể thay đổi hướng di chuyển của rắn.

Ăn mồi: Khi đầu rắn chạm vào vị trí của quả táo, rắn sẽ "ăn" táo. Quả táo biến mất, một quả táo mới xuất hiện ở vị trí ngẫu nhiên khác, và con rắn sẽ dài thêm một đoạn.

Điểm số: Mỗi khi rắn ăn một quả táo, điểm số của người chơi sẽ tăng lên.

Tốc độ: Tốc độ di chuyển của rắn sẽ tăng dần theo điểm số hoặc theo cấp độ chơi mà bạn chọn, làm tăng độ khó của game.

Điều kiện kết thúc Game: Game sẽ kết thúc khi:

Rắn va chạm vào bất kỳ phần nào của tường bao quanh khu vực chơi.

Rắn va chạm vào chính thân nó (tự cắn).

Menu: Game có các màn hình menu đơn giản để bắt đầu game, chọn độ khó và hiển thị kết quả khi game kết thúc.

2. Hướng dẫn cách chơi 🎮
Để chơi game, bạn cần chạy file thực thi (.exe) của game trong môi trường console Windows.

2.1. Bắt đầu Game
Mở file ran_san_moi.exe (hoặc tên file thực thi tương tự) trong Command Prompt hoặc PowerShell.

Màn hình Start Menu sẽ xuất hiện:

===== Ran San Moi====!
Tuy chinh:
1. Bat Dau
2. Ket thuc
Lua chon cua ban: _

Nhập 1 và nhấn Enter để bắt đầu chơi.

Bạn sẽ được yêu cầu chọn cấp độ chơi (1 - 5):

Nhập một số từ 1 đến 5 và nhấn Enter.

Cấp độ càng cao, rắn sẽ di chuyển càng nhanh, game càng khó.

Game sẽ đếm ngược 3, 2, 1, Choi! trước khi bắt đầu.

2.2. Điều khiển Rắn
Trong khi chơi game, bạn sẽ sử dụng các phím mũi tên trên bàn phím để điều khiển hướng di chuyển của rắn:

Mũi tên Lên (↑): Rắn di chuyển lên trên.

Mũi tên Xuống (↓): Rắn di chuyển xuống dưới.

Mũi tên Trái (←): Rắn di chuyển sang trái.

Mũi tên Phải (→): Rắn di chuyển sang phải.

Lưu ý quan trọng: Bạn không thể điều khiển rắn quay ngược 180 độ ngay lập tức (ví dụ: đang đi lên thì không thể nhấn mũi tên xuống ngay lập tức).

2.3. Mục tiêu và Điểm số
Mục tiêu: Điều khiển rắn ăn các quả táo (O) xuất hiện trên màn hình.

Điểm số: Mỗi khi ăn một quả táo, điểm số của bạn sẽ tăng lên và hiển thị ở góc màn hình.

Tăng độ dài: Rắn sẽ dài thêm một đoạn sau mỗi lần ăn táo.

2.4. Kết thúc Game
Game sẽ kết thúc khi rắn va chạm vào tường hoặc tự cắn vào thân mình. Màn hình End Menu sẽ xuất hiện:

Ket thuc tro choi!
Diem cua ban: [Điểm số của bạn]
Ban co muon choi nua khong ([y]/[n]): _

Nhập y và nhấn Enter để chơi lại từ đầu.

Nhập n và nhấn Enter để thoát game.

2.5. Thoát Game nhanh
Trong khi đang chơi game, bạn có thể nhấn phím q để thoát game ngay lập tức và chuyển đến màn hình kết thúc.

Chúc bạn có những giây phút vui vẻ với game Rắn Săn Mồi!