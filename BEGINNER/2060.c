/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2060 - Bino's Challenge
 * 
 */

#include <stdio.h>

int main () {

    int n, x, m[4] = {0};
    scanf("%d", &n);

    int i, j;
    for (i = 0; i < n; i++) {

        scanf("%d", &x);

        for (j = 2; j <= 5; j++) {
            if (!(x % j))
                m[j-2]++;
        }

    }

    for (j = 2; j <= 5; j++) 
        printf("%d Multiplo(s) de %d\n", m[j-2], j);
    
    return 0;

}