#pragma once
#include "Worker.h"

class Queue {
    Worker* arr;
    int maxCount;
    int count;
public:
    Queue(int max);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void Add(const Worker& obj);
    Worker Extract();
    void Clear();
    void ShowAll() const;
    int GetCount() const;
};
