// column gets added by one, we check for rows

#include<bits/stdc++.h>
using namespace std;

#define N 4
int board[N][N];

void printBoard(int board[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int row, int col){

    // will not allow to place queen in same row
    for(int i=0; i<col; i++){
        if(board[row][i] == 1){
            return false;
        }
    }

    // checks for upper left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    // check for lower left diagonal
    for(int i=row, j=col; i<N && j>=0; i++, j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}

bool solveRec(int col){
    if(col == N){
        return true;
    }

    for(int i=0; i<N; i++){
        if(isSafe(i, col)){
            board[i][col] = 1;
            if(solveRec(col + 1)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

int main(){
    if(!solveRec(0)){
        cout<<"Solution does not exists";
    }
    printBoard(board);
}