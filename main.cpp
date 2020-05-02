#include <iostream>
#include "include/GameManager.h"

using namespace std;

int main()
{
    GameManager game(15);
    game.CreateItems(2);
    game.CreateAgents(2);
    return 0;
}
