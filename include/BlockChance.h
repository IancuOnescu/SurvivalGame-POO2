#ifndef BLOCKCHANCE_H
#define BLOCKCHANCE_H

#include <UniqueEffectItems.h>


class BlockChance : public UniqueEffectItems
{
    public:
        BlockChance(std::pair<int, int>);
        virtual ~BlockChance();
        void TakeEffect(AgentType*);
};

#endif // BLOCKCHANCE_H
