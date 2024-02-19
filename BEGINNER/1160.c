/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1160 - Population Increase
 * 
 */

#include <stdio.h>

int main() {

    int t, c;
    scanf("%d", &t);

    long int pa, pb;
    double g1, g2;

    while (t) {

        t--;

        scanf("%li %li %lf %lf", &pa, &pb, &g1, &g2);

        c = 0;
        while (pa <= pb && c < 101) {
            pa += ((pa * g1) / 100);
            pb += ((pb * g2) / 100);

            c++;
        }

        (c > 100) ? printf("Mais de 1 seculo.\n") : printf("%d anos.\n", c);

    }
    

    return 0;
}