#ifndef HPBOOSTER_H
#define HPBOOSTER_H
#include "ItemType.h"

class HPBooster:public ItemType
{
    public:
        HPBooster(std::pair<int, int>);
        virtual ~HPBooster();
        void TakeEffect(AgentType*);
};

#endif // HPBOOSTER_H
