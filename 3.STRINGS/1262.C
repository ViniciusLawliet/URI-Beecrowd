/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1262 - Leitura Multipla
 * 
 */

#include <stdio.h>

int main() {

    char str[52];
    while (scanf("%s", str) != EOF) {

        int P;
        scanf("%d", &P);

        int i, p_use, cicles;
        i = cicles = 0;

        while (str[i]) {
            p_use = P;
            if (str[i] == 'W') {cicles++; i++;}
            else {
                cicles++;
                i++;
                p_use--;
                while (str[i] == 'R' && p_use) {
                    i++;
                    p_use--;
                }
            }
        }

        printf("%d\n", cicles);
    }

    return 0;
}