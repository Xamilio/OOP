#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>

int* data = nullptr;
int size = 0;
int currentIndex = 0;
bool finished = false;

std::mutex mtx;
std::condition_variable cv;

void producer()
{
    std::ifstream file("input.txt");

    if (!file.is_open())
    {
        std::cout << "Ошибка открытия файла\n";
        return;
    }

    int value;
    int index = 0;

    while (file >> value)
    {
        {
            std::unique_lock<std::mutex> lock(mtx);
            data[index++] = value;
            currentIndex++;
        }

        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    {
        std::unique_lock<std::mutex> lock(mtx);
        finished = true;
    }

    cv.notify_all();
}

void consumer()
{
    int processedIndex = 0;

    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] {
            return currentIndex > 0 || finished;
        });

        while (processedIndex < currentIndex)
        {
            int value = data[processedIndex++];
            lock.unlock();
            std::cout << value * value << std::endl;
            lock.lock();
        }

        if (finished && processedIndex >= currentIndex)
        {
            break;
        }
    }
}

int main()
{
    std::ifstream file("input.txt");
    int temp;

    while (file >> temp)
    {
        size++;
    }
    file.close();

    if (size == 0)
    {
        std::cout << "Файл пустой\n";
        return 0;
    }

    data = new int[size];

    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    delete[] data;

    return 0;
}
