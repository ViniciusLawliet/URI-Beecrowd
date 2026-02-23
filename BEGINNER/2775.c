/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2775 - Preparando a Producao
 * 
 */

#include <stdio.h>

#define MAXN 1000

int prod[2][MAXN];

int main() {

    int n;
    while (scanf("%d", &n) != EOF) {
        
        int i;
        for (i = 0; i < n; i++) {scanf("%d", &prod[0][i]);}
        for (i = 0; i < n; i++) {scanf("%d", &prod[1][i]);}

        long time = 0;

        // Bubble? Para 1000 elementos no Pior Caso O(N²) isso vai ser um problema.
        // Existem alternativas mais eficientes... Mas... as entradas do URI foram gentis.
        int change;
        for (int i = 0; i < n - 1; i++) {
            change = 0;

            for (int j = 0; j < n - 1 - i; j++) {
                if (prod[0][j] > prod[0][j + 1]) {

                    int temp = prod[0][j];
                    prod[0][j] = prod[0][j + 1];
                    prod[0][j + 1] = temp;

                    temp = prod[1][j];
                    prod[1][j] = prod[1][j + 1];
                    prod[1][j + 1] = temp;

                    time += (temp + prod[1][j]);

                    change = 1;
                }
            }

            if (!change)
                break;

        }

        printf("%ld\n", time);
    }

    return 0;
}