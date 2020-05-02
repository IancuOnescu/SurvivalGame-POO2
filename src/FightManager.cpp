#include "../include/FightManager.h"

FightManager::FightManager(AgentType* ag1, AgentType* ag2):Agent1_(ag1), Agent2_(ag2){
}

bool FightManager::IsDead(AgentType* agent) const{
    return agent->GetHealthPoints() <= 0;
}

void FightManager::EndFight(){
    if(IsDead(Agent1_)){
        Agent2_->EndOfFightModifier();
        return;
    }
    Agent1_->EndOfFightModifier();
}

void FightManager::StartFight(){
    while(!IsDead(Agent1_) && !IsDead(Agent2_)){
        Agent1_->DealDamage(Agent2_);
        Agent1_->MidFightModifier();
        if(!IsDead(Agent2_)){
            Agent2_->DealDamage(Agent1_);
            Agent2_->MidFightModifier();
        }
    }
}

AgentType* FightManager::GetLoser(){
    return IsDead(Agent1_) ? Agent1_ : Agent2_;
}

FightManager::~FightManager(){
}
