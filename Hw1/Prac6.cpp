#include <iostream>
#include <cstring>

class Buffer {
private:
    char* data_;
    size_t size_;

public:
    explicit Buffer(size_t size)
        : data_(new char[size]), size_(size) {}

    ~Buffer() {
        delete[] data_;
    }

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    Buffer(Buffer&& other) noexcept
        : data_(other.data_), size_(other.size_) {
        other.data_ = nullptr;
        other.size_ = 0;
    }

    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;

            data_ = other.data_;
            size_ = other.size_;

            other.data_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    char* data() {
        return data_;
    }

    const char* data() const {
        return data_;
    }

    size_t size() const {
        return size_;
    }

    char* release() {
        char* temp = data_;
        data_ = nullptr;
        size_ = 0;
        return temp;
    }
};

int main() {
    Buffer buf(50);

    std::strcpy(buf.data(), "RAII Buffer example");
    std::cout << "Data: " << buf.data() << std::endl;
    std::cout << "Size: " << buf.size() << std::endl;

    Buffer buf2 = std::move(buf);

    std::cout << "After move: " << buf2.data() << std::endl;

    return 0;
}
