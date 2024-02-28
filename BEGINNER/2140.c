/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2140 - Two Bills
 * 
 */

#include <stdio.h>

int main () {

    int n, m, bills[] = {100, 50, 20, 10, 5, 2};

    while (1) {
        scanf("%d %d", &n, &m);

        if (!n && !m)
            break;

        m -= n;

        int i, c;
        for (i = c = 0; m && i < 6; i++) {
            if (m / bills[i]) {
                m -= bills[i];
                c++;
            }
        }

        (!m && c == 2) ? printf("possible\n") : printf("impossible\n");

    }

    return 0;
}