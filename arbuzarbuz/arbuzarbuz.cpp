#include "Game.h"
#include <ctime> 

using namespace std;

int main() {
    system("color 3");
    srand(static_cast<unsigned int>(time(nullptr)));

    Base::people_on_base = rand() % 100;   
    Base::vehicles_on_base = rand() % 50; 
    Base::petrol_on_base = rand() % 1000;  
    Base::goods_on_base = rand() % 200;   

    Game game; 
    game.showMenu(); 

    return 0; 
}
