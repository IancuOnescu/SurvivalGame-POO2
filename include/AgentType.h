#ifndef AGENTTYPE_H
#define AGENTTYPE_H
#include "ItemType.h"
#include <vector>
#include <map>
#include "MapManager.h"

class ItemType;

class AgentType
{
    char symbol_;
    float damagePoints_;
    float healthPoints_;
    std::pair<int, int>movementPattern_;
    std::pair<int, int>position_;
    std::map<std::string, std::vector<ItemType*>>inventory_;
    public:
        AgentType(float, float, std::pair<int, int>, std::pair<int, int>, char);
        float ApplyItemsModifier(float, std::string);
        virtual void DealDamage(AgentType*);
        virtual void TakeDamage(float);
        void ChangePosition(const MapManager&);
        void SetMovementPattern(std::pair<int, int>);
        std::pair<int, int> GetMovementPattern() const;
        void SetPosition(std::pair<int, int>);
        std::pair<int, int> GetPosition() const;
        virtual void ChangeMovementPattern(int) = 0;
        void SetDamagePoints(float val);
        float GetDamagePoints() const;
        void SetHealthPoints(float val);
        float GetHealthPoints() const;
        char GetSymbol() const;
        virtual void StartOfFightModifier();
        virtual void MidFightModifier() = 0;
        virtual void EndOfFightModifier() = 0;
        void AddToInventory(ItemType*);
        virtual ~AgentType();
};

inline void AgentType::SetDamagePoints(float val){damagePoints_ = val;}

inline float AgentType::GetDamagePoints() const {return damagePoints_;}

inline void AgentType::SetHealthPoints(float val){healthPoints_ = val;}

inline float AgentType::GetHealthPoints() const {return healthPoints_;}

inline std::pair<int, int> AgentType::GetPosition() const {return position_;}

inline void AgentType::SetPosition(std::pair<int, int> pos){position_ = pos;}

inline void AgentType::SetMovementPattern(std::pair<int, int> pat){movementPattern_ = pat;}

inline std::pair<int, int> AgentType::GetMovementPattern() const {return movementPattern_;}

inline char AgentType::GetSymbol() const {return symbol_;}
#endif // AGENTTYPE_H
