#include "../include/MarauderAgent.h"

MarauderAgent::MarauderAgent(std::pair<int, int> pos):AgentType(80, 410, std::make_pair(2, 2), pos), damageTaken_(0){
}

void MarauderAgent::TakeDamage(float damageTaken){
    AgentType::TakeDamage(damageTaken);
    damageTaken_ += damageTaken;
}


void MarauderAgent::ChangeMovementPattern(){
    std::pair<int, int> movementPattern_ = GetMovementPattern();
    std::pair<int, int> position_ = GetPosition();
    int sizeOfMap = 10;
    if(movementPattern_.first + position_.first >= sizeOfMap)
        movementPattern_.first = -1;
    if(movementPattern_.first + position_.first < 0)
        movementPattern_.first = 2;
    if(movementPattern_.second + position_.second >= sizeOfMap)
        movementPattern_.second = -2;
    if(movementPattern_.second + position_.second < 0)
        movementPattern_.second = 1;
    SetMovementPattern(movementPattern_);
}

void MarauderAgent::StartOfFightModifier(){
    AgentType::StartOfFightModifier();
    damageTaken_ = 0;
    return;
}

void MarauderAgent::MidFightModifier(){
    while(damageTaken_-90 >= 0){
        damageTaken_ -= 90;
        SetDamagePoints(GetDamagePoints()*1.3);
    }
    return;
}

void MarauderAgent::EndOfFightModifier(){
    AgentType::EndOfFightModifier();
    AgentType::EndOfFightModifier();
    return;
}

MarauderAgent::~MarauderAgent()
{
    damageTaken_ = 0;
}
