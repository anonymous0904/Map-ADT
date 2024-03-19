#ifndef MAP1_MAPITERATOR_H
#define MAP1_MAPITERATOR_H

#endif //MAP1_MAPITERATOR_H
#pragma once
#include "Map.h"
class MapIterator
{
    friend class Map;
private:
    const Map& map;
    MapNode*curr_node;

    MapIterator(const Map& m);

public:

    //iterator moves on the first position of the list
    void first();

    //iterates over the next position in the list
    void next();

    //returns the pair (key,value) at the current position
    TElem getCurrent();

    //returns true if the current position of the iterator in the list is pointing to a valid element, false otherwise
    bool valid() const;
};


