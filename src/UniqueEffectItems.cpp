#include "../include/UniqueEffectItems.h"

UniqueEffectItems::UniqueEffectItems(int chance, std::pair<int, int> pos, std::string cls, char symbol):ItemType(pos, cls, symbol), chancePercentage_(chance){
}

bool UniqueEffectItems::TestChance(){
    return (chancePercentage_ >= (rand() % 100));
}

UniqueEffectItems::~UniqueEffectItems(){
    chancePercentage_ = 0;
}
