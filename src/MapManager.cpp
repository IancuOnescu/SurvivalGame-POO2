#include "../include/MapManager.h"

MapManager::MapManager(int s):size_(s){
    map_ = new char *[size_];
    for(unsigned int i=0; i<size_; ++i)
        map_[i] = new char[size_];
    for(unsigned int i=0; i<size_; ++i)
        for(unsigned int j=0; j<size_; ++j)
            map_[i][j] = ' ';
}

void MapManager::DisplayDash(int n) const{
    for(int i=0; i<n; i++)
        std::cout<<"-";
    std::cout<<"\n";
}

void MapManager::Display() const{
    DisplayDash(2*size_+1);
    for(unsigned int i=0; i<size_; ++i){
        std::cout<<"|";
        for(unsigned int j=0; j<size_; ++j)
            std::cout<<map_[i][j]<<"|";
        std::cout<<"\n";
        DisplayDash(2*size_+1);
    }
}

bool MapManager::IsPositionMarked(const std::pair<int, int> pos) const{
    return map_[pos.first][pos.second] == ' ' ? false : true;
}

void MapManager::MarkPosition(const std::pair<int, int> pos, const char symbol){
    map_[pos.first][pos.second] = symbol;
}

MapManager::~MapManager(){
}
