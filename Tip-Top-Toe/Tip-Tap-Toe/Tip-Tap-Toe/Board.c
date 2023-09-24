#include <stdio.h>
#include "tictactoe.h"

char board[3][3] = { {'_', '_', '_'},
                     {'_', '_', '_'},
                     {'_', '_', '_'} };

void print_board() {
    printf("|%c|%c|%c|\n", board[0][0], board[0][1], board[0][2]);
    printf("|%c|%c|%c|\n", board[1][0], board[1][1], board[1][2]);
    printf("|%c|%c|%c|\n", board[2][0], board[2][1], board[2][2]);
}

int check_win() {
    int i, j;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_') {
            return 1;
        }
    }
    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '_') {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_') {
        return 1;
    }
    return 0;
}
int main() {
    char input[2];
    int row, col;
    int player = 1;
    printf("The Square is\n");
    printf("QWE\n");
    printf("ASD\n");
    printf("ZXC\n");
    while(1) {
        printf("Player %d's turn. Where should we place %c? ", player, player == 1 ? 'X' : 'O');
        scanf("%s", input);
        switch(input[0]) {
            case 'q':
                row = 0;
                col = 0;
                break;
            case 'w':
                row = 0;
                col = 1;
                break;
            case 'e':
                row = 0;
                col = 2;
                break;
            case 'a':
                row = 1;
                col = 0;
                break;
            case 's':
                row = 1;
                col = 1;
                break;
            case 'd':
                row = 1;
                col = 2;
                break;
            case 'z':
                row = 2;
                col = 0;
                break;
            case 'x':
                row = 2;
                col = 1;
                break;
            case 'c':
                row = 2;
                col = 2;
                break;
            default:
                printf("Invalid input. Please enter a valid input.\n");
                continue;
        }
        if (board[row][col] != '_') {
            printf("That spot is already taken. Please choose another spot.\n");
            continue;
        }
        board[row][col] = player == 1 ? 'X' : 'O';
        print_board();
        if (check_win()) {
            printf("Player %d wins!\n", player);
            return 0;
        }
        // Check for tie
        if (board[0][0] != '_' && board[0][1] != '_' && board[0][2] != '_' &&
            board[1][0] != '_' && board[1][1] != '_' && board[1][2] != '_' &&
            board[2][0] != '_' && board[2][1] != '_' && board[2][2] != '_') {
            printf("It's a tie!\n");
            return 0;
        }
        // Switch players
        player = player == 1 ? 2 : 1;
    }
    return 0;
}