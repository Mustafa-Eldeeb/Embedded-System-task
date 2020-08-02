#include "my_stack.h"
#include "dataTypes.h"


//func to make stack with determined capacity
struct My_stack* createStack(uint8_t capacity)
{
    struct My_stack* stack = (struct My_stack*)malloc(sizeof(struct My_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// check if stack is full
uint8_t isFull(struct My_stack* stack) {
    return stack->top == stack->capacity - 1;
}

// check if stack is empty
uint8_t isEmpty(struct My_stack* stack) {
    return stack->top == -1;
}
//insert item
void push(struct My_stack* stack, uint8_t item) {

    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
   // printf("%c pushed to stack\n", item); //just for debug
}

// remove item from stack

uint8_t pull(struct My_stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;

    return stack->array[stack->top--]; //return then decrease
}

// return the top of stack without removing it

uint8_t peak(struct My_stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// function to check if the parentheses in exp are balanced or not !
uint8_t* BalancedParentheses(uint8_t* exp) {
    struct My_stack* stack_1 = createStack(100);

    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(stack_1, exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {   
            if(isEmpty(stack_1))
            {
                return "unbalanced";
            }
            
            if (stack_1->array[stack_1->top] == '(' && exp[i] != ')')
            {

                return "unbalanced";
            }
            if (stack_1->array[stack_1->top] == '{' && exp[i] != '}')
            {

                return "unbalanced";
            }
            if (stack_1->array[stack_1->top] == '[' && exp[i] != ']')
            {

                return "unbalanced";
            }
            else
                pull(stack_1);
        }

    }

   // printf(" stack top is %c\n", stack_1->array[stack_1->top]); for debug
    if (isEmpty(stack_1))
        return "balanced";
    else
    {
        return "unbalanced";
    }

}
