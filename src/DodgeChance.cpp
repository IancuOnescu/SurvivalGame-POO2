#include "../include/DodgeChance.h"

DodgeChance::DodgeChance(std::pair<int, int> pos):UniqueEffectItems(20, pos, "Deffensive"){
}

void DodgeChance::TakeEffect(AgentType* agent){
    if(!TestChance()){
        SetModifAmount(0);
        return;
    }
    SetModifAmount(GetModifAmount() * (-1));
    return;
}

DodgeChance::~DodgeChance()
{
}
