/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1074 - Even or Odd
 * 
 */

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    long int x;
    for (int i = 0; i < n; i++) {

        scanf("%li", &x);

        if (!x) {
            printf("NULL\n");
            continue;
        }

        (x & 1) ? printf("ODD") : printf("EVEN"); 
        (x > 0) ? printf(" POSITIVE\n") : printf(" NEGATIVE\n");

    }

    return 0;
}