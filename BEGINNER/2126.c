/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2126 - Searching Subsequences
 * 
 */

#include <stdio.h>

int main () {

    char subString[12], string[34];
    int c = 1;

    while (scanf("%s %s", subString, string) != EOF) {

        int sub = 0, pos = 0;
        int i, j;
        
        for (i = 0; string[i]; i++) {

            for (j = 0; subString[j] && (string[i + j] == subString[j]); j++);

            if (!subString[j]) {
                sub++;
                pos = i + 1;
            }

        }

        printf("Caso #%d:\n", c++);
        if (sub)
            printf("Qtd.Subsequencias: %d\nPos: %d\n\n", sub, pos);
        else
            printf("Nao existe subsequencia\n\n");
    }

    return 0;
}
