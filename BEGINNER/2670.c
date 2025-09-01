/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2670 - Maquina de Cafe
 * 
 */

#include <stdio.h>

#define Min(a,b) (((a)<(b)) ? (a):(b))

int main() {

    int a1, a2, a3;
    scanf("%d %d %d", &a1, &a2, &a3);

    int c1, c2, c3;
    c1 = (a2 << 1) + (a3 << 2);
    c2 = (a1 << 1) + (a3 << 1);
    c3 = (a1 << 2) + (a2 << 1); 

    printf("%d\n", Min(c1,Min(c2,c3)));

    return 0;
}