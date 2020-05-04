#include "../include/GameManager.h"

GameManager::GameManager(int size):map_(size), nrOfRounds_(0){
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
void GameManager::CreateUnits(std::vector<T*>& units, unsigned int nrOfUnits, T* (GameManager::*funct)(std::pair<int, int>)){
    unsigned int size = map_.GetSize();
    for(unsigned int i=0; i<nrOfUnits; ++i){
        int xcoord = rand() % size;
        int ycoord = rand() % size;
        while(map_.IsPositionMarked(std::make_pair(xcoord, ycoord)))
            xcoord = rand() % size , ycoord = rand() % size;
        units.push_back((this->*funct)(std::make_pair(xcoord, ycoord)));
        map_.MarkPosition(std::make_pair(xcoord, ycoord), units.back()->GetSymbol());
    }
}

void GameManager::CreateAgents(int nrOfAgents){
    CreateUnits<AgentType>(agents_, nrOfAgents, GetRandomAgent);
    map_.Display();
}

void GameManager::CreateItems(int nrOfItems){
    CreateUnits(items_, nrOfItems, GetRandomItem);
}

template<typename T>
AgentType* GameManager::CreateRandomAgent(std::pair<int, int> pos){
    return new T(pos);
}

template<typename T>
ItemType* GameManager::CreateRandomItem(std::pair<int, int> pos){
    return new T(pos);
}

template<typename T>
void GameManager::DeleteVector(std::vector<T>& vect){
    for(auto itr :vect)
        delete itr;
    vect.clear();
}

template<typename T>
T* GameManager::GetUnitAtPos(std::vector<T*> vect, std::pair<int, int> pos, T* notThisOne){
    for(auto unit: vect)
        if(unit->GetPosition() == pos && unit != notThisOne)
            return unit;
}

template<typename T>
void GameManager::EraseByPointer(std::vector<T*>& vect, T* ptr){
    auto it = std::find(vect.begin(), vect.end(), ptr);
    vect.erase(it);
}

AgentType* GameManager::GetRandomAgent(std::pair<int, int> pos){
    return (this->*createAgentsFunctions_[rand() % createAgentsFunctions_.size()])(pos);
}

ItemType* GameManager::GetRandomItem(std::pair<int, int> pos){
    return (this->*createItemsFunctions_[rand() % createItemsFunctions_.size()])(pos);
}

void GameManager::RunGame(unsigned int rounds){
    while(!IsGameOver() && rounds){
        RunRound();
        rounds--;
        nrOfRounds_++;
        if(IsGameOver()){
            std::cout << "That was it! Ty for playing!";
            exit(1);
        }
    }
}

///This is a mess
void GameManager::RunRound(){
    for(auto agent: agents_)
        if(agent->GetPosition().first >= 0 && agent->GetPosition().first < map_.GetSize() &&
           agent->GetPosition().second >= 0 && agent->GetPosition().second < map_.GetSize()){
            map_.UnmarkPosition(agent->GetPosition());
            std::cout << agent->GetSymbol() << " moved from (" << agent->GetPosition().first + 1 << "," << agent->GetPosition().second + 1<< ")";
            agent->ChangePosition(map_);
            std::pair<int, int> pos = agent->GetPosition();
            std::cout << " to (" << pos.first + 1 << "," << pos.second  + 1 << ")\n";
            if(map_.IsPositionMarked(pos)){
                if(map_.GetSymbolAtPos(pos) >= 'a' && map_.GetSymbolAtPos(pos) <='z'){
                        std::cout << "And picked up " << map_.GetSymbolAtPos(pos) << "\n";
                        ItemType* item = GetUnitAtPos<ItemType>(items_, pos);
                        agent->AddToInventory(item);
                        EraseByPointer<ItemType>(items_, item);
                        map_.MarkPosition(agent->GetPosition(), agent->GetSymbol());
                    }
                else{
                        AgentType* enemy = GetUnitAtPos<AgentType>(agents_, pos, agent);
                        FightManager* newFight = new FightManager(enemy, agent);
                        newFight->StartFight();
                        newFight->EndFight();
                        map_.MarkPosition(pos, newFight->GetWinner()->GetSymbol());
                        newFight->GetLoser()->SetPosition(std::make_pair(-1, -1));
                }
            }
            else  map_.MarkPosition(agent->GetPosition(), agent->GetSymbol());
        }
    for(auto agent = agents_.begin(); agent != agents_.end(); )
        if((*agent)->GetPosition() == std::make_pair(-1, -1)){
            delete *agent;
            agent = agents_.erase(agent);
        }
        else agent++;
    map_.Display();
}

bool GameManager::IsGameOver(){
    return agents_.size() == 1;
}

GameManager::~GameManager(){
    DeleteVector<AgentType*>(agents_);
    DeleteVector<ItemType*>(items_);
}
