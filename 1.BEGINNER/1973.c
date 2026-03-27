/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.2
 * 
 * problem: 1973 - Star Trek
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main () {

    int n;
    scanf("%d", &n);

    int i, *v;
    v = (int *)malloc(n * sizeof(int));
    long long unsigned s = 0;
    for (i = 0; i < n; i++) {

        scanf("%d", &v[i]);
        s += v[i];

    }

    int c = 0;
    for (i = 0; i > -1 && i < n;) {

        if (i > c)
            c = i;

        if (!v[i])
            break;
        
        v[i]--;
        s--;

        ((v[i] + 1) & 1) ? i++ : i--;

    }

    printf("%d %llu\n", ++c, s);
    free(v);

    return 0;

}