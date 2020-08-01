#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

struct My_stack{

    int top;
    unsigned capacity;
    char* array;
};

//func to make stack with determined capacity
struct My_stack* createStack(unsigned capacity){
struct My_stack* stack = (struct My_stack*)malloc(sizeof(struct My_stack));
stack->capacity = capacity;
stack->top = -1;
stack->array = (int*) malloc(stack->capacity* sizeof(int));
return stack;
}

// check if stack is full
int isFull(struct My_stack* stack){
    return stack->top == stack->capacity -1;
}

// check if stack is empty
int isEmpty(struct My_stack* stack){
    return stack->top == -1;
}
//insert item
void push(struct My_stack* stack , char item){
    
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%c pushed to stack\n", item);
}

// remove item from stack

int pull(struct My_stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
        
    return stack->array[stack->top--]; //return then decrease
}

// return the top of stack without removing it

int peak(struct My_stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

//driver program to test
char* BalancedParentheses(char* exp){
    struct My_stack* stack_1 =createStack(100);
     
    for(int i =0;i<strlen(exp);i++){
        if(exp[i]=='{' || exp[i]=='(')
        push(stack_1,exp[i]);
        if(exp[i]=='}' || exp[i]==')')
        {
            if (stack_1->array[stack_1->top]=='(' && exp[i]!=')')
            {
                
                return "unbalanced";
            }
            if (stack_1->array[stack_1->top]=='{' && exp[i]!='}')
            {
                
                return "unbalanced";
            }
            if (stack_1->array[stack_1->top]=='[' && exp[i]!=']')
            {
                
                return "unbalanced";
            }
            else 
                pull(stack_1);
        }
   
    }
 
 printf(" stack top is %c\n", stack_1->array[stack_1->top]);
 if(isEmpty(stack_1))
    return "balanced";
    else
    {
        return "unbalanced";
    }
    
}


int main(){
    char expo[]="({(3)*5})";
     
  printf("%s\n", BalancedParentheses(expo));
 //   struct My_stack* stack_1 = createStack(10);
 //   push(stack_1,'c');
    // printf(" stack top is %c\n", stack_1->array[stack_1->top]);
  //  push(stack_1,2);
  //   printf(" stack top is %d\n", stack_1->array[stack_1->top]);
  //  push(stack_1,3);
  //   printf(" stack top is %d\n", stack_1->array[stack_1->top]);
  //   pull(stack_1);
    //  printf(" stack top is %d\n", stack_1->array[stack_1->top]);

    return 0;
}

/*char* BalancedParentheses(char* exp){
    struct My_stack* stack_1 =createStack(100);
     
    for(int i =0;i<strlen(exp);i++){
        if(exp[i]=='{' || exp[i]=='(')
        push(stack_1,exp[i]);
        if(exp[i]=='}' || exp[i]==')')
        {
            if (stack_1->array[stack_1->top]=='(' && exp[i]!=')')
            {
                
                return "unbalanced";
            }
            if (stack_1->array[stack_1->top]=='{' && exp[i]!='}')
            {
                
                return "unbalanced";
            }
            if (stack_1->array[stack_1->top]=='[' && exp[i]!=']')
            {
                
                return "unbalanced";
            }
            else 
                pull(stack_1);
        }
   
    }
 
 printf(" stack top is %c\n", stack_1->array[stack_1->top]);
 if(isEmpty(stack_1))
    return "balanced";
    else
    {
        return "unbalanced";
    }
    
}*/