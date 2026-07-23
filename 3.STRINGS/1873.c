/**
 * @author vinicius lawliet
 * @brief Determines the winner using unique character identifiers instead of string comparisons.
 * @version 0.1
 * 
 * @problem: 1873 - Pedra-papel-tesoura-lagarto-Spock
 * 
*/

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    char str[2][10];

    while (n--) {
        scanf("%s %s", str[0], str[1]); // Rajesh x Sheldon

        int winner = 0;

        if (str[0][2] == str[1][2]) winner = -1;
        else if (str[0][2] == 's' && str[1][2] == 'p') winner++; // Tesoura corta papel
        else if (str[0][2] == 'p' && str[1][2] == 'd') winner++; // Papel cobre pedra
        else if (str[0][2] == 'd' && str[1][2] == 'g') winner++; // Pedra derruba lagarto
        else if (str[0][2] == 'g' && str[1][2] == 'o') winner++; // Lagarto adormece Spock
        else if (str[0][2] == 'o' && str[1][2] == 's') winner++; // Spock derrete tesoura
        else if (str[0][2] == 's' && str[1][2] == 'g') winner++; // Tesoura prende lagarto
        else if (str[0][2] == 'g' && str[1][2] == 'p') winner++; // Lagarto come papel
        else if (str[0][2] == 'p' && str[1][2] == 'o') winner++; // Papel refuta Spock
        else if (str[0][2] == 'o' && str[1][2] == 'd') winner++; // Spock vaporiza pedra
        else if (str[0][2] == 'd' && str[1][2] == 's') winner++; // Pedra quebra tesoura

        if (winner == -1) {
            printf("empate\n");
        } else if (winner == 1) {
            printf("rajesh\n");
        } else {
            printf("sheldon\n");
        }
    }
    
    return 0;
}