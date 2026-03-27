/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2867 - Digitos
 * 
 */

#include <stdio.h>
#include <math.h>

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int n, m;
        scanf("%d %d", &n, &m);

        double digits = m * log10(n); 
        /*  log10(n^m) == m * log10(n) 
            [essa mudanca reduz a complexida e o custo de memoria, 
            ao evitar processar e armazenar um numero 100^100] 
        */
        printf("%d\n", (int)digits + 1);
    }

    return 0;
}