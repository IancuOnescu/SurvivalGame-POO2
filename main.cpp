#include <iostream>
#include "include/AgentType.h"
#include "include/ItemType.h"
#include "include/PsychicAgent.h"
#include "include/MageAgent.h"
#include "include/MarauderAgent.h"
#include "include/AssassinAgent.h"
#include "include/HPBooster.h"
#include "include/DMGBooster.h"
#include "include/HybridBooster.h"
#include "include/CriticalChance.h"
#include "include/DodgeChance.h"
#include "include/InstKillChance.h"
#include "include/BlockChance.h"
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    vector<AgentType*> plsWork;
    vector<ItemType*> items;

    plsWork.push_back(new PsychicAgent(make_pair(0, 0)));
    plsWork.push_back(new MageAgent(make_pair(0, 0)));
    plsWork.push_back(new MarauderAgent(make_pair(0, 0)));
    plsWork.push_back(new AssassinAgent(make_pair(0, 0)));

    items.push_back(new HPBooster(make_pair(0, 0)));
    items.push_back(new DMGBooster(make_pair(0, 0)));
    items.push_back(new HybridBooster(make_pair(0, 0)));
    items.push_back(new CriticalChance(make_pair(0, 0)));
    items.push_back(new DodgeChance(make_pair(0, 0)));
    items.push_back(new InstKillChance(make_pair(0, 0)));
    items.push_back(new BlockChance(make_pair(0, 0)));

    cout<<"dmg: "<<plsWork[0]->GetDamagePoints()<<endl;
    cout<<"hp: "<<plsWork[0]->GetHealthPoints()<<endl;
    cout<<"dmg: "<<plsWork[3]->GetDamagePoints()<<endl;
    cout<<"hp: "<<plsWork[3]->GetHealthPoints()<<endl;
    cout<<"--------------------------------------------"<<endl;

   plsWork[3]->DealDamage(plsWork[0]);
   plsWork[3]->MidFightModifier();
   plsWork[3]->EndOfFightModifier();

    cout<<"dmg: "<<plsWork[0]->GetDamagePoints()<<endl;
    cout<<"hp: "<<plsWork[0]->GetHealthPoints()<<endl;
    cout<<"dmg: "<<plsWork[3]->GetDamagePoints()<<endl;
    cout<<"hp: "<<plsWork[3]->GetHealthPoints()<<endl;
    cout<<"--------------------------------------------"<<endl;
    return 0;
}
