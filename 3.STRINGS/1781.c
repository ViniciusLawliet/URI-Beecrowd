/**
 * @author vinicius lawliet
 * @brief Preprocesses vowel and consonant positions and applies lazy cyclic shifts.
 * @version 0.1
 * 
 * @problem: 1781 - Guga e a String
 * 
*/

#include <stdio.h>

#define MAX_VETOR 10000

int posV[MAX_VETOR];
int posC[MAX_VETOR];

char vogais[MAX_VETOR];
char consoantes[MAX_VETOR];

int ehVogal(char c) {
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main() {

    int T;
    scanf("%d", &T);

    char str[MAX_VETOR + 1];
    char ans[MAX_VETOR + 1];

    for (int caso = 1; caso <= T; caso++) {

        printf("Caso #%d:\n", caso);

        scanf("%s", str);

        int nv = 0;
        int nc = 0;

        // pre-processamento
        for (int i = 0; str[i]; i++) {

            if (ehVogal(str[i])) {
                posV[nv] = i;
                vogais[nv++] = str[i];
            }
            else {
                posC[nc] = i;
                consoantes[nc++] = str[i];
            }
        }

        int offsetV = 0;
        int offsetC = 0;

        int Q;
        scanf("%d", &Q);

        while (Q--) {

            int op;
            scanf("%d", &op);

            if (op == 2) {

                // copia string original
                int i;
                for (i = 0; str[i]; i++) ans[i] = str[i];
                ans[i] = '\0';

                // recoloca vogais
                for (i = 0; i < nv; i++) {
                    ans[posV[i]] = vogais[(i - offsetV + nv) % nv];
                }

                // recoloca consoantes
                for (i = 0; i < nc; i++) {
                    ans[posC[i]] = consoantes[(i - offsetC + nc) % nc];
                }

                printf("%s\n", ans);
            }
            else {

                int deslocamento;
                scanf("%d", &deslocamento);

                if (op == 0 && nv)
                    offsetV = (offsetV + deslocamento) % nv;

                else if (op == 1 && nc)
                    offsetC = (offsetC + deslocamento) % nc;
            }
        }
    }

    return 0;
}