#include "CoordinatedValue.h"
#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

struct StackNode { // struct to represent a node of a stack
    
    CoordinatedValue coordinatedValue;
    struct StackNode* nextStackNode;
    
};

typedef struct StackNode StackNode;

/*
 * struct to reperesent a stack
 * only the top node of the stack is accessible
 */
struct Stack { 
    
    struct StackNode* topNode;
    
};

typedef struct Stack Stack;

struct StackNode* createNewNode(CoordinatedValue coordinatedValue);

struct Stack* createNewStack();

bool isEmpty(Stack* queryStack);

void push(Stack* queryStack, CoordinatedValue coordinatedValue);

void pop(Stack* queryStack);

CoordinatedValue peek(struct Stack* queryStack);

void displayStack(Stack* queryStack);

void freeStack(Stack* queryStack);

#endif