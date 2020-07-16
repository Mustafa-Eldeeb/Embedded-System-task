#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "x_o.h"





int main() 
{
   

    print_board();
    printf("win_check return = %c",win_check());
    printf("\n win_flag = %d",win_flag);
    return 0;
}


