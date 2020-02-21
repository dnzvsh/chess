#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char form;
} Figure;

void initial_state()
{
    Figure king[2] = {'K', 'k'};
    Figure queen[2] = {'Q', 'q'};
    Figure bishop[2] = {'B', 'b'};
    Figure knight[2] = {'N', 'n'};
    Figure rook[2] = {'R', 'r'};
    Figure pawn[2] = {'P', 'p'};
    Figure nan = {'0'};
    Figure arr[8][8];
    printf("   1 2 3 4 5 6 7 8\n");
    printf("  ________________\n");
    for (int i = 0; i < 8; i++) {
        printf("%c| ", i + 65);
        for (int j = 0; j < 8; j++) {
            if (((i == 0) && (j == 0)) || ((i == 0) && (j == 7))) {
                arr[i][j] = *rook;
            } else if (((i == 7) && (j == 7)) || ((i == 7) && (j == 0))) {
                arr[i][j] = rook[1];
            } else if (((i == 0) && (j == 1)) || ((i == 0) && (j == 6))) {
                arr[i][j] = *knight;
            } else if (((i == 7) && (j == 6)) || ((i == 7) && (j == 1))) {
                arr[i][j] = knight[1];
            } else if (((i == 0) && (j == 2)) || ((i == 0) && (j == 5))) {
                arr[i][j] = *bishop;
            } else if (((i == 7) && (j == 5)) || ((i == 7) && (j == 2))) {
                arr[i][j] = bishop[1];
            } else if ((i == 0) && (j == 3)) {
                arr[i][j] = *king;
            } else if ((i == 7) && (j == 4)) {
                arr[i][j] = king[1];
            } else if ((i == 0) && (j == 4)) {
                arr[i][j] = *queen;
            } else if ((i == 7) && (j == 3)) {
                arr[i][j] = queen[1];
            } else if (i == 1) {
                arr[i][j] = *pawn;
            } else if (i == 6) {
                arr[i][j] = pawn[1];
            } else {
                arr[i][j] = nan;
            }

            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    initial_state();
    return 0;
}
