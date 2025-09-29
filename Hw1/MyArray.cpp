#include "MyArray.h"
#include <stdexcept>

MyArray::MyArray() : arr(nullptr), size(0) 
{

}

MyArray::MyArray(int n) : size(n)
{
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = 0;
}
MyArray::MyArray(const MyArray& other) : size(other.size)
{
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
}
MyArray::MyArray(MyArray&& other)  : arr(other.arr), size(other.size)
{
    other.arr = nullptr;
    other.size = 0;
}
MyArray::~MyArray()
{
    delete[] arr;
}

MyArray& MyArray::operator=(const MyArray& other)
{
    if (this == &other) return *this;
    delete[] arr;
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
    return *this;
}
MyArray& MyArray::operator=(MyArray&& other) 
{
    if (this == &other) return *this;
    delete[] arr;
    arr = other.arr;
    size = other.size;
    other.arr = nullptr;
    other.size = 0;
    return *this;
}
int& MyArray::operator[](int index)
{
    static int dummy = 0;
    if (index < 0 || index >= size)
    {
        cout << "Ошибка: индекс " << index << " вне диапазона!" << endl;
        return dummy;
    }
    return arr[index];
}
const int& MyArray::operator[](int index) const
{
    static int dummy = 0;
    if (index < 0 || index >= size)
    {
        cout << "Ошибка: индекс " << index << " вне диапазона!" << endl;
        return dummy;
    }
    return arr[index];
}
MyArray MyArray::operator+(const MyArray& other) const
{
    MyArray temp(size + other.size);
    for (int i = 0; i < size; i++) temp.arr[i] = arr[i];
    for (int i = 0; i < other.size; i++) temp.arr[size + i] = other.arr[i];
    return temp;
}
MyArray& MyArray::operator++()
{
    PushBack(0);
    return *this;
}
MyArray& MyArray::operator--()
{
    PopBack();
    return *this;
}

void MyArray::PushBack(int value)
{
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++) newArr[i] = arr[i];
    newArr[size] = value;
    delete[] arr;
    arr = newArr;
    size++;
}
void MyArray::PopBack()
{
    if (size == 0) return;
    int* newArr = new int[size - 1];
    for (int i = 0; i < size - 1; i++) newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    size--;
}
void MyArray::print() const
{
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}
