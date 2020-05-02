#include "../include/InstKillChance.h"

InstKillChance::InstKillChance(std::pair<int, int> pos):UniqueEffectItems(5, pos, "Offensive"){
}

void InstKillChance::TakeEffect(AgentType* agent){
    if(!TestChance()){
        SetModifAmount(0);
        return;
    }
    SetModifAmount(10000000);
    return;
}

InstKillChance::~InstKillChance()
{
}
