#ifndef PSYCHICAGENT_H
#define PSYCHICAGENT_H
#include "AgentType.h"

class PsychicAgent:public AgentType
{
    unsigned int numberOfHits_;
    public:
        PsychicAgent(std::pair<int, int>);
        void DealDamage(AgentType*);
        void ChangeMovementPattern();
        void StartOfFightModifier();
        void MidFightModifier();
        void EndOfFightModifier();
         ~PsychicAgent();
};

#endif // PSYCHICAGENT_H
