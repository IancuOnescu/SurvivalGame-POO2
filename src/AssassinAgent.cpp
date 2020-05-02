#include "../include/AssassinAgent.h"

AssassinAgent::AssassinAgent(std::pair<int, int> pos):AgentType(110, 250, std::make_pair(1, 1), pos), enemyHP_(0), enemyInitialHP_(0), enemyHPAfterHit_(0), initialHP_(0){
}

void AssassinAgent::ChangeMovementPattern(){
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

void AssassinAgent::DealDamage(AgentType* enemyAgent){
    enemyHP_ = enemyAgent->GetHealthPoints();
    AgentType::DealDamage(enemyAgent);
    enemyHPAfterHit_ = enemyAgent->GetHealthPoints();
}

void AssassinAgent::StartOfFightModifier(){
    AgentType::StartOfFightModifier();
    enemyHP_ = 0;
    enemyInitialHP_ = 0;
    initialHP_ = GetHealthPoints();
    return;
}

void AssassinAgent::MidFightModifier(){
    if(enemyHP_ > enemyInitialHP_)
        enemyInitialHP_ = enemyHP_;
    if(enemyHP_ >= enemyInitialHP_*0.7 && enemyHPAfterHit_ < enemyInitialHP_ *0.7)
        SetDamagePoints(GetDamagePoints()*1.3);
    if(enemyHP_ >= enemyInitialHP_*0.4 && enemyHPAfterHit_ < enemyInitialHP_ *0.4)
        SetDamagePoints(GetDamagePoints()*1.3);
    if(enemyHP_ >= enemyInitialHP_*0.1 && enemyHPAfterHit_ < enemyInitialHP_ *0.1)
        SetDamagePoints(GetDamagePoints()*1.3);
    return;
}

void AssassinAgent::EndOfFightModifier(){
    if(enemyInitialHP_ > initialHP_)
        SetHealthPoints(enemyInitialHP_);
    AgentType::EndOfFightModifier();
    return;
}

AssassinAgent::~AssassinAgent(){
    enemyHP_ = 0;
}
