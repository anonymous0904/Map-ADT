#include "Map.h"
#include "MapIterator.h"

#include <iostream>

using namespace std;

Map::Map() {
    head= nullptr;
    tail= nullptr;
    mapSize=0;
}

//teta(n)-scrolls through the entire list to delete each element
Map::~Map() {
    MapNode*current=head;
    while(current){
        MapNode*next=current->next;
        delete current;
        current=next;
    }
}

//Overall: O(n)
//Best case: teta(1)-the searched element is on the first position in the list
//Average case: teta(n)-the searched element is in the middle of the list. The search takes n/2 steps
//Worst case: teta(n)-the searched element is either on the last position, or it is not in the list at all.
TValue Map::search(TKey c) const{
    MapNode*current=head;
    while(current) {
        if (current->key == c) {
            return current->value;
        }
        current=current->next;
    }
    return NULL_TVALUE;
}

//Overall:O(n)
//Best Case:teta(1)- the element with the key value "c" is on the first position in the list
//Average case: teta(n)- the element with the key value "c" is in the middle of the list, therefore, the algorithm takes n/2 steps
//Worst case: teta(n)- the element with the key value "c" is either on the last position, or it is not in the list at all, therefore,
//the algorithm goes through the entire list
TValue Map::add(TKey c, TValue v) {
    //Check if the key already exists and update the value if so
    TValue val;
    MapIterator it = iterator();
    while (it.valid()) {
        if (it.curr_node->key == c) {
            val = it.curr_node->value;
            it.curr_node->value = v;
            return val;
        }
        it.next();
    }
    // If the key doesn't exist, create a new node and append it at the end of the list
    auto *newNode = new MapNode;
    newNode->key = c;
    newNode->value = v;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr) {//If the list is empty
        head = newNode;
        tail = newNode;
        mapSize++;
        return NULL_TVALUE;
    } else {
        tail->next=newNode;
        tail->next->prev=tail;
        tail=newNode;
        mapSize++;
    }
    return NULL_TVALUE;
}

//Total:O(n)
//Best Case:teta(1)-the element with the key value "c" is on the first position of the list
//Average case: teta(n)-the element with the key value "c" is in the middle of the list
//Worst case: teta(n)-the element is at the end of the list and the algorithm takes 2*n steps (n for searching the element, n for going through
//the list to delete it)
TValue Map::remove(TKey c){
    if(search(c)==NULL_TVALUE) {
        return NULL_TVALUE;
    }
    else{
        TValue val= search(c);
        mapSize--;
        MapIterator iterator1=iterator();
        while(iterator1.curr_node){
            if(iterator1.curr_node->key==c){
                if(iterator1.curr_node!=head){
                    iterator1.curr_node->prev->next=iterator1.curr_node->next;
                }
                else{
                    head=iterator1.curr_node->next;
                }
                if(iterator1.curr_node->next){
                    iterator1.curr_node->next->prev=iterator1.curr_node->prev;
                }
                delete iterator1.curr_node;
                return val;
            }
            iterator1.next();
        }
        return val;
    }
}

int Map::size() const {
    return mapSize;
}

bool Map::isEmpty() const{
    if(mapSize==0){
        return true;
    }
    return false;
}

void Map::printMap() {
    MapNode*current=head;
    while(current){
        cout<<"key: "<<current->key<<" value:"<<current->value<<endl;
        current=current->next;
    }
}

MapIterator Map::iterator() const {
    return MapIterator(*this);
}

Map::Map(const Map&original){
    head= nullptr;
    tail= nullptr;
    mapSize=original.mapSize;
    MapNode *current_node=original.head;
    while(current_node){
        this->add(current_node->key,current_node->value);
        current_node=current_node->next;
    }
}