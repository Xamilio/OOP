#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

    void ensureCapacity(int newSize) {
        if (newSize <= capacity)
            return;

        int newCapacity = capacity;
        while (newCapacity < newSize) {
            newCapacity += grow;
        }

        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Array(int initialSize = 0, int growBy = 1)
        : size(initialSize), capacity(initialSize), grow(growBy) {
        data = (capacity > 0) ? new T[capacity] : nullptr;
    }

    ~Array() {
        delete[] data;
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize, int growBy = 1) {
        grow = growBy;
        if (newSize > capacity) {
            ensureCapacity(newSize);
        }
        size = newSize;
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        if (size < capacity) {
            T* newData = new T[size];
            for (int i = 0; i < size; ++i)
                newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = size;
        }
    }

    void RemoveAll() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    T GetAt(int index) const {
        return data[index];
    }

    void SetAt(int index, const T& value) {
        data[index] = value;
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    void Add(const T& value) {
        ensureCapacity(size + 1);
        data[size++] = value;
    }

    void Append(const Array<T>& other) {
        ensureCapacity(size + other.size);
        for (int i = 0; i < other.size; ++i)
            data[size++] = other.data[i];
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            grow = other.grow;
            data = new T[capacity];
            for (int i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    T* GetData() {
        return data;
    }

    const T* GetData() const {
        return data;
    }

    void InsertAt(int index, const T& value) {
        ensureCapacity(size + 1);
        for (int i = size; i > index; --i)
            data[i] = data[i - 1];
        data[index] = value;
        ++size;
    }

    void RemoveAt(int index) {
        for (int i = index; i < size - 1; ++i)
            data[i] = data[i + 1];
        --size;
    }
};

int main() {
    Array<int> a(3, 2);
    a.SetAt(0, 1);
    a.SetAt(1, 2);
    a.SetAt(2, 3);
    a.Add(4);
    a.InsertAt(1, 10);
    a.RemoveAt(2);
    for (int i = 0; i < a.GetSize(); ++i)
        cout << a[i] << " ";
}
