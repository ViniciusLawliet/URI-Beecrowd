/**
 * @author vinicius lawliet
 * @brief
 * @version 0.1
 * 
 * @problem: 1803 - Matring
 * 
*/

#include <stdio.h>
#include <string.h>

char matring[4][82];

int main() {

    for (int i = 0; i < 4; ++i) {
        scanf("%s", matring[i]);
    }

    int n = strlen(matring[0]);

    int F, L;
    F = L = 0;
    for (int i = 0, mul = 1000; i < 4; ++i) {
        F += (int)(matring[i][0] - '0')   * mul;
        L += (int)(matring[i][n-1] - '0') * mul;
        mul /= 10;
    }

    for (int j = 1; j < n-1; ++j) {
        int num = 0;
        for (int i = 0, mul = 1000; i < 4; ++i) {
            num += (int)(matring[i][j] - '0') * mul;
            mul /= 10;
        }
        putchar((F * num + L) % 257);
    }
    putchar('\n');

    return 0;
}