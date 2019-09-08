/**
 * UVA 10189 - Minesweeper
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1130
 * $ g++ uva10189.c -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
 */

#include <stdio.h>
#define MAX_SIZE 100

int main(void) {
    const char SAFE_SQ = '.';
    const char MINE_SQ = '*';
    int field[MAX_SIZE][MAX_SIZE];
    char buffer[MAX_SIZE + 1];
    int n = 0;
    int m = 0;
    int field_count = 1;
    char c;

    while(scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) {
            break;
        }
        if (field_count > 1) {
            printf("\n");
        }
        printf("Field #%d:\n", field_count++);
        // Read in field.
        for(int j = 0; j < n; j++) {
            scanf("%s", buffer);
            for(int i = 0; i < m; i++) {
                if(buffer[i] == MINE_SQ) {
                    field[j][i] = 1;
                } else if(buffer[i] == SAFE_SQ) {
                    field[j][i] = 0;
                } else {
                    printf("Error: %c read.", buffer[i]);
                    return 1;
                }
            }
        }
        // Count mines.
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                int count = 0;
                for(int y = j - 1; y <= j + 1; y++) {
                    for(int x = i - 1; x <= i + 1; x++) {
                        if(y>=0 && y <n && x>=0 && x<m) {
                            count += field[y][x];
                        }
                    }
                }
                // The center square is improperly counted above.
                //count -= field[j][i];
                if(field[j][i]) {
                    printf("*");
                } else {
                    printf("%d", count);
                }
            }
            printf("\n");
        }
    }
    return 0;
}