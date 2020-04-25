#include "../include/HPBooster.h"

HPBooster::HPBooster(std::pair<int, int> pos):ItemType(pos, "Immediate"){
}

void HPBooster::TakeEffect(AgentType* agent){
    agent->SetHealthPoints(agent->GetHealthPoints() + GetModifAmount());
    return;
}

HPBooster::~HPBooster()
{
}
