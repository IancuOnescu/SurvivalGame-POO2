#include "../include/ItemType.h"

ItemType::ItemType(std::pair<int, int> pos, std::string cls):position_(pos), classifType_(cls){
    SetModifAmount(RandomizeModifAmount());
}

float ItemType::RandomizeModifAmount(){
    return rand() % 40;
}

ItemType::~ItemType()
{
    position_ = std::make_pair(-1, -1);
    modifAmount_ = 0;
}
