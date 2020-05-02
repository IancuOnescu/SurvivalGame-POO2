#ifndef CRITICALCHANCE_H
#define CRITICALCHANCE_H

#include "UniqueEffectItems.h"


class CriticalChance : public UniqueEffectItems
{
    public:
        CriticalChance(std::pair<int, int>);
        virtual ~CriticalChance();
        void TakeEffect(AgentType*);
};

#endif // CRITICALCHANCE_H
