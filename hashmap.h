#include "CoordinatedValue.h"
#include "stack.h"

#ifndef HASHMAP_H
#define HASHMAP_H

#define INITIAL_CAPACITY 16
#define LOAD_FACTOR_THRESHOLD 0.7

// structure to represent each node in the hash map
struct HashNode {
    
    double key;
    Stack* coordValStack;
    int isActive; // flag to mark active nodes (1) or deleted nodes (0)
    
};

typedef struct HashNode HashNode;

struct HashMap {
    
    HashNode** array; // array of pointers to HashNode
    int capacity; // total capacity of the hash map
    int size; // current number of active elements in the hash map
    
};

typedef struct HashMap HashMap;

unsigned long long hashFunction(double key);

HashMap* createHashMap(int capacity);

HashNode* createHashNode(CoordinatedValue coordinatedValue);

void resizeHashMap(HashMap* map);

void insertHashNode(HashMap* map, CoordinatedValue coordinatedValue);

CoordinatedValue get(HashMap* map, double key);

void deleteHashNode(HashMap* map, double key);

void freeHashMap(HashMap* map);

void printHashMap(HashMap* map);

#endif