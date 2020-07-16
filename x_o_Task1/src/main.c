#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define board_rows 3
#define board_cols 3
 static char board [board_rows][board_cols] ={  { '1',  '2',    '3'}, 
                                                { '4',  '5',    '6'},
                                                { '7',  '8',    '9'} };
static win_flag = 0;
void print_board();
void update_pos(int pos,char side);
char win_check()
{
    //check the first row
    for(int i = 0; i< board_cols-1;i++)
    {
        if (board[0][i]==board[0][i+1])
        {
            win_flag =1;
        }
        else
        {
            win_flag=0;
        }
    }
    if (win_flag){
        return board[0][0];
    }
        //check the second row
    for(int i = 0; i< board_cols-1;i++)
    {
        if (board[1][i]==board[1][i+1])
        {
            win_flag =1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag){
       return board[1][0];
    }
        //check the third row
    for(int i = 0; i< board_cols-1;i++)
    {
        if (board[2][i]==board[2][i+1])
        {
            win_flag =1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag){
        return board[2][0];
    }

        //check the first column
    for(int i = 0; i< board_rows-1;i++)
    {
        if (board[i][0]==board[i+1][0])
        {
            win_flag =1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag){
        return board[0][0];
    }
    //check the 2nd column
    for(int i = 0; i< board_rows-1;i++)
    {
        if (board[i][1]==board[i+1][1])
        {
            win_flag =1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag){
       return board[0][1];
    }

    //check the third column
    for(int i = 0; i< board_rows-1;i++)
    {
        if (board[i][2]==board[i+1][2])
        {
            win_flag =1;
        }
        else
        {
            win_flag=0;
        }
    }

    if (win_flag){
        return board[0][2];
    }

    // check diameters
    if(board[1][1]==board[0][2] && board[1][1]==board[2][0])
    {
         win_flag = 1;
         return board[1][1];
    }

    if(board[1][1]==board[0][0] && board[1][1]==board[2][2])
    {
         win_flag = 1;
         return board[1][1];
    }
    return '0';
}
int main() 
{
   

    print_board();
    printf("win_check return = %c",win_check());
    printf("\n win_flag = %d",win_flag);
    return 0;
}

void print_board(){

    for(int i =0;i<board_rows;i++){
        printf("_______________\n");
        for(int j =0; j<board_cols;j++){
            printf("| %c  ",board[i][j]);
            

        }
         printf("|");

        printf("\n");
    }
}

void update_pos(int pos,char side){

    switch(pos){
        case 1: 
            board[0][0]=side;
            break;
        case 2: 
            board[0][1]=side;
            break;
        case 3: 
            board[0][2]=side;
            break;
        case 4: 
            board[1][0]=side;
            break;
        case 5: 
            board[1][1]=side;
            break;
        case 6: 
            board[1][2]=side;
            break;
        case 7: 
            board[2][0]=side;
            break;
        case 8: 
            board[2][1]=side;
            break;
        case 9: 
            board[2][2]=side;
            break;
    }
}