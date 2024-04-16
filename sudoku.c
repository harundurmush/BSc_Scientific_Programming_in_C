#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define GRID_SIZE 9
void printBoard(int board[GRID_SIZE][GRID_SIZE]){
	int row,column;
	for(row=0;row<GRID_SIZE;row++){
		if(row%3==0 && row!=0){
			printf("-----------\n");
		}
		for(column=0;column<GRID_SIZE;column++){
			if(column%3==0 && column!=0){
				printf("|");
			}
			printf("%d",board[row][column]);
		}
		printf("\n");
	}
}
int isNumberInRow(int board[GRID_SIZE][GRID_SIZE], int number, int row){
	int i;
	for(i=0;i<GRID_SIZE;i++){
		if(board[row][i]==number){
			return TRUE;
		}
	}
	return FALSE;
}
int isNumberInColumn(int board[GRID_SIZE][GRID_SIZE], int number, int column){
	int i;
	for(i=0;i<GRID_SIZE;i++){
		if(board[i][column]==number){
			return TRUE;
		}
	}
	return FALSE;
}
int isNumberInBox(int board[GRID_SIZE][GRID_SIZE], int number, int row, int column){
	int localBoxRow = row - row % 3;
	int localBoxColumn = column - column % 3;
	int i,j;
	for(i=localBoxRow;i<localBoxRow+3;i++){
		for(j=localBoxColumn;j<localBoxColumn+3;j++){
			if(board[i][j]==number){
				return TRUE;
			}
		}
	}
	return FALSE;
}
int isValidPlacement(int board[GRID_SIZE][GRID_SIZE],int number,int row,int column){
	return !isNumberInRow(board,number,row) && !isNumberInColumn(board,number,column) && isNumberInBox(board,number,row,column);
}
int solveBoard(int board[GRID_SIZE][GRID_SIZE]){
	int row,column,numberToTry;
	for(row=0;row<GRID_SIZE;row++){
		for(column=0;column<GRID_SIZE;column++){
			if(board[row][column]==0){
				for(numberToTry=1;numberToTry<=GRID_SIZE;numberToTry++){
					if(isValidPlacement(board,numberToTry,row,column)){
						board[row][column]=numberToTry;
						if(solveBoard(board)){
							return TRUE;
						}
						else{
							board[row][column]=0;
						}
					}
				}
				return FALSE;
			}
		}
	}
	return TRUE;
}
void main(){
	int board[GRID_SIZE][GRID_SIZE]={
        {7, 0, 2, 0, 5, 0, 6, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0},
        {1, 0, 0, 0, 0, 9, 5, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 9, 0},
        {0, 4, 3, 0, 0, 0, 7, 5, 0},
        {0, 9, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 9, 7, 0, 0, 0, 0, 5},
        {0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 4, 0, 2, 0, 3} 
      };
	   printBoard(board);
	   printf("\nSolution is:\n\n");
	   solveBoard(board);
	   printBoard(board);
	   
}

