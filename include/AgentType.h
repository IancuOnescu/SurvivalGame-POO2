#ifndef AGENTTYPE_H
#define AGENTTYPE_H

class AgentType
{
    float damagePoints_;
    float healthPoints_;
    std::pair<int, int>movementPattern_;
    std::pair<int, int>position_;
    std::map<std::string, std::vector<ItemType>>;
    public:
        AgentType();
        void DealDamage(AgentType&);
        void TakeDamage(float);
        void ChangePosition();
        void SetPosition(std::pair<int, int>);
        std::pair<int, int> GetPosition();
        virtual void ChangeMovementPattern() = 0;
        void SetDamagePoints(float val);
        float GetDamagePoints();
        void SetHealthPoints(float val);
        float GetHelathPoints();
        void StartOfFightModifier();
        virtual void MidFightModifier() = 0;
        virtual void EndOfFightModyifier() = 0;
        void AddToInventory();
        virtual ~AgentType();
};

inline void AgentType::SetDamagePoints(float val){damagePoints_ = val;}

inline float AgentType::GetDamagePoints(){return damagePoints_;}

inline void AgentType::SetHealthPoints(float val){healthPoints_ = val;}

inline float AgentType::GetHelathPoints(){return healthPoints_;}

inline void AgentType::SetPosition(std::pair<int, int> pos){position_ = pos;}

inline std::pair<int, int> AgentType::GetPosition(){return position_;}

#endif // AGENTTYPE_H
