/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1551 - Frase Completa
 * 
 */

#include <stdio.h>

int main() {

    char str[1024];

    int N;
    scanf("%d", &N);
    getchar();

    while (N--) {

        fgets(str, sizeof str, stdin);

        unsigned int mask = 0;
        int count = 0;

        for (int i = 0; str[i] && count < 26; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {

                unsigned int bit = 1u << (str[i] - 'a');

                if (!(mask & bit)) {
                    mask |= bit;
                    count++;
                }
            }
        }

        if (count == 26) {
            printf("frase completa\n");
        } else if (count >= 13) {
            printf("frase quase completa\n");
        } else {
            printf("frase mal elaborada\n");
        }
    }

    return 0;
}