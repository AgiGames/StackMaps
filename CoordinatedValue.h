#ifndef CV_H
#define CV_H

struct CoordinatedValue{
  
    int i;
    int j;
    double value;
    
};
typedef struct CoordinatedValue CoordinatedValue;

void printCoordinatedValue(CoordinatedValue coordinatedValue);

#endif