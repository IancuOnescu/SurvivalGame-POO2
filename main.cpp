#include <iostream>
#include "include/GameManager.h"
#include "conio.h"

using namespace std;

int main()
{
    system("color 0A");
    int mapsize, nrAgents, nrItems, nrOfRounds;
    cout << "Welcome to our Survival Game Simlator\n";
    cout << "We hope you will enjoy your stay here\n";
    cout << "We will need some data before we begin\n";
    cout << "Please provides us the map size you wish: ";
    cin >> mapsize;
    while(mapsize < 3){
        cout << "A little big bigger please(>=3): ";
        cin >> mapsize;
    }
    GameManager game(mapsize);
    cout << "Now provide us with the number of items\n";
    cout << "You want us to randomly spread over the map(1-" << mapsize*mapsize-1 <<"): ";
    cin >> nrItems;
    while(nrItems < 1 || nrItems > mapsize*mapsize-1){
        cout << "Not quite in the range. Try again: ";
        cin >> nrItems;
    }
    game.CreateItems(nrItems);
    cout << "Now provide us with the number of agents\n";
    cout << "You want us to randomly spread over the map(1-" << mapsize*mapsize-nrItems <<"): ";
    cin >> nrAgents;
    while(nrAgents < 1 || nrAgents > mapsize*mapsize-nrItems){
        cout << "Not quite in the range. Try again: ";
        cin >> nrAgents;
    }
    game.CreateAgents(nrAgents);
    cout << "How many rounds do you wish to simulate?\n";
    cin >> nrOfRounds;
    while(nrOfRounds){
        game.RunGame(nrOfRounds);
        cout << "Do you wish to keep going?\n";
        cout << "Type 0 to quit or a number greater to keep going: ";
        cin>>nrOfRounds;
    }
    cout << "Thank you very much for your patience. Much Love!\n";
    cout << "Hope to see you again!";
    return 0;
}
