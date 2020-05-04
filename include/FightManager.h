#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H

#include "AgentType.h"
#include <memory>
#include <iostream>

class FightManager
{
    AgentType* Agent1_;
    AgentType* Agent2_;
    public:
        FightManager(AgentType*, AgentType*);
        bool IsDead(AgentType*) const;
        void StartFight();
        void EndFight();
        AgentType* GetLoser() const;
        AgentType* GetWinner() const;
        virtual ~FightManager();
};


#endif // FIGHTMANAGER_H
