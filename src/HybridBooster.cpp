#include "../include/HybridBooster.h"

HybridBooster::HybridBooster(std::pair<int, int> pos):ItemType(pos, "Immediate"){
}

void HybridBooster::TakeEffect(AgentType* agent){
    agent->SetDamagePoints(agent->GetDamagePoints() + GetModifAmount());
    agent->SetHealthPoints(agent->GetHealthPoints() + GetModifAmount());
    return;
}

HybridBooster::~HybridBooster()
{
    //dtor
}
