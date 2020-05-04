#ifndef MARAUDERAGENT_H
#define MARAUDERAGENT_H

#include "AgentType.h"


class MarauderAgent : public AgentType
{
    float damageTaken_;
    public:
        MarauderAgent(std::pair<int, int>);
        void TakeDamage(float);
        void ChangeMovementPattern(int);
        void StartOfFightModifier();
        void MidFightModifier();
        void EndOfFightModifier();
        virtual ~MarauderAgent();

    protected:

    private:
};

#endif // MARAUDERAGENT_H
