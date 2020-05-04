#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include "AgentType.h"
#include <string>
#include <cstdlib>

class AgentType;

class ItemType
{
    char symbol_;
    std::pair<int, int>position_;
    const std::string classifType_;
    float modifAmount_;
    public:
        ItemType(std::pair<int, int>, std::string, char);
        std::string GetClassifType() const;
        float RandomizeModifAmount();
        float GetModifAmount();
        char GetSymbol() const;
        void SetModifAmount(float);
        std::pair<int, int> GetPosition() const;
        virtual void TakeEffect(AgentType*) = 0;
        virtual ~ItemType();
};

inline std::pair<int, int> ItemType::GetPosition() const {return position_;}

inline std::string ItemType::GetClassifType() const {return classifType_;}

inline float ItemType::GetModifAmount(){return modifAmount_;}

inline void ItemType::SetModifAmount(float val){modifAmount_ = val;}

inline char ItemType::GetSymbol() const {return symbol_;}

#endif // ITEMTYPE_H
