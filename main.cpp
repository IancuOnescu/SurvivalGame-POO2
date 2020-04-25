#include <iostream>
#include "include/AgentType.h"
#include "include/ItemType.h"
#include "include/PsychicAgent.h"
#include "include/HPBooster.h"
#include "include/DMGBooster.h"
#include "include/HybridBooster.h"
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    vector<AgentType*> plsWork;
    vector<ItemType*> items;

    plsWork.push_back(new PsychicAgent(make_pair(0, 0)));

    items.push_back(new HPBooster(make_pair(0, 0)));
    items.push_back(new DMGBooster(make_pair(0, 0)));
    items.push_back(new HybridBooster(make_pair(0, 0)));
    plsWork[0]->AddToInventory(items[0]);
    plsWork[0]->AddToInventory(items[1]);
    plsWork[0]->AddToInventory(items[2]);
    cout<<"dmg: "<<plsWork[0]->GetDamagePoints()<<endl;
    cout<<"hp: "<<plsWork[0]->GetHealthPoints()<<endl;
    plsWork[0]->StartOfFightModifier();
    cout<<"dmg: "<<plsWork[0]->GetDamagePoints()<<endl;
    cout<<"hp: "<<plsWork[0]->GetHealthPoints()<<endl;
    return 0;
}
