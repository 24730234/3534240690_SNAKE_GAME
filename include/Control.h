#ifndef CONTROL_H
#define CONTROL_H

// Enum để định nghĩa hướng di chuyển của rắn
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Control {
    private:
        Direction currentDir; // Hướng hiện tại của rắn
        
    public:
        Control();

        // Lấy hướng hiện tại
        Direction getDirection() const;

        // Cập nhật hướng dựa trên phím bấm
        void updateDirection(char key);

        // Kiểm tra có thay đổi hướng hợp lệ hay không
        bool isOpposite(Direction newDir) const;
};

#endif