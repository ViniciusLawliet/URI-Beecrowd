/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2313 - Which Triangle
 * 
 */

#include <stdio.h>

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

#define triangulo(a,b,c) ((a)+(b)>(c)&&(b)+(c)>(a)&&(a)+(c)>(b))?1:0
#define retangulo(a,b,c) ((a)*(a))==((b)*(b)+(c)*(c))?1:0

int main() {

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (triangulo(a, b, c)) {
        printf("Valido-");

        if (a == b && b == c)
            printf("Equilatero\n");
        else if (a != b && b != c && a != c)
            printf("Escaleno\n");
        else
            printf("Isoceles\n");

        int hip = max(a, max(b, c));
        int cat = min(a, min(b, c));
        int cat2 = (a + b + c) - hip - cat;

        printf("Retangulo: %c\n", (retangulo(hip, cat, cat2)) ? 'S' : 'N');

    } else {
        printf("Invalido\n");
    }

    return 0;
}