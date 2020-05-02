#ifndef MAGEAGENT_H
#define MAGEAGENT_H

#include "AgentType.h"


class MageAgent : public AgentType
{
    float enemyDMG_;
    public:
        MageAgent(std::pair<int, int>);
        void DealDamage(AgentType*);
        void ChangeMovementPattern();
        void StartOfFightModifier();
        void MidFightModifier();
        void EndOfFightModifier();
        virtual ~MageAgent();
};

#endif // MAGEAGENT_H
