#include <iostream>
using namespace std;

class PlayerMemento {
private:
    int health;
    int energy;
    int gold;
    int x, y;

public:
    PlayerMemento(int h, int e, int g, int xPos, int yPos)
        : health(h), energy(e), gold(g), x(xPos), y(yPos) {}

    int getHealth() { return health; }
    int getEnergy() { return energy; }
    int getGold() { return gold; }
    int getX() { return x; }
    int getY() { return y; }
};

class Player {
private:
    int health;
    int energy;
    int gold;
    int x, y;

public:
    Player(int h, int e, int g, int xPos, int yPos)
        : health(h), energy(e), gold(g), x(xPos), y(yPos) {}

    void makeMove() {
        energy -= 10;
        gold += 5;
        x += 1;
        y += 2;
        if (energy < 0) energy = 0;
    }

    PlayerMemento save() {
        return PlayerMemento(health, energy, gold, x, y);
    }

    void restore(PlayerMemento m) {
        health = m.getHealth();
        energy = m.getEnergy();
        gold = m.getGold();
        x = m.getX();
        y = m.getY();
    }

    void showState() {
        cout << "HP: " << health
             << " | Energy: " << energy
             << " | Gold: " << gold
             << " | Position: (" << x << ", " << y << ")\n";
    }
};

class SaveSlots {
private:
    PlayerMemento* slots[3];

public:
    SaveSlots() {
        for (int i = 0; i < 3; i++)
            slots[i] = nullptr;
    }

    void saveToSlot(int slot, PlayerMemento m) {
        if (slot < 1 || slot > 3) return;
        if (slots[slot - 1] != nullptr)
            delete slots[slot - 1];
        slots[slot - 1] = new PlayerMemento(m);
    }

    PlayerMemento loadFromSlot(int slot) {
        return *slots[slot - 1];
    }

    ~SaveSlots() {
        for (int i = 0; i < 3; i++)
            if (slots[i] != nullptr)
                delete slots[i];
    }
};

int main() {
    Player player(100, 100, 50, 0, 0);
    SaveSlots saves;

    player.showState();

    player.makeMove();
    player.showState();

    saves.saveToSlot(1, player.save());

    player.makeMove();
    player.makeMove();
    player.showState();

    player.restore(saves.loadFromSlot(1));
    player.showState();

    return 0;
}
