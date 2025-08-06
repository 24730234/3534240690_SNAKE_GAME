Cách Commit lên GitHub để Tránh Xung đột
Xung đột (conflict) xảy ra khi hai hoặc nhiều người cùng chỉnh sửa cùng một dòng code trong cùng một file. Dưới đây là các thực hành tốt để giảm thiểu và xử lý xung đột.

1. Kéo (Pull) thường xuyên:

Trước khi bắt đầu làm việc: Luôn git pull từ nhánh chính (thường là main hoặc develop) để đảm bảo bạn có phiên bản code mới nhất.

Trước khi commit: Kéo code một lần nữa trước khi git push để tích hợp các thay đổi mới nhất từ kho chứa từ xa. Điều này giúp bạn giải quyết xung đột cục bộ trước khi đẩy lên.

Lệnh: git pull origin <tên_nhánh_hiện_tại>

2. Tạo nhánh (Branch) cho mỗi tính năng/sửa lỗi:

Lý do: Mỗi tính năng hoặc sửa lỗi nên được phát triển trên một nhánh riêng biệt. Điều này cô lập các thay đổi của bạn khỏi nhánh chính và các thay đổi của người khác.

Lệnh: git checkout -b <tên_nhánh_mới> (tạo và chuyển sang nhánh mới)

3. Commit nhỏ, thường xuyên và có ý nghĩa:

Commit nhỏ: Thay vì commit một lượng lớn thay đổi cùng lúc, hãy chia nhỏ công việc thành các commit logic. Mỗi commit nên giải quyết một vấn đề cụ thể hoặc thêm một phần nhỏ của tính năng.

Commit thường xuyên: Commit code của bạn thường xuyên vào nhánh cục bộ. Điều này tạo ra các điểm khôi phục và giúp dễ dàng theo dõi tiến độ.

Thông điệp commit rõ ràng: Viết thông điệp commit mô tả ngắn gọn và chính xác những gì đã thay đổi và tại sao.

Ví dụ tốt: feat: Add user authentication endpoint, fix: Resolve bug in login form validation, refactor: Improve database connection handling.

Tránh: update, fix bug, changes.

4. Giải quyết xung đột ngay lập tức:

Nếu Git báo cáo xung đột khi bạn pull hoặc merge một nhánh khác, hãy giải quyết chúng ngay lập tức.

Các bước cơ bản:

Git sẽ đánh dấu các dòng bị xung đột trong file bằng các ký hiệu <<<<<<<, =======, >>>>>>>.

Bạn cần chỉnh sửa thủ công file đó để chọn phiên bản code mong muốn (của bạn, của người khác, hoặc kết hợp cả hai).

Sau khi giải quyết, git add <tên_file> để đánh dấu file đã được giải quyết.

git commit để hoàn tất quá trình merge.

5. Sử dụng .gitignore:

Thêm các file không cần thiết vào kho chứa Git (như file biên dịch, file cấu hình cục bộ, thư mục node_modules, v.v.) vào file .gitignore.

Lý do: Điều này giúp tránh các commit không cần thiết và giảm khả năng xung đột trên các file mà không ai nên theo dõi.

6. Thảo luận và phối hợp với nhóm:

Giao tiếp là chìa khóa: Nếu bạn biết có người khác đang làm việc trên cùng một phần code, hãy trao đổi với họ để phối hợp các thay đổi.

Quy trình làm việc: Tuân thủ quy trình làm việc Git của nhóm (ví dụ: Git Flow, GitHub Flow).

Bằng cách áp dụng những quy tắc này, bạn sẽ giảm thiểu đáng kể khả năng xảy ra xung đột và làm cho quá trình phát triển dự án trở nên mượt mà hơn.