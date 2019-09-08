/**
 * UVA100 - 3n+1 Problem
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
 * $ g++ uva100.c -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
 */

#include <stdio.h>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int main(void) {
    int num1, num2;
    // Read input
    while(scanf("%d %d", &num1, &num2) != EOF) {
        int start = MIN(num1, num2);
        int stop = MAX(num1, num2);
        int max_len = 0;
        // Find cycle lengths for all numbers between num1 and num2.
        for(int i=start; i <=stop; i++) {
            int len = 1;
            int j = i;
            while(j != 1) {
                if (j % 2 == 0) {
                    j = j / 2;
                } else {
                    j = (j * 3) + 1;
                }
                len++;
            }
            if (len > max_len) {
                max_len = len;
            }
        }
        printf("%d %d %d\n", num1, num2, max_len);
    }
}