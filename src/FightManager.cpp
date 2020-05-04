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
    Agent1_->StartOfFightModifier();
    Agent2_->StartOfFightModifier();
    std::cout << "Ladies and gentleman we have a fight\n";
    std::cout << "location: (" << Agent1_->GetPosition().first+1 << "," << Agent1_->GetPosition().second+1 << ")\n";
    std::cout << Agent1_->GetSymbol() << " HP:" << Agent1_->GetHealthPoints() << " DMG:" << Agent1_->GetDamagePoints() << "\n";
    std::cout << Agent2_->GetSymbol() << " HP:" << Agent2_->GetHealthPoints() << " DMG:" << Agent2_->GetDamagePoints() << "\n";
    while(!IsDead(Agent1_) && !IsDead(Agent2_)){
        Agent1_->DealDamage(Agent2_);
        Agent1_->MidFightModifier();
        if(!IsDead(Agent2_)){
            Agent2_->DealDamage(Agent1_);
            Agent2_->MidFightModifier();
        }
    }
    std::cout << GetLoser()->GetSymbol() << "lost\n";
}

AgentType* FightManager::GetLoser() const{
    return IsDead(Agent1_) ? Agent1_ : Agent2_;
}

AgentType* FightManager::GetWinner() const{
    return IsDead(Agent1_) ? Agent2_ : Agent1_;
}

FightManager::~FightManager(){
}
