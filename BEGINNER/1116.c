/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1116 - Dividing X by Y
 * 
 */

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int x, y;
    while(n) {
        n--;
        scanf("%d %d", &x, &y);

        if(!y)
            printf("divisao impossivel\n");
        else 
            printf("%0.1f\n", (x*1.0)/y);

    }

    return 0;
}