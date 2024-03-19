#include "Map.h"
#include "MapIterator.h"
using namespace std;

MapIterator::MapIterator(const Map& d) : map(d)
{
    curr_node= map.head;
}

void MapIterator::first() {
    curr_node=map.head;
}

void MapIterator::next() {
    if(curr_node!= nullptr) {
        curr_node = curr_node->next;
    }
}
TElem MapIterator::getCurrent(){
    if(not valid()) {
        return NULL_TELEM;
    }
    return make_pair(curr_node->key,curr_node->value );
}
bool MapIterator::valid() const {
    return curr_node!= nullptr;
}
