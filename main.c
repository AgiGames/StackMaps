#include "CoordinatedValue.h"
#include "stack.h"
#include "hashmap.h"
#include <stdio.h>

int main() {
    
    CoordinatedValue coordVal1;
    CoordinatedValue coordVal2;
    CoordinatedValue coordVal3;
    
    coordVal1.i = 3;
    coordVal1.j = 4;
    coordVal1.value = 3.1415;
    
    coordVal2.i = 7;
    coordVal2.j = 8;
    coordVal2.value = 3.1415;
    
    coordVal3.i = 11;
    coordVal3.j = 12;
    coordVal3.value = 3.1415;
    
    HashMap* map = createHashMap(INITIAL_CAPACITY);
    insertHashNode(map, coordVal1);
    insertHashNode(map, coordVal2);
    insertHashNode(map, coordVal3);
    printHashMap(map);
    
    printf("Gotten Coord Val: \n");
    printCoordinatedValue(get(map, 3.1415));
    
    freeHashMap(map);
    
    return 0;
    
}