#include "../include/AgentType.h"

AgentType::AgentType(float dmg, float health, std::pair<int, int> pattern, std::pair<int, int> pos, char symbol):damagePoints_(dmg), healthPoints_(health), movementPattern_(pattern), position_(pos), symbol_(symbol){
}

float AgentType::ApplyItemsModifier(float damageToModify, std::string itemType){
    for(auto item : inventory_[itemType]){
        item->SetModifAmount(damageToModify);
        item->TakeEffect(this);
        damageToModify += item->GetModifAmount();
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

void AgentType::ChangePosition(const MapManager& map){
    int sizeOfMap = map.GetSize();
    if(movementPattern_.first+position_.first >= sizeOfMap || movementPattern_.second+position_.second >= sizeOfMap
       || movementPattern_.first+position_.first < 0 || movementPattern_.second+position_.second < 0)
        ChangeMovementPattern(sizeOfMap);
    position_.first = movementPattern_.first + position_.first;
    position_.second = movementPattern_.second + position_.second;
    return;
}

void AgentType::StartOfFightModifier(){
    for(auto item: inventory_["Immediate"]){
        item->TakeEffect(this);
        delete item;
    }
    inventory_["Immediate"].clear();
    return;
}

void AgentType::AddToInventory(ItemType* item){
    inventory_[item->GetClassifType()].push_back(item);
    return;
}

void AgentType::EndOfFightModifier(){
    healthPoints_ += 100;
}

AgentType::~AgentType()
{
    for(auto it : inventory_)
        for(auto item : it.second)
            delete item;
    inventory_.clear();
}
