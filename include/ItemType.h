#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include "AgentType.h"
#include <string>
#include <cstdlib>

class AgentType;

class ItemType
{
    std::pair<int, int>position_;
    const std::string classifType_;
    float modifAmount_;
    public:
        ItemType(std::pair<int, int>, std::string);
        std::string GetClassifType();
        float RandomizeModifAmount();
        float GetModifAmount();
        void SetModifAmount(float);
        std::pair<int, int> GetPosition();
        virtual void TakeEffect(AgentType*) = 0;
        virtual ~ItemType();
};

inline std::pair<int, int> ItemType::GetPosition(){return position_;}

inline std::string ItemType::GetClassifType(){return classifType_;}

inline float ItemType::GetModifAmount(){return modifAmount_;}

inline void ItemType::SetModifAmount(float val){modifAmount_ = val;}

#endif // ITEMTYPE_H
