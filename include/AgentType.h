#ifndef AGENTTYPE_H
#define AGENTTYPE_H
#include "ItemType.h"
#include <vector>
#include <map>

class ItemType;

class AgentType
{
    float damagePoints_;
    float healthPoints_;
    std::pair<int, int>movementPattern_;
    std::pair<int, int>position_;
    std::map<std::string, std::vector<ItemType*>>inventory_;
    public:
        AgentType(float, float, std::pair<int, int>, std::pair<int, int>);
        float ApplyItemsModifier(float, std::string);
        virtual void DealDamage(AgentType*);
        virtual void TakeDamage(float);
        void ChangePosition();
        void SetMovementPattern(std::pair<int, int>);
        std::pair<int, int> GetMovementPattern();
        std::pair<int, int> GetPosition();
        virtual void ChangeMovementPattern() = 0;
        void SetDamagePoints(float val);
        float GetDamagePoints();
        void SetHealthPoints(float val);
        float GetHealthPoints();
        virtual void StartOfFightModifier();
        virtual void MidFightModifier() = 0;
        virtual void EndOfFightModifier() = 0;
        void AddToInventory(ItemType*);
        virtual ~AgentType();
};

inline void AgentType::SetDamagePoints(float val){damagePoints_ = val;}

inline float AgentType::GetDamagePoints(){return damagePoints_;}

inline void AgentType::SetHealthPoints(float val){healthPoints_ = val;}

inline float AgentType::GetHealthPoints(){return healthPoints_;}

inline std::pair<int, int> AgentType::GetPosition(){return position_;}

inline void AgentType::SetMovementPattern(std::pair<int, int> pat){movementPattern_ = pat;}

inline std::pair<int, int> AgentType::GetMovementPattern(){return movementPattern_;}
#endif // AGENTTYPE_H
