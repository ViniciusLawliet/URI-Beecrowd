/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2718 - Luzes de Natal
 * 
 */

#include <stdio.h>
#include <stdint.h>

int main(void) {

    int N;
    scanf("%d", &N);

    while (N--) {
        unsigned long long x;
        scanf("%llu", &x);

        int best = 0, cur = 0;
        // percorre do bit mais significativo (49) ao menos significativo (0)
        for (int i = 49; i >= 0; --i) { // 50 lampadas?
            if ((x >> i) & 1ULL) {
                cur++;
            } else {
                if (cur > best) best = cur;
                cur = 0;
            }
        }
        if (cur > best) best = cur;

        printf("%d\n", best);
    }
    return 0;
}