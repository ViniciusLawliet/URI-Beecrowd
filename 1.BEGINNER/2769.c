/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2769 - Linha de Montagem
 * 
 */

#include <stdio.h>

#define MAXN 1000

long a1[MAXN], a2[MAXN];
long t1[MAXN], t2[MAXN];

int main() {
    
    int n;
    while (scanf("%d", &n) != EOF) {

        long e1, e2, s1, s2;

        scanf("%ld %ld", &e1, &e2);

        int i;
        for(i = 0; i < n; i++) scanf("%ld", &a1[i]);
        for(i = 0; i < n; i++) scanf("%ld", &a2[i]);

        for(i = 0; i < (n-1); i++) scanf("%ld", &t1[i]);
        for(i = 0; i < (n-1); i++) scanf("%ld", &t2[i]);

        scanf("%ld %ld", &s1, &s2);

        long f1 = e1 + a1[0];
        long f2 = e2 + a2[0];

        int j;
        for(j = 1; j < n; j++) {
            long nf1 = (f1 + a1[j] < f2 + t2[j-1] + a1[j]) ?
                            f1 + a1[j] :
                            f2 + t2[j-1] + a1[j];

            long nf2 = (f2 + a2[j] < f1 + t1[j-1] + a2[j]) ?
                            f2 + a2[j] :
                            f1 + t1[j-1] + a2[j];

            f1 = nf1;
            f2 = nf2;
        }

        long ans = (f1 + s1 < f2 + s2) ? f1 + s1 : f2 + s2;

        printf("%ld\n", ans);
    }

    return 0;
}