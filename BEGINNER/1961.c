/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1961 - Jumping Frog
 * 
 */

#include <stdio.h>

int abs_local(int x) {
    return (x >= 0) ? x : x * -1;
}

int main() {

    int p, n;
    scanf("%d %d", &p, &n);

    int v[n], i;
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (i = 1; i < n; i++) {

        if (abs_local(v[i] - v[i - 1]) > p)
            break;

    }
    
    (i == n) ? printf("YOU WIN\n") : printf("GAME OVER\n");

    return 0;

}