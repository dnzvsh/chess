#include <ctype.h>
#include <stdio.h>

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void fill_chess(char chess[][8]){
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
    chess[7][3] = 'q';
    chess[7][4] = 'k';
    chess[7][5] = 'b';
    chess[7][6] = 'n';
    chess[7][7] = 'r';
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }}
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

//Проверка максимального хода для пешки
int check_pawn(char board[][8], int* wturn)
{
    int max_turn;
    if (wturn[1] == 1) {
        max_turn = 2;
    } else
        max_turn = 1;
    int count = 0;
    for (int i = 1; i <= wturn[3]; i++) {
        if (board[wturn[1]][i + wturn[0]] == ' ') {
            count++;
        }
    }
    if (!count && wturn[0] == wturn[2]) {
        if (wturn[3] - wturn[1] <= max_turn && wturn[3] > wturn[1]) {
            swap(&board[wturn[1]][wturn[0]], &board[wturn[3]][wturn[2]]);
            return 0;
        }
    }
    printf("\ncan't move like that)))))\n");
    return 1;
}
//Запись хода
void scan_turn(char* sdt, int* wturn)
{
    scanf("%c%c-%c%c", &sdt[0], &sdt[1], &sdt[2], &sdt[3]);
    sdt[4] = '\n';
    char_to_board(sdt, wturn);
    printf("\nfrom %d %d\n", wturn[0], wturn[1]);
    printf("  to %d %d\n", wturn[2], wturn[3]);
}

//Проверка находится ли фигура в положении "откуда"
int check_from(char board[][8], int* wturn)
{
    if (board[wturn[1]][wturn[0]] == ' ') {
        return -1;
    }
    return 0;
}

//Проверка есть ли свободное место в положении "куда"
int check_to(char board[][8], int* wturn)
{
    if (board[wturn[3]][wturn[2]] == ' ') {
        return 0;
    }
    return -1;
}

int main()
{
    char chess[8][8] = {{' '}};
    fill_chess(chess);
    print_board(chess);
    char sdt[12];
    int wturn[4];
    scan_turn(sdt, wturn);
    int flag_from = check_from(chess, wturn);
    if (flag_from == -1) {
        printf("\nWrong format input\n");
    }
    int flag_to = check_to(chess, wturn);
    if (flag_to == -1) {
        printf("\nCan't move here\n");
    }
    if (!flag_from && !flag_to) {
        check_pawn(chess, wturn);
    }
    print_board(chess);

    return 0;
}
