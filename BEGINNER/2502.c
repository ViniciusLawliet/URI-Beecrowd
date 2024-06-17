/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2502 - Deciphering the Encrypted Card
 * 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY 21
#define MAX_LINE 1001

void map(char *k1, char *k2, int c, char *map) {

    int i;
    for (i = 0; i < 128; i++)
        map[i] = (char) i;

    for (i = 0; i < c; i++) {
        map[(int) k1[i]] = k2[i];
        map[(int) k2[i]] = k1[i];
    }

}

void decrypt(char *line, char *ascii) {

    int i;
    for (i = 0; line[i] != '\0'; i++) {

        int x = (int) line[i];
        if (isdigit(x))
            putchar(tolower(ascii[x]));
        else
            putchar((isupper(x)) ? ascii[x] : tolower(ascii[(int) toupper(x)]));

    }
    printf("\n");
}

int main() {

    int c, n;
    char key1[MAX_KEY], key2[MAX_KEY];
    char line[MAX_LINE];

    while (scanf("%d %d\n", &c, &n) != EOF) {

        scanf(" %[^\n]s", key1);
        scanf(" %[^\n]s", key2);

        char ascii[128];
        map(key1, key2, c, ascii);

        for (int i = 0; i < n; i++) {
            scanf(" %[^\n]s", line);
            decrypt(line, ascii);
        }

        printf("\n");
    }

    return 0;
}