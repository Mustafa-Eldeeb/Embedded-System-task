
#ifndef _MY_STACK_
#define _MY_STACK_
#include <limits.h>
#include "dataTypes.h"

struct My_stack {

    int top;
    uint8_t capacity;
    uint8_t* array;
};
struct My_stack* createStack(unsigned capacity);

uint8_t isFull(struct My_stack* stack);
uint8_t isEmpty(struct My_stack* stack);
void push(struct My_stack* stack, uint8_t item);
uint8_t pull(struct My_stack* stack);
uint8_t peak(struct My_stack* stack);
uint8_t* BalancedParentheses(uint8_t* exp);

#endif //MY_STACK