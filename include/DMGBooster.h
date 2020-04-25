#ifndef DMGBOOSTER_H
#define DMGBOOSTER_H
#include "ItemType.h"


class DMGBooster : public ItemType
{
    public:
        DMGBooster(std::pair<int, int>);
        virtual ~DMGBooster();
        void TakeEffect(AgentType*);
};

#endif // DMGBOOSTER_H
