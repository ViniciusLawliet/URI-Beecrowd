/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1149 - Summing Consecutive Integers
 * 
 */

#include <stdio.h>

int main() {

    int a, n = 0;

    scanf("%d", &a);

    while (n < 1) {
        scanf("%d", &n);
    }

    int s = 0;
    for (; n > 0; n--) {
        s += a++;
    }

    printf("%d\n", s);

    return 0;
}