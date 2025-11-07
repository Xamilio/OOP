#include "Game.h"
using namespace std;

void Game::drawBase() {
    system("cls");

    cout << "+------------------------+\n";
    cout << "|        BASE            |\n";
    cout << "+------------------------+\n";
    cout << "| People:   " << Base::people_on_base << "\n";
    cout << "| Vehicles: " << Base::vehicles_on_base << "\n";
    cout << "| Petrol:   " << Base::petrol_on_base << " L\n";
    cout << "| Goods:    " << Base::goods_on_base << " tons\n";
    cout << "+------------------------+\n";
}

void Game::showMenu() {
    while (true) {
        drawBase();
        cout << "\n===== MENU =====\n";
        cout << "1. Bus Arrive\n";
        cout << "2. Truck Arrive\n";
        cout << "3. Bus Leave\n";
        cout << "4. Truck Leave\n";
        cout << "5. Exit\n";
        cout << "================\n";
        cout << "Choose an option: ";
        string choice;
        cin >> choice;
        if (choice == "1") {
            busArrive();
        }
        else if (choice == "2") {
            truckArrive();
        }
        else if (choice == "3") {
            busLeave();
        }
        else if (choice == "4") {
            truckLeave();
        }
        else if (choice == "5") {
            cout << "Exiting game...\n";
            return;
        }
        else {
            cout << "Invalid choice! Please enter a valid option (1-5)\n";
            waitForEnter();
        }
    }
}

void Game::busArrive() {
    cout << "Bus arriving...\n";
    bus.arrive();
    waitForEnter();
}

void Game::truckArrive() {
    cout << "Truck arriving...\n";
    truck.arrive();
    waitForEnter();
}

void Game::busLeave() {
    cout << "Bus leaving...\n";
    if (!bus.leave()) {
        cout << "Bus failed to leave.\n";
    }
    waitForEnter();
}

void Game::truckLeave() {
    cout << "Truck leaving...\n";
    if (!truck.leave()) {
        cout << "Truck failed to leave.\n";
    }
    waitForEnter();
}

void Game::waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(); 
    cin.get(); 
}


