#ifndef DODGECHANCE_H
#define DODGECHANCE_H

#include "UniqueEffectItems.h"


class DodgeChance : public UniqueEffectItems
{
    public:
        DodgeChance(std::pair<int, int>);
        virtual ~DodgeChance();
        void TakeEffect(AgentType*);
};

#endif // DODGECHANCE_H
