/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2724 - Ajude Patatatitu
 * 
 */

#include <stdio.h>
#include <string.h>

#define _MAX 51

char compostos_p[_MAX][_MAX];

int main() {

    int N;
    scanf("%d", &N);

    while(N--) {

        int i, j;

        // Entrada de compostos perigosos
        int T;
        scanf("%d", &T);
        for (i = 0; i < T; i++) {
            scanf("%s", &compostos_p[i]);
        }

        // Entrada das experiencias
        int U;
        scanf("%d", &U);
        for (i = 0; i < U; i++) {
            char experiencia[_MAX];
            scanf("%s", experiencia);
            
            // Talvez uma Trie fosse uma alternativa mais inteligente!
            // https://en.wikipedia.org/wiki/Trie
            // https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm
            int perigo = 0;
            char *ret;
            for (j = 0; j < T; j++) {
                ret = strstr(experiencia, compostos_p[j]);
                if (ret != NULL) {

                    // VERIFICACAO ADICIONAL DO TERMINADOR "ClF312" != "ClF3"
                    char end = ret[strlen(compostos_p[j])];
                    /*printf("string = %s\n", ret);
                    printf("terminator = %c\n", end);*/

                    if ((end >= '0' && end <= '9') || (end >= 'a' && end <= 'z')) {
                        continue;
                    }

                    perigo = 1;
                    break;       // early-exit

                }
            }

            printf("%s\n", (perigo) ? "Abortar" : "Prossiga");
        }
        if (N) printf("\n"); // PRESENTATION ERROR NO ULTIMO CASO DE TESTE?
    }

    return 0;
}