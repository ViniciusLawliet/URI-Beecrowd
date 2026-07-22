/**
 * @author vinicius lawliet
 * @brief Frequency counting using a 128x128 matrix.
 * @version 0.1
 * 
 * problem: 1737 - Etaoin Shrdlu
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char a, b;
    int freq;
} Digraph;

Digraph v[9025];
int freq[128][128];

int comp(const void *p1, const void *p2) {
    const Digraph *a = p1;
    const Digraph *b = p2;

    if (a->freq != b->freq) return b->freq - a->freq;
    if (a->a != b->a) return a->a - b->a;

    return a->b - b->b;
}

int main() {

    int n;

    while (scanf("%d", &n) == 1 && n != 0) {

        memset(freq, 0, sizeof(freq)); // zerar matriz

        getchar(); // consome o '\n'

        char line[82];

        int total = 0;
        int first = 1;
        unsigned char last;

        while (n--) {

            fgets(line, sizeof(line), stdin);

            int len = strlen(line);

            if (line[len - 1] == '\n') line[--len] = '\0';

            for (int i = 0; i < len; i++) {

                unsigned char c = line[i];

                if (!first) {
                    freq[last][c]++;
                    total++;
                }

                last = c;
                first = 0;
            }
        }

        //printf("Total de digrafos: %d\n", total);

        int m = 0;
        for (int i = 32; i <= 126; i++) {
            for (int j = 32; j <= 126; j++) {
                if (freq[i][j]) {
                    //printf("%c%c -> %d\n", i, j, freq[i][j]);
                    v[m].a = i;
                    v[m].b = j;
                    v[m].freq = freq[i][j];
                    m++;
                }
            }
        }

        qsort(v, m, sizeof(v[0]), comp);

        for (int i = 0; i < 5; ++i) {
            printf("%c%c %d %0.6f\n", v[i].a, v[i].b, v[i].freq, (double)v[i].freq/total);
        }

        puts("");
    }

    return 0;
}