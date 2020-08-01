#include <stdio.h>
//#include <stdbool.h>
#include <stdlib.h>
#include "x_o.h"

#define BOARD_ROWS 3
#define BOARD_COLS 3
#define BOARD_SIZE 9

static char win_flag = 0;
static char filled = 0;
static char retake_input = 0; // when user choose used location this flag will be one

static char board [BOARD_ROWS][BOARD_COLS] ={   { '1',  '2',    '3'}, 
                                                { '4',  '5',    '6'},
                                                { '7',  '8',    '9'} };

void print_board();
void update_pos(int pos,char side);
char win_check();

int main() 
{   
    static char player_1,player_2;
    char pos;
    char win ;
    
    printf("please choose side ( x or o ):\n");
    scanf("%c",&player_1);
    if(player_1 == 'x')
    {
        player_2 ='o';
    }
    else 
    {
        player_1 ='o';
        player_2 ='x';
    }
    printf("user 1 --- %c",player_1);
    printf("\nuser 2 --- %c\n",player_2);
    print_board();

    while(!(win_flag)){
    
    printf("user 1 --- please choose location :\n");
    scanf("%d",&pos);

    update_pos(pos,player_1);
    
   
    print_board();
    while(retake_input > 0)
    {
        printf("user 1 --- please choose location :\n");
        scanf("%d",&pos);
        update_pos(pos,player_1);
        print_board();
    }
    
    
    win =win_check();
    if (win == player_1)
    {
        printf("user 1 --- %c : is the winner  \n",player_1);
        return 0;
    }
   
    if(filled == BOARD_SIZE)
    {
        printf("\n Draw !!!  :\n");
        return 0;
    }

    printf("user 2 --- please choose location :\n");
    scanf("%d",&pos);

    update_pos(pos,player_2);
    
 
    print_board();

    while(retake_input > 0)
    {
        printf("user 2 --- please choose location :\n");
        scanf("%d",&pos);
        update_pos(pos,player_2);
        print_board();
    }
    win =win_check();
    if (win == player_2)
    {
        printf("user 2 --- %c : is the winner  :\n",player_2);
        return 0;
    }
  
    }

    //i have used the two line below for testing
   // printf("win_check return = %c",win_check());
   // printf("\n win_flag = %d",win_flag);
   system("pause");
    return 0;
}












// just to print board

void print_board(){

    for(int i =0;i<BOARD_ROWS;i++){
        printf("_______________\n");
        for(int j =0; j<BOARD_COLS;j++){
            printf("| %c  ",board[i][j]);
            

        }
         
         printf("|\n");

        
    }
    printf("_______________\n");
}


//to update board with new inputs

void update_pos(int pos,char side){

    retake_input = 0;

    switch(pos){
        case 1: 
            if(board[0][0]=='x' || board[0][0]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            }
            
            board[0][0]=side;
            filled +=1;
            break;
        
        case 2: 
            if(board[0][1]=='x' || board[0][1]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            }
            board[0][1]=side;
            filled +=1;
            break;
        
        case 3:
            if(board[0][2]=='x' || board[0][2]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            } 
            board[0][2]=side;
            filled +=1;
            break;
        
        case 4:
            if(board[1][0]=='x' || board[1][0]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            } 
            board[1][0]=side;
            filled +=1;
            break;
       
        case 5:
            if(board[1][1]=='x' || board[1][1]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            } 
         
            board[1][1]=side;
            filled +=1;
            break;
        
        case 6:
             if(board[1][2]=='x' || board[1][2]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            }  
            board[1][2]=side;
            filled +=1;
            break;
        
        case 7:
             if(board[2][0]=='x' || board[2][0]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            }  
            board[2][0]=side;
            filled +=1;
            break;
        
        case 8: 
             if(board[2][1]=='x' || board[2][1]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            } 
            board[2][1]=side;
            filled +=1;
            break;
        
        case 9: 
             if(board[2][2]=='x' || board[2][2]=='o')
            {
                printf("action not allowed try again !!!\n");
                retake_input = 1;
                break;
            } 
            board[2][2]=side;
            filled +=1;
            break;

        default:
                printf("enter a valid location num_range [1:9]\n");
    }
}



//to check winning state
char win_check()
{
    //check the first row
    for(int i = 0; i< BOARD_COLS-1;i++)
    {
        if (board[0][i]==board[0][i+1])
        {
            win_flag +=1;
        }
        else
        {
            win_flag=0;
        }
    }
    if (win_flag==2){
        return board[0][0];
    }
        //check the second row
    for(int i = 0; i< BOARD_COLS-1;i++)
    {
        if (board[1][i]==board[1][i+1])
        {
             win_flag +=1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag==2){
       return board[1][0];
    }
        //check the third row
    for(int i = 0; i< BOARD_COLS-1;i++)
    {
        if (board[2][i]==board[2][i+1])
        {
             win_flag +=1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag==2){
        return board[2][0];
    }

        //check the first column
    for(int i = 0; i< BOARD_ROWS-1;i++)
    {
        if (board[i][0]==board[i+1][0])
        {
             win_flag +=1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag==2){
        return board[0][0];
    }
    //check the 2nd column
    for(int i = 0; i< BOARD_ROWS-1;i++)
    {
        if (board[i][1]==board[i+1][1])
        {
             win_flag +=1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag == 2){
       return board[0][1];
    }

    //check the third column
    for(int i = 0; i< BOARD_ROWS-1;i++)
    {
        if (board[i][2]==board[i+1][2])
        {
             win_flag +=1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag==2){
        return board[0][2];
    }

    // check diameters
    if(board[1][1]==board[0][2] && board[1][1]==board[2][0])
    {
         win_flag = 2;
         return board[1][1];
    }

    if(board[1][1]==board[0][0] && board[1][1]==board[2][2])
    {
         win_flag = 2;
         return board[1][1];
    }
    return '0';
}