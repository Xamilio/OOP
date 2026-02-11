#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class BankAccount {
private:
    std::string owner;
    double balance;
    std::mutex mtx;

public:
    BankAccount(std::string name, double startBalance)
        : owner(name), balance(startBalance) {
    }

    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        std::cout << "Пополнение: " << amount << std::endl;
    }

    void withdraw(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Снятие: " << amount << std::endl;
        }
        else {
            std::cout << "Недостаточно средств\n";
        }
    }

    void addInterest() {
        std::lock_guard<std::mutex> lock(mtx);
        balance += balance * 0.01;
    }

    void printInfo() {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Владелец: " << owner
            << " | Баланс: " << balance << std::endl;
    }
};

bool running = true;
std::mutex runMutex;

void interestWorker(BankAccount& acc) {
    while (true) {
        {
            std::lock_guard<std::mutex> lock(runMutex);
            if (!running)
                break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
        acc.addInterest();
        std::cout << "[Начислен 1%]\n";
    }
}

int main() {
    BankAccount account("Sasha", 1000);

    std::thread t(interestWorker, std::ref(account));

    int choice;
    double amount;

    while (true) {
        std::cout << "\n1-Пополнить\n2-Снять\n3-Инфо\n0-Выход\n> ";
        std::cin >> choice;

        if (choice == 0)
            break;

        switch (choice) {
        case 1:
            std::cout << "Сумма: ";
            std::cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            std::cout << "Сумма: ";
            std::cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.printInfo();
            break;
        }
    }

    {
        std::lock_guard<std::mutex> lock(runMutex);
        running = false;
    }

    t.join();

    std::cout << "Программа завершена.\n";
}