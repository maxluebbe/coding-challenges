/**
 * UVA 10137 - The Trip
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1078
 * $ g++ uva10137.c -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
 */

#include <math.h>
#include <stdio.h>

int main(void) {
    const int MAX_STUDENTS = 1000;
    int n = 0;
    int amounts[MAX_STUDENTS];
    
    while(scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        int dollars = 0;
        int cents = 0;
        char sep;
        int ceil_avg, average_cents = 0;
        int under = 0;
        int over = 0;
        int exchange = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%c%d", &dollars, &sep, &cents);
            amounts[i] = dollars * 100 + cents;
            average_cents += amounts[i];
        }
        // This is the not-obvious special case!
        // Depending on n and the amount to be divided, we need to check
        // if rounding up or down to the nearest cent is more efficient.
        ceil_avg = ceil(1.0 * average_cents / n);
        average_cents /= n;
        for (int i = 0; i < n; i++) {
            if(amounts[i] > ceil_avg) {
                over += amounts[i] - ceil_avg;
            }
            else if (amounts[i] < average_cents) {
                under += average_cents - amounts[i];
            }
        }
        exchange = over;
        if (under > over) {
            exchange = under;
        }
        printf("$%d.%02d\n", exchange / 100, exchange % 100);
    }
    return 0;
}