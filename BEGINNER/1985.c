/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1985 - MacPRONALTS
 * 
 */

#include <stdio.h>

struct mac {
    int code;
    float value;
};

int main () {

    struct mac x[5] = {
        {1005, 5.50},
        {1001, 1.50},
        {1002, 2.50},
        {1003, 3.50},
        {1004, 4.50}
    };
    
    int p, c;
    scanf("%d", &p);

    float q, tot = 0;    
    while (p) {
        p--;
        scanf("%d %f", &c, &q);

        // hash function
        tot += (x[c % 5].value * q);

    }

    printf("%0.2f\n", tot);

    return 0;

}