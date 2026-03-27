/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2782 - Escadinha
 * 
 */

#include <stdio.h>

int main() {

    int N;
    scanf("%d", &N);

    int x, anterior, count = 1;
    scanf("%d", &x);

    int i, distancia;
    for (i = 1; i < N; i++) {
        anterior = x;
        scanf("%d", &x);
        if ((anterior - x) != distancia && i > 1) { count++; }
        distancia = (anterior - x);
    }

    printf("%d\n", count);

    return 0;
}