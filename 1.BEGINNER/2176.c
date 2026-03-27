/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2176 - Parity
 * 
 */

#include <stdio.h>

int main() {

    char bit[102];
    scanf("%s", bit);

    int i, c;
    for(i = c = 0; bit[i]; i++) {
        if (bit[i] == '1')
            c++;
    }
    bit[i++] = (c & 1) ? '1' : '0';
    bit[i] = '\0';

    printf("%s\n", bit);

    return 0;

}