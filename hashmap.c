#include "hashmap.h"
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdio.h>


// a hashing function to return an index based on given double value
unsigned long long hashFunction(double key) {
    
    unsigned long long result;
    
    memcpy(&result, &key, sizeof(key));

    return result ^ (result >> 32);
    
}

// function to create a hash map
HashMap* createHashMap(int capacity) {
    
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->capacity = capacity;
    map->size = 0;
    map->array = (HashNode**)malloc(capacity * sizeof(HashNode*));
    for (int i = 0; i < capacity; i++) {
        map->array[i] = NULL;
    }
    return map;
    
}

HashNode* createHashNode(CoordinatedValue coordinatedValue) {
    
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = coordinatedValue.value;
    Stack* stack = createNewStack();
    push(stack, coordinatedValue);
    node->coordValStack = stack;
    node->isActive = 1;
    return node;
    
}

void resizeHashMap(HashMap* map) {
    
    int newCapacity = map->capacity * 2; // setting the new capactity to twice the current
    HashNode** newArray = (HashNode**)malloc(newCapacity * sizeof(HashNode*));
    for (int i = 0; i < newCapacity; i++) {
        newArray[i] = NULL;
    } // making the new array with the capacity of twice the current capacity

    // rehash all the values from the old array
    for (int i = 0; i < map->capacity; i++) {
        if (map->array[i] != NULL && map->array[i]->isActive) {
            unsigned long long hash = hashFunction(map->array[i]->key);
            int index = hash % newCapacity;

            while (newArray[index] != NULL) {
                index = (index + 1) % newCapacity;
            }
            newArray[index] = map->array[i];
        }
    }

    // free the old array
    for (int i = 0; i < map->capacity; i++) {
        if (map->array[i] != NULL) {
            freeStack(map->array[i]->coordValStack);
            free(map->array[i]->coordValStack); 
            free(map->array[i]);
        }
    }
    free(map->array);
    map->array = newArray;
    map->capacity = newCapacity;
    
}

// function to insert a key value pair
void insertHashNode(HashMap* map, CoordinatedValue coordinatedValue) {

    // resize if needed
    if ((float)map->size / map->capacity >= LOAD_FACTOR_THRESHOLD) {
        resizeHashMap(map);
    }

    unsigned long long hash = hashFunction(coordinatedValue.value);
    int index = hash % map->capacity;

    while (map->array[index] != NULL && map->array[index]->isActive) {
        if (map->array[index]->key == coordinatedValue.value) {
            push(map->array[index]->coordValStack, coordinatedValue);
            return;
        }
        index = (index + 1) % map->capacity;
    }

    map->array[index] = createHashNode(coordinatedValue);
    map->size++;
    
}

// function to get value based on key
CoordinatedValue get(HashMap* map, double key) {
    
    unsigned long long hash = hashFunction(key);
    int index = hash % map->capacity;

    while (map->array[index] != NULL) {
        if (map->array[index]->isActive && map->array[index]->key == key) {
            return peek(map->array[index]->coordValStack);
        }
        index = (index + 1) % map->capacity;
    }
    CoordinatedValue errorCoordinatedValue;
    errorCoordinatedValue.i = INT_MIN;
    errorCoordinatedValue.j = INT_MIN;
    errorCoordinatedValue.value = FLT_MIN;
    return errorCoordinatedValue;
    
}

void deleteHashNode(HashMap* map, double key) {
    
    unsigned long long hash = hashFunction(key);
    int index = hash % map->capacity;

    while (map->array[index] != NULL) {
        if (map->array[index]->isActive && map->array[index]->key == key) {
            map->array[index]->isActive = 0;
            map->size--;
            return;
        }
        index = (index + 1) % map->capacity;
    }
    
}

void freeHashMap(HashMap* map) {
    
    for (int i = 0; i < map->capacity; i++) {
        if (map->array[i] != NULL) {
            freeStack(map->array[i]->coordValStack);
            free(map->array[i]->coordValStack); 
            free(map->array[i]);
        }
    }
    free(map->array);
    free(map);
    
}

void printHashMap(HashMap* map) {
    
    for (int i = 0; i < map->capacity; i++) {
        if (map->array[i] == NULL) {
            printf("Bucket %d: [EMPTY]\n", i);
        } else if (!map->array[i]->isActive) {
            printf("Bucket %d: [DELETED]\n", i);
        } else {
            printf("Bucket %d: %lf -> \n", i, map->array[i]->key);
            displayStack(map->array[i]->coordValStack);
        }
    }
    
}