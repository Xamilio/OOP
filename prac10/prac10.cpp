#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

//mutex mtx;
//
//void writeToFile(int id) {
//    for (int i = 0; i < 5; i++) {
//        mtx.lock();
//        ofstream file("data.txt", ios::app);
//        file << "Поток " << id << " запись " << i + 1 << endl;
//        file.close();
//        mtx.unlock();
//    }
//}
//
//void readFile() {
//    ifstream file("data.txt");
//    string line;
//    while (getline(file, line)) {
//        cout << line << endl;
//    }
//    file.close();
//}
//
//int main() {
//    ofstream clear("data.txt");
//    clear.close();
//
//    thread t1(writeToFile, 1);
//    thread t2(writeToFile, 2);
//    thread t3(writeToFile, 3);
//
//    t1.join();
//    t2.join();
//    t3.join();
//
//    thread reader(readFile);
//    reader.join();
//
//}

class FileWriter {
    string filename;
    mutex mtx;

public:
    FileWriter(const string& name) : filename(name) {}

    void appendLine(const string& text) {
        lock_guard<mutex> lock(mtx);
        ofstream file(filename, ios::app);
        file << text << endl;
        file.close();
    }

    void appendLineUnsafe(const string& text) {
        ofstream file(filename, ios::app);
        file << text << endl;
        file.close();
    }
};

void writer(FileWriter& fw, int id) {
    for (int i = 0; i < 5; i++) {
        fw.appendLine("Поток " + to_string(id) + " запись " + to_string(i + 1));
    }
}

void readFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    ofstream clear("result.txt");
    clear.close();

    FileWriter fw("result.txt");

    thread t1(writer, ref(fw), 1);
    thread t2(writer, ref(fw), 2);
    thread t3(writer, ref(fw), 3);

    t1.join();
    t2.join();
    t3.join();

    cout << "Готово" << endl;

    thread reader(readFile, "result.txt");
    reader.join();

}

