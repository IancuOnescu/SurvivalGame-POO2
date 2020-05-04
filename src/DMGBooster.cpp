#include "../include/DMGBooster.h"

DMGBooster::DMGBooster(std::pair<int, int> pos):ItemType(pos, "Immediate", 'd'){
}

void DMGBooster::TakeEffect(AgentType* agent){
    agent->SetDamagePoints(agent->GetDamagePoints() + GetModifAmount());
    return;
}

DMGBooster::~DMGBooster()
{
}
