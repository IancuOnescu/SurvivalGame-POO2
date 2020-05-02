#include "../include/MageAgent.h"

MageAgent::MageAgent(std::pair<int, int> pos):AgentType(90, 340, std::make_pair(1, 3), pos), enemyDMG_(0){
}

void MageAgent::DealDamage(AgentType* enemyAgent){
    enemyDMG_ = enemyAgent->GetDamagePoints();
    SetDamagePoints(GetDamagePoints() + (enemyDMG_ * 0.1));
    AgentType::DealDamage(enemyAgent);
    SetDamagePoints(GetDamagePoints() - (enemyDMG_ * 0.1));
}

void MageAgent::ChangeMovementPattern(){
    std::pair<int, int> movementPattern_ = GetMovementPattern();
    std::pair<int, int> position_ = GetPosition();
    int sizeOfMap = 10;
    if(movementPattern_.first + position_.first >= sizeOfMap)
        movementPattern_.first = -2;
    if(movementPattern_.first + position_.first < 0)
        movementPattern_.first = 2;
    if(movementPattern_.second + position_.second >= sizeOfMap )
        movementPattern_.second = -1;
    if(movementPattern_.second + position_.second < 0)
        movementPattern_.second = 1;
    SetMovementPattern(movementPattern_);
}

void MageAgent::MidFightModifier(){
    if(rand()%100 <= 20)
        SetDamagePoints(enemyDMG_*0.05 + GetDamagePoints());
}

void MageAgent::StartOfFightModifier(){
    AgentType::StartOfFightModifier();
    enemyDMG_ = 0;
    return;
}

void MageAgent::EndOfFightModifier(){
    AgentType::EndOfFightModifier();
    if(enemyDMG_ > GetDamagePoints())
        SetDamagePoints(enemyDMG_);
    enemyDMG_ = 0;
}

MageAgent::~MageAgent()
{
}
