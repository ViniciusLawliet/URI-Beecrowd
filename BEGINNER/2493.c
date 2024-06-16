/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 2493 - Operation Game
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTER 50

struct expression {
    int x, y, z;
};

int calc(struct expression e, char operador) {
    switch (operador) {
        case '+':
            return (e.x + e.y) == e.z;
        case '-':
            return (e.x - e.y) == e.z;
        case '*':
            return (e.x * e.y) == e.z;
        case 'I': {
            int soma = (e.x + e.y) == e.z;
            int subtracao = (e.x - e.y) == e.z;
            int multiplicacao = (e.x * e.y) == e.z;  
            return (soma || subtracao || multiplicacao) ? 0 : 1;
        }
        default:
            printf("Erro: operador desconhecido!\n");
            return 0;
    }
}

void insertInOrder(char **arr, int *count, char *name) {
    int i;
    for (i = *count - 1; i >= 0 && strcmp(arr[i], name) > 0; i--) {
        strcpy(arr[i + 1], arr[i]);
    }
    strcpy(arr[i + 1], name);
    (*count)++;
}

int main() {

    int t;
    while (scanf("%d", &t) != EOF) {

        struct expression *p;
        p = (struct expression *)malloc(t * sizeof(struct expression));
        
        int i;
        for (i = 0; i < t; i++)
            scanf("%d %d=%d", &p[i].x, &p[i].y, &p[i].z);

        char **M_names;
        M_names = (char **)malloc(t * sizeof(char *));
        for (i = 0; i < t; i++)
            M_names[i] = (char *)malloc(MAX_CHARACTER * sizeof(char));
        
        int count = 0;
        char name[MAX_CHARACTER]; int index; char resp;
        for (i = 0; i < t; i++) {
            scanf("%s %d %c", name, &index, &resp);
            
            if (!calc(p[index - 1], resp)) {
                insertInOrder(M_names, &count, name);
            }

        }

        if (!count)
            printf("You Shall All Pass!\n");
        else if (count == t)
            printf("None Shall Pass!\n");
        else {
            printf("%s", M_names[0]);
            for (i = 1; i < count; i++)
                printf(" %s", M_names[i]);
            printf("\n");
        }

        // memory deallocation
        free(p);
        for (i = 0; i < t; i++)
            free(M_names[i]);
        free(M_names);
    }

    return 0;
}