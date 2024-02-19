/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1973 - Star Trek
 * 
 */

#include <stdio.h>

int main () {

    int n;
    scanf("%d", &n);

    int v[n], i;
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

    return 0;

}