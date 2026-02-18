#include <iostream>
#include <cstddef>

class Buffer
{
private:
    char* ptr;
    std::size_t size_;

public:
    Buffer(std::size_t size)
    {
        size_ = size;
        ptr = new char[size_];
    }

    ~Buffer()
    {
        delete[] ptr;
    }

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    Buffer(Buffer&& other)
    {
        ptr = other.ptr;
        size_ = other.size_;

        other.ptr = nullptr;
        other.size_ = 0;
    }

    Buffer& operator=(Buffer&& other)
    {
        if (this != &other)
        {
            delete[] ptr;

            ptr = other.ptr;
            size_ = other.size_;

            other.ptr = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    char* data()
    {
        return ptr;
    }

    std::size_t size() const
    {
        return size_;
    }

    char* release()
    {
        char* temp = ptr;
        ptr = nullptr;
        size_ = 0;
        return temp;
    }
};

int main()
{
    Buffer buf(5);

    buf.data()[0] = 'H';
    buf.data()[1] = 'e';
    buf.data()[2] = 'l';
    buf.data()[3] = 'l';
    buf.data()[4] = 'o';

    for (std::size_t i = 0; i < buf.size(); i++)
    {
        std::cout << buf.data()[i];
    }

    std::cout << std::endl;
}
