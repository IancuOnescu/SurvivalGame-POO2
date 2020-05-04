#ifndef UNIQUEEFFECTITEMS_H
#define UNIQUEEFFECTITEMS_H

#include "ItemType.h"


class UniqueEffectItems : public ItemType
{
    int chancePercentage_;
    public:
        UniqueEffectItems(int, std::pair<int, int>, std::string, char);
        virtual ~UniqueEffectItems();
        bool TestChance();
};

#endif // UNIQUEEFFECTITEMS_H
