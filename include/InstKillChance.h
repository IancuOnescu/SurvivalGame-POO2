#ifndef INSTKILLCHANCE_H
#define INSTKILLCHANCE_H

#include "UniqueEffectItems.h"


class InstKillChance : public UniqueEffectItems
{
    public:
        InstKillChance(std::pair<int, int>);
        virtual ~InstKillChance();
        void TakeEffect(AgentType*);
};

#endif // INSTKILLCHANCE_H
