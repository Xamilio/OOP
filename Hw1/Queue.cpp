#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int max) {
    maxCount = max;
    arr = new Worker[maxCount];
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

bool Queue::isEmpty() const {
    return count == 0;
}

bool Queue::isFull() const {
    return count == maxCount;
}

void Queue::Add(const Worker& obj) {
    if (!isFull()) {
        arr[count++] = obj;
    }
    else {
        cout << "Очередь переполнена!" << endl;
    }
}

Worker Queue::Extract() {
    if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return Worker();
    }
    Worker first = arr[0];
    for (int i = 1; i < count; i++) {
        arr[i - 1] = arr[i];
    }
    count--;
    return first;
}

void Queue::Clear() {
    count = 0;
}

void Queue::ShowAll() const {
    for (int i = 0; i < count; i++) {
        arr[i].PrintInfo();
    }
}

int Queue::GetCount() const {
    return count;
}
