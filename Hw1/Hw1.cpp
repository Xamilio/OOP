#include <iostream>
#include <string>

using namespace std;

class Component {
public:
    virtual int getPrice() = 0;
    virtual void add(Component* c) {}
    virtual void print(string indent = "") = 0;
    virtual ~Component() {}
};

class Item : public Component {
    string name;
    int price;
public:
    Item(string n, int p) {
        name = n;
        price = p;
    }

    int getPrice() override {
        return price;
    }

    void print(string indent = "") override {
        cout << indent << name << " : " << price << endl;
    }
};

class Composite : public Component {
    string name;
    Component* children[100];
    int count;
public:
    Composite(string n) {
        name = n;
        count = 0;
    }

    void add(Component* c) override {
        children[count++] = c;
    }

    int getPrice() override {
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += children[i]->getPrice();
        }
        return sum;
    }

    void print(string indent = "") override {
        cout << indent << name << endl;
        for (int i = 0; i < count; i++) {
            children[i]->print(indent + "  ");
        }
    }
};

int main() {
    Composite* office = new Composite("Офис");

    Composite* reception = new Composite("Приемная");
    reception->add(new Item("Журнальный столик", 200));
    reception->add(new Item("Мягкий диван", 500));
    reception->add(new Item("Стол секретаря", 300));
    reception->add(new Item("Кулер", 150));

    Composite* room1 = new Composite("Аудитория 1");
    room1->add(new Item("10 столов", 1000));
    room1->add(new Item("Доска", 200));
    room1->add(new Item("Стол учителя", 300));

    Composite* computerRoom = new Composite("Компьютерная аудитория");
    Composite* tables = new Composite("10 компьютерных столов");

    for (int i = 0; i < 10; i++) {
        Composite* table = new Composite("Стол с компьютером");
        table->add(new Item("Компьютер", 800));
        tables->add(table);
    }

    computerRoom->add(tables);
    computerRoom->add(new Item("Доска", 200));

    office->add(reception);
    office->add(room1);
    office->add(computerRoom);

    office->print();

    cout << "\nОбщая стоимость: " << office->getPrice() << endl;

    return 0;
}
