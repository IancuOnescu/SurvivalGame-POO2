#include "../include/BlockChance.h"

BlockChance::BlockChance(std::pair<int, int> pos):UniqueEffectItems(20, pos, "Deffensive", 'b'){
}

void BlockChance::TakeEffect(AgentType* agent){
    if(!TestChance()){
        SetModifAmount(0);
        return;
    }
    SetModifAmount(GetModifAmount()/2 * (-1));
    return;
}

BlockChance::~BlockChance()
{
}
