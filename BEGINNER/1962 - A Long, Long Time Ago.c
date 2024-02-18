#include <stdio.h>

int main () {

    int n, t;
    scanf("%d", &n);

    while (n) {

        n--;
        scanf("%d", &t);

        t -= 2015;

        (t < 0) ? printf("%d D.C.\n", t *= -1) : printf("%d A.C.\n", ++t);

    }

    return 0;

}