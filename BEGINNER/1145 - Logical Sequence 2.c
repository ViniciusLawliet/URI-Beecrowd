#include <stdio.h>

int main() {

    int x, y;
    scanf("%d %d", &x, &y);

    int i, j;
    for (i = 1; i <= y; i += x) {
        for(j = 0; j < (x-1); j++) {
            printf("%d ", i+j);
        }
        printf("%d\n", i+j);
    }

    return 0;
}