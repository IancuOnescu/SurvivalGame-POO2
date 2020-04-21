#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include "AgentType.h"

class ItemType
{
    std::pair<int, int>position_;
    bool taken_;
    std::string classifType_;
    float modifAmount_;
    public:
        ItemType();
        void SetTaken(bool);
        bool GetTaken();
        void SetClassifType(std::string);
        std::string GetClassifType();
        void SetModifAmount(float value);
        float GetModifAmount();
        void SetPosition(std::pair)
        std::pair GetPosition();
        virtual void TakeEffect(AgentType&) = 0;
        virtual ~ItemType();
};

inline void ItemType::SetPosition(std::pair<int, int> pos){position_ = pos;}

inline std::pair<int, int> ItemType::GetPosition(){return position_;}

inline void ItemType::SetTaken(bool taken){taken_ = taken;}

inline bool ItemType::GetTaken(){return taken_;}

inline void ItemType::SetClassifType(std::string type){classifType_ = type}

inline std::string ItemType::GetClassifType(){return classifType_;}

#endif // ITEMTYPE_H
