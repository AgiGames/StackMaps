#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct StackNode* createNewNode(CoordinatedValue coordinatedValue) { // function to create a new node with certain given value
    
    struct StackNode* newNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    newNode->coordinatedValue = coordinatedValue;
    newNode->nextStackNode = NULL;
    return newNode;
    
}

struct Stack* createNewStack() { // function to create a new stack
    
    struct Stack* newStack = (struct Stack*) malloc(sizeof(struct Stack));
    newStack->topNode = NULL;
    return newStack;
    
}

bool isEmpty(Stack* queryStack) { // function to check if stack is empty

    return (queryStack->topNode == NULL);
    
}

void push(Stack* queryStack, CoordinatedValue coordinatedValue) { // function to add value to top of the stack
    
    struct StackNode* newNode = createNewNode(coordinatedValue);
    
    /*
     * if heap is full
     * do nothing
     */
    if(newNode == NULL) {
        printf("Heap Overflow!\n");
        return;
    }
    
    /*
     * since the new node is now the top node
     * the new node's next node in the stack is the previously top node of the stack
     * then update the stack's top node to the new node
     */
    newNode->nextStackNode = queryStack->topNode;
    queryStack->topNode = newNode;
    
}

void pop(Stack* queryStack) {
    
    /* 
     * if stack is empty
     * do nothing
     */
    if(queryStack->topNode == NULL) {
        printf("Heap Underflow!\n");
        return;
    }
    
    /*
     * change the top node of the stack
     * to the 2nd top node of the stack
     * which is the next node of the top node
     */
    printf("removed from stack:\n");
    printCoordinatedValue(queryStack->topNode->coordinatedValue);
    queryStack->topNode = queryStack->topNode->nextStackNode;
    
}

CoordinatedValue peek(Stack* queryStack) {
    
    /*
     * if stack is empty
     * return some large negative integer to imply stack is emty
     */
    if(isEmpty(queryStack)) {
        printf("\nSTACK IS EMPTY\n");
        CoordinatedValue errorCoordinatedValue;
        errorCoordinatedValue.i = INT_MIN;
        errorCoordinatedValue.j = INT_MIN;
        errorCoordinatedValue.value = FLT_MIN;
        return errorCoordinatedValue;
    }
        
    return (queryStack->topNode->coordinatedValue);
    
}

void displayStack(Stack* queryStack) {
    
    struct StackNode* stackNode = queryStack->topNode;
    while(stackNode != NULL) {
        printCoordinatedValue(stackNode->coordinatedValue);
        printf("-------------------------\n");
        stackNode = stackNode->nextStackNode;
    }
    
}

void freeStack(Stack* queryStack) {
    
    StackNode* stackNode = queryStack->topNode;
    StackNode* temp;

    while (stackNode != NULL) {
        temp = stackNode;
        stackNode = stackNode->nextStackNode;
        free(temp);
    }
    
}