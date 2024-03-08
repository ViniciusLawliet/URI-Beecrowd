/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2167 - Engine Failure
 * 
 */

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int rpm, p_rpm, fall = 0;
    scanf("%d", &p_rpm);

    for (int i = 2; i <= n; i++) {

        scanf("%d", &rpm);

        if (p_rpm > rpm && !fall) 
            fall = i;

        p_rpm = rpm;

    }

    printf("%d\n", fall);

    return 0;
}