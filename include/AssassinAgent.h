#ifndef ASSASSINAGENT_H
#define ASSASSINAGENT_H

#include "AgentType.h"


class AssassinAgent : public AgentType
{
    float enemyInitialHP_;
    float enemyHP_;
    float enemyHPAfterHit_;
    float initialHP_;
    public:
        AssassinAgent(std::pair<int, int>);
        virtual ~AssassinAgent();
        void DealDamage(AgentType*);
        void ChangeMovementPattern();
        void StartOfFightModifier();
        void MidFightModifier();
        void EndOfFightModifier();
};

#endif // ASSASSINAGENT_H
