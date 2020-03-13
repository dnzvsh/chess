#include <stdio.h>

void initial_board(char chess[][8])
{
    chess[0][0] = 'R';
    chess[0][1] = 'N';
    chess[0][2] = 'B';
    chess[0][3] = 'K';
    chess[0][4] = 'Q';
    chess[0][5] = 'B';
    chess[0][6] = 'N';
    chess[0][7] = 'R';
    for (int i = 0; i < 8; i++) {
        chess[1][i] = 'P';
        chess[6][i] = 'p';
    }
    chess[7][0] = 'r';
    chess[7][1] = 'n';
    chess[7][2] = 'b';
    chess[7][3] = 'k';
    chess[7][4] = 'q';
    chess[7][5] = 'b';
    chess[7][6] = 'n';
    chess[7][7] = 'r';
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    printf("   A B C D E F G H\n   _______________\n");
    for (int i = 0; i < 8; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", chess[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char chess[8][8] = {{' '}};
    initial_board(chess);
    return 0;
}