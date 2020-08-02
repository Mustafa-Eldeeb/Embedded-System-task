// Task_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "my_stack.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    // exp for testing 
    uint8_t exp[] = "({(3)*5})";
    uint8_t exp_1[] = "(2*3+(5/2+(4*3)))";
    uint8_t exp_2[] = "{({2+10}}*11}";
    uint8_t exp_3[] = ")(";
    uint8_t exp_4[] = "}";
    uint8_t exp_5[] = "[";
    uint8_t exp_6[] = "{([])}";

    printf("%s\n", BalancedParentheses(exp));
    printf("should be balanced and it is : %s\n", BalancedParentheses(exp_1));
    printf("should be balanced and it is : %s\n", BalancedParentheses(exp_6));
    printf("should be unbalanced and it is : %s\n ", BalancedParentheses(exp_2));
    printf("should be unbalanced and it is : %s\n ", BalancedParentheses(exp_3));
    printf("exp 4 should be unbalanced and it is : %s\n ", BalancedParentheses(exp_4));
    printf("exp 5should be unbalanced and it is : %s\n ", BalancedParentheses(exp_5));
   
    


    // the following code was just for debugging
    /*
    //   struct My_stack* stack_1 = createStack(10);
    //   push(stack_1,'c');
       // printf(" stack top is %c\n", stack_1->array[stack_1->top]);
     //  push(stack_1,2);
     //   printf(" stack top is %d\n", stack_1->array[stack_1->top]);
     //  push(stack_1,3);
     //   printf(" stack top is %d\n", stack_1->array[stack_1->top]);
     //   pull(stack_1);
       //  printf(" stack top is %d\n", stack_1->array[stack_1->top]);
       */
    return 0;
}

