
#ifndef _X_O.H
#define _X_O.H

#define board_rows 3
#define board_cols 3
 static char board [board_rows][board_cols] ={  { '1',  '2',    '3'}, 
                                                { '4',  '5',    '6'},
                                                { '7',  '8',    '9'} };
static char win_flag = 0;

void print_board();
void update_pos(int pos,char side);
char win_check();



#endif