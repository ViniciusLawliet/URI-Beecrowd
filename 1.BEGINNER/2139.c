/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2139 - Pedrinho's Christmas
 * 
 */

#include <stdio.h>

int main () {

    int months[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int m, d;

    while (scanf("%d %d", &m, &d) != EOF) {

        int t = 0;
        for (int i = 0; i < (m - 1); i++)
            t += months[i];

        t += d;
        t = 360 - t;

        if (!t)
            printf("E natal!\n");
        else if (t < 0)
            printf("Ja passou!\n");
        else if (t == 1) {
            printf("E vespera de natal!\n");
        } else {
            printf("Faltam %d dias para o natal!\n", t);
        }

    }    

    return 0;
}
