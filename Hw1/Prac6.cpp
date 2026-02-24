#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <fstream>
#include <chrono>

using namespace std;

class Car {
private:
    string name;
    string number;

public:
    Car(string n, string num) : name(n), number(num) {}

    void park(counting_semaphore<3>& parking) {
        cout << "Машина " << name << " (" << number << ") подъехала к парковке\n";
        parking.acquire();
        cout << "Машина " << name << " припарковалась\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Машина " << name << " уехала\n";
        parking.release();
    }
};

mutex fileMutex;

void writeToFile(int id, counting_semaphore<2>& fileSemaphore) {
    cout << "Поток " << id << " начал работу\n";
    fileSemaphore.acquire();

    {
        lock_guard<mutex> lock(fileMutex);
        ofstream file("log.txt", ios::app);
        file << "Поток " << id << " записал данные\n";
        file.close();
    }

    cout << "Поток " << id << " закончил запись\n";
    fileSemaphore.release();
}

int data[20] = {0};
mutex arrayMutex;

void fillArray(int id, counting_semaphore<2>& arraySemaphore) {
    while (true) {
        arraySemaphore.acquire();

        int index = -1;

        {
            lock_guard<mutex> lock(arrayMutex);
            for (int i = 0; i < 20; i++) {
                if (data[i] == 0) {
                    data[i] = id;
                    index = i;
                    break;
                }
            }
        }

        arraySemaphore.release();

        if (index == -1)
            break;

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {

    cout << "\n========== ЗАДАНИЕ 1 ==========\n";

    counting_semaphore<3> parking(3);
    thread cars[6];

    for (int i = 0; i < 6; i++) {
        Car car("Car" + to_string(i + 1), "AA00" + to_string(i + 1));
        cars[i] = thread(&Car::park, car, ref(parking));
    }

    for (int i = 0; i < 6; i++)
        cars[i].join();


    cout << "\n========== ЗАДАНИЕ 2 ==========\n";

    counting_semaphore<2> fileSemaphore(2);
    thread writers[6];

    for (int i = 0; i < 6; i++)
        writers[i] = thread(writeToFile, i + 1, ref(fileSemaphore));

    for (int i = 0; i < 6; i++)
        writers[i].join();


    cout << "\n========== ЗАДАНИЕ 3 ==========\n";

    counting_semaphore<2> arraySemaphore(2);
    thread workers[5];

    for (int i = 0; i < 5; i++)
        workers[i] = thread(fillArray, i + 1, ref(arraySemaphore));

    for (int i = 0; i < 5; i++)
        workers[i].join();

    cout << "\nМассив:\n";
    for (int i = 0; i < 20; i++)
        cout << data[i] << " ";

    cout << endl;

    return 0;
}
