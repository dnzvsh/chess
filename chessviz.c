#include <stdio.h>
#include <ctype.h>

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
}

void print_board(char chess[][8])
{
    printf("   A B C D E F G H\n   _______________\n");
    for (int i = 0; i < 8; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", chess[i][j]);
        }
        printf("\n");
    }
}

void char_to_board(char* sdt, int* wturn)
{
    for (int j = 0; j < 4; j++) {
        printf("%d ", sdt[j]);
    }
    printf("\n");
    for (int i = 0; i < 12; i++) {
        int char1;
        if (sdt[i] == '\0')
            break;
        if (isalpha(sdt[i]) != 0) {
            char1 = (int)sdt[i] - 97;
        }
        if (isdigit(sdt[i]) != 0) {
            char1 = (int)sdt[i] - 49;
        }
        wturn[i] = char1;
    }
}

void* scan_turn(char* sdt, int* wturn)
{
    scanf("%c%c-%c%c", &sdt[0], &sdt[1], &sdt[2], &sdt[3]);
    sdt[4] = '\n';
    char_to_board(sdt, wturn);
    printf("\nfrom %d %d\n", wturn[0], wturn[1]);
    printf("  to %d %d\n", wturn[2], wturn[3]);
}

int check_from(char board[][8], int* wturn)
{
    if (board[wturn[1]][wturn[0]] == ' ') {
        return -1;
    }
    return 0;
}

int main()
{
    char chess[8][8] = {{' '}};
    initial_board(chess);
    print_board(chess);
    char sdt[12];
    int wturn[4];
    scan_turn(sdt, wturn);
    return 0;
}
