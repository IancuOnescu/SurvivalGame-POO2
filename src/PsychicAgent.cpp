#include "../include/PsychicAgent.h"

PsychicAgent::PsychicAgent(std::pair<int, int> pos):AgentType(100, 300, std::make_pair(1, 1), pos, 'P'), numberOfHits_(0){
}

void PsychicAgent::DealDamage(AgentType* enemyAgent){
    AgentType::DealDamage(enemyAgent);
    ++numberOfHits_;
    return;
}

void PsychicAgent::ChangeMovementPattern(int sizeOfMap){
    std::pair<int, int> movementPattern_ = GetMovementPattern();
    std::pair<int, int> position_ = GetPosition();
    if(movementPattern_.first + position_.first >= sizeOfMap ||
       movementPattern_.first + position_.first < 0)
            movementPattern_.first *= (-1);
    if(movementPattern_.second + position_.second >= sizeOfMap ||
       movementPattern_.second + position_.second < 0)
            movementPattern_.second *= (-1);
    SetMovementPattern(movementPattern_);
    return;
}

void PsychicAgent::StartOfFightModifier(){
    AgentType::StartOfFightModifier();
    numberOfHits_ = 0;
    return;
}

void PsychicAgent::MidFightModifier(){
    if(numberOfHits_ % 3 == 0)
        SetDamagePoints(GetDamagePoints()*1.05);
    return;
}

void PsychicAgent::EndOfFightModifier(){
    AgentType::EndOfFightModifier();
    SetDamagePoints(GetDamagePoints()*1.3);
    return;
}

PsychicAgent::~PsychicAgent(){
    numberOfHits_ = 0;
}
