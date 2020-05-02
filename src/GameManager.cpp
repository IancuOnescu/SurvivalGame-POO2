#include "../include/GameManager.h"

GameManager::GameManager(int size):map_(size){
    srand(time(NULL));
    createAgentsFunctions_.push_back(&CreateRandomAgent<MageAgent>);
    createAgentsFunctions_.push_back(&CreateRandomAgent<MarauderAgent>);
    createAgentsFunctions_.push_back(&CreateRandomAgent<AssassinAgent>);
    createAgentsFunctions_.push_back(&CreateRandomAgent<PsychicAgent>);
    createItemsFunctions_.push_back(&CreateRandomItem<HPBooster>);
    createItemsFunctions_.push_back(&CreateRandomItem<DMGBooster>);
    createItemsFunctions_.push_back(&CreateRandomItem<HybridBooster>);
    createItemsFunctions_.push_back(&CreateRandomItem<DodgeChance>);
    createItemsFunctions_.push_back(&CreateRandomItem<InstKillChance>);
    createItemsFunctions_.push_back(&CreateRandomItem<BlockChance>);
    createItemsFunctions_.push_back(&CreateRandomItem<CriticalChance>);
}

template<typename T>
void GameManager::CreateUnits(std::vector<T> units, unsigned int nrOfUnits, T (GameManager::*funct)(std::pair<int, int>), char symbol){
    for(unsigned int i=0; i<nrOfUnits; ++i){
        unsigned int size = map_.GetSize();
        int xcoord = rand() % size;
        int ycoord = rand() % size;
        while(map_.IsPositionMarked(std::make_pair(xcoord, ycoord)))
            xcoord = rand() % size , ycoord = rand() % size;
        units.push_back((this->*funct)(std::make_pair(xcoord, ycoord)));
        map_.MarkPosition(std::make_pair(xcoord, ycoord), symbol);
    }
}

void GameManager::CreateAgents(int nrOfAgents){
    CreateUnits(agents_, nrOfAgents, GetRandomAgent, 'A');
    map_.Display();
}

void GameManager::CreateItems(int nrOfItems){
    CreateUnits(items_, nrOfItems, GetRandomItem, 'R');
}

template<typename T>
AgentType* GameManager::CreateRandomAgent(std::pair<int, int> pos){
    return new T(pos);
}

template<typename T>
ItemType* GameManager::CreateRandomItem(std::pair<int, int> pos){
    return new T(pos);
}

AgentType* GameManager::GetRandomAgent(std::pair<int, int> pos){
    return (this->*createAgentsFunctions_[rand() % createAgentsFunctions_.size()])(pos);
}

ItemType* GameManager::GetRandomItem(std::pair<int, int> pos){
    return (this->*createItemsFunctions_[rand() % createItemsFunctions_.size()])(pos);
}

GameManager::~GameManager(){
}
