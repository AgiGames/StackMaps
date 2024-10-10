#include "CoordinatedValue.h"
#include <stdio.h>

void printCoordinatedValue(CoordinatedValue coordinatedValue) {
    
    printf("[i: %d, ", coordinatedValue.i);
    printf("j: %d, ", coordinatedValue.j);
    printf("value: %lf]\n", coordinatedValue.value);
    
}