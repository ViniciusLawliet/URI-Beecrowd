/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1586 - Cabo de Guerra
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;

    while (scanf("%d", &N) == 1 && N) {

        long long *a = (long long *)malloc(sizeof(long long) * N);
        char **names = (char **)malloc(sizeof(char *) * N);

        long long SN = 0;  // soma total
        long long T = 0;   // soma ponderada

        for (int i = 0; i < N; i++) {
            names[i] = (char *)malloc(12 * sizeof(char));

            scanf("%s", names[i]);

            long long sum = 0;
            for (int j = 0; names[i][j] != '\0'; j++) {
                sum += names[i][j];
            }

            a[i] = sum;

            SN += sum;
            T += (long long)(i + 1) * sum;
        }

        long long Sp = 0;
        int found = -1;

        /*
            Sp = a1 + a2 + ... + ap
            SN = a1 + a2 + ... + aN
            T  = 1*a1 + 2*a2 + ... + N*aN
        */

        for (int p = 0; p < N; p++) {
            Sp += a[p];

            /* pos estudante = p+1 */
            if (Sp == T - (long long)(p + 1) * SN) {
                found = p;
                break;
            }
        }

        if (found == -1)
            printf("Impossibilidade de empate.\n");
        else
            printf("%s\n", names[found]);

        for (int i = 0; i < N; i++) {
            free(names[i]);
        }

        free(names);
        free(a);
    }

    return 0;
}