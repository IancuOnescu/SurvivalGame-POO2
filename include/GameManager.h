#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "AgentType.h"
#include "ItemType.h"
#include "PsychicAgent.h"
#include "MageAgent.h"
#include "MarauderAgent.h"
#include "AssassinAgent.h"
#include "HPBooster.h"
#include "DMGBooster.h"
#include "HybridBooster.h"
#include "CriticalChance.h"
#include "DodgeChance.h"
#include "InstKillChance.h"
#include "BlockChance.h"
#include "FightManager.h"
#include "MapManager.h"
#include <vector>
#include <ctime>

class GameManager
{
    typedef AgentType* (GameManager::*CreateAFunctions)(std::pair<int, int>);
    typedef ItemType* (GameManager::*CreateIFunctions)(std::pair<int, int>);
    std::vector<CreateAFunctions> createAgentsFunctions_;
    std::vector<CreateIFunctions> createItemsFunctions_;
    std::vector<AgentType*> agents_;
    std::vector<ItemType*> items_;
    MapManager map_;
    public:
        GameManager(int);
        void RunGame();
        template<typename T> AgentType *CreateRandomAgent(std::pair<int, int>);
        template<typename T> ItemType *CreateRandomItem(std::pair<int, int>);
        template<typename T> void CreateUnits(std::vector<T>, unsigned int, T (GameManager::*)(std::pair<int, int>), char);
        AgentType* GetRandomAgent(std::pair<int, int>);
        ItemType* GetRandomItem(std::pair<int, int>);
        void CreateAgents(int);
        void CreateItems(int);
        virtual ~GameManager();
};

#endif // GAMEMANAGER_H
