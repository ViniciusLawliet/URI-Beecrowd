/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1038 - Snack
 * 
 */

#include <stdio.h>

struct snack {
    char specification[16];
    float price;
};

int main() {

    struct snack list[5] = {
        {"Cachorro Quente", 4.00},
        {"X-Salada", 4.50},
        {"X-Bacon", 5.00},
        {"Torrada simples", 2.00},
        {"Refrigerante", 1.50}
    };

    int code, quantity;
    scanf("%d %d", &code, &quantity);
    printf("Total: R$ %0.2f\n", list[code-1].price * quantity);

    return 0;
}