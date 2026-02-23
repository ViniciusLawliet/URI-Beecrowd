/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1024 - Criptografia
 * 
 */

#include <stdio.h>

char str[1024];

int main() {

    int N;
    scanf("%d", &N);

    while (N--) {
        scanf(" %[^\n]", str);

        int i;
        for (i = 0; str[i] != '\0'; i++) {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                str[i] = (char)(str[i] + 3);
            }
        }

        int metade = i/2;

        int d = 0;
        for (--i; d < metade; d++, i--) {
            putchar(str[i]);
        }

        for (; i >= 0; i--) {
            putchar(str[i] - 1);
        }

        putchar('\n');
    }

    return 0;
}