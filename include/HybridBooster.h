#ifndef HYBRIDBOOSTER_H
#define HYBRIDBOOSTER_H
#include "ItemType.h"


class HybridBooster : public ItemType
{
    public:
        HybridBooster(std::pair<int, int>);
        virtual ~HybridBooster();
        void TakeEffect(AgentType*);
};

#endif // HYBRIDBOOSTER_H
