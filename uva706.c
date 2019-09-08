#include <stdio.h>

int main(void) {
    const int MAX_DIGITS = 8;
    const int MAX_S = 10;
    char buffer[MAX_DIGITS * MAX_S + 1]; // Extra char is for '\n'.
    int s;
    char num[MAX_S + 1];
    while(scanf("%d %s", &s, num) != EOF) {
        int rows = 2 * s + 3;
        for (int i = 0; i < rows; i++) {
            char *p = num;
            // Build buffer for each row then print it.
            // If row == 0, rows/2, rows -1 its a horizontal.
            // Elseif row < rows/2 top vertical
            // else bottom half vertical.
            while(*p) {
                printf("%c\n", *(p++));
            }
        }
        // Each number is followed by a blank line.
        printf("\n");
    }
    return 0;
}