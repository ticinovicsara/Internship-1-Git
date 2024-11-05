#include <stdio.h>
#include <stdbool.h>

void curr_state(char board[3][3]);
bool isWin(char board[3][3], char player);
bool boardFull(char board[3][3]);
bool fieldTaken(char board[3][3], int choice);

int main(){
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char player = 'X';
    int choice;
    bool endGame = false;

    while(!endGame){
        curr_state(board);

        printf("Player %c, pick a fiel(1 -9): ", player);
        scanf("%d", &choice);

        if(choice < 1 || choice > 9 || fieldTaken(board, choice)){
            printf("wrong move\n");
            continue;
        }

        board[(choice - 1) / 3][(choice - 1) % 3] = player;

        if(isWin(board, player)){
            curr_state(board);
            printf("Player %c is the winner!\n", player);
            endGame = true;
        }
        else if(boardFull(board)){
            curr_state(board);
            printf("Its a tie\n");
            endGame = true;
        }
        else{
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void curr_state(char board[3][3]){
    printf("\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c ", board[i][j]);
            if(j < 2)   printf("|");
        }
        printf("\n");
        if(i < 2)   printf("---|---|---\n");
    }
    printf("\n");
}

bool isWin(char board[3][3], char player){
    for(int i=0; i<3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }
    return false;
}

bool boardFull(char board[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    return true;
}

bool fieldTaken(char board[3][3], int choice){
    return board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O';
}