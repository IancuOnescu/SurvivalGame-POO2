#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <vector>
#include <iostream>

class MapManager
{
    char **map_;
    unsigned int size_;
    public:
        MapManager(int size_);
        void Display() const;
        void DisplayDash(int) const;
        unsigned int GetSize() const;
        bool IsPositionMarked(const std::pair<int, int>) const;
        void MarkPosition(const std::pair<int, int>, const char);
        void UnmarkPosition(const std::pair<int, int>);
        char GetSymbolAtPos(std::pair<int, int>) const;
        virtual ~MapManager();
};

inline unsigned int MapManager::GetSize() const{ return size_;}

#endif // MAPMANAGER_H
