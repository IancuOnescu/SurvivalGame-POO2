#include "../include/CriticalChance.h"

CriticalChance::CriticalChance(std::pair<int, int> pos):UniqueEffectItems(10, pos, "Offensive"){
}

void CriticalChance::TakeEffect(AgentType* agent){
    if(!TestChance()){
        SetModifAmount(0);
        return;
    }
    SetModifAmount(GetModifAmount());
    return;
}

CriticalChance::~CriticalChance()
{
}
