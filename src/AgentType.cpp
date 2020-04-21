#include "AgentType.h"

AgentType::AgentType()
{
}

void AgentType::DealDamage(AgentType& enemyAgent){
    ///go trough items for damage change
    enemyAgent.TakeDamage(///new damage)
    return;
}

void AgentType::TakeDamage(float damageTaken){
    ///go trough itmes for less damage
    return;
}

void AgentType::ChangePosition(){
    if(movementPattern_.first+position_.first >= sizeofmap || movementPattern_.second+position_.second >= sizeofmap)
        ChangeMovementPattern();
    SetPosition(make_pair<position_.first+movementPattern_.first, position_.second+movementPattern_.second>);
    return;
}

void AgentType::StartOfFightModifier(){
    ///loop trough items for immediates
    return;
}

void AddToInventory(ItemType& item){
    map[item.GetClassifType()].append(item);
    item.SetTaken(true);
    return;
}

AgentType::~AgentType()
{
}
