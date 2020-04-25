#include "../include/AgentType.h"

AgentType::AgentType(float dmg, float healt, std::pair<int, int> pattern, std::pair<int, int> pos):damagePoints_(dmg), healthPoints_(healt), movementPattern_(pattern), position_(pos){
}

float AgentType::ApplyItemsModifier(float damageToModify, std::string itemType){
    for(auto item : inventory_[itemType]){
        item->TakeEffect(this);
//        damageToModify = item->GetModifier(damageToModify);
    }
    return damageToModify;
}

void AgentType::DealDamage(AgentType* enemyAgent){
    float damageToDeal = ApplyItemsModifier(damagePoints_, "Offensive");
    enemyAgent->TakeDamage(damageToDeal);
    return;
}

void AgentType::TakeDamage(float damageTaken){
    float damageToTake = ApplyItemsModifier(damageTaken, "Deffensive");
    if(damageToTake>0)
        healthPoints_ -= damageToTake;
    return;
}

void AgentType::ChangePosition(){
    int sizeOfMap = 10;
    if(movementPattern_.first+position_.first >= sizeOfMap || movementPattern_.second+position_.second >= sizeOfMap
       || movementPattern_.first+position_.first < 0 || movementPattern_.second+position_.second < 0)
        ChangeMovementPattern();
    position_.first = movementPattern_.first + position_.first;
    position_.second = movementPattern_.second + position_.second;
    return;
}

void AgentType::StartOfFightModifier(){
    for(auto item: inventory_["Immediate"])
        item->TakeEffect(this);
    return;
}

void AgentType::AddToInventory(ItemType* item){
    inventory_[item->GetClassifType()].push_back(item);
    return;
}

AgentType::~AgentType()
{
    damagePoints_ = 0;
    healthPoints_ = 0;
    movementPattern_ = std::make_pair(0, 0);
    position_ = std::make_pair(-1, -1);
    inventory_.clear();
}
