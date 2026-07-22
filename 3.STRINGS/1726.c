/**
 * @author vinicius lawliet
 * @brief Evaluates set expressions using the Shunting Yard algorithm and bitmask operations.
 * @version 0.1
 * 
 * @problem: 1726 - Amigos
 * 
*/

#include <stdio.h>
#include <stdint.h>

#define MAX_LINE 256
#define MAX_STACK 64

//typedef unsigned long Set; // 32 bits
typedef uint32_t Set;

Set eval_union(Set a, Set b) { return a | b;    }
Set eval_inter(Set a, Set b) { return a & b;    }
Set eval_diff (Set a, Set b) { return a & (~b); }

enum {
    ASSOC_NONE = 0,
    ASSOC_LEFT,
    ASSOC_RIGHT
};

typedef struct op_s {
    char op;
    int prec;
    int assoc;
    Set (*eval)(Set, Set);
} Operator;

// Operator Table (Shunting-yard algorithm)
Operator ops[] = {
    {'*', 2, ASSOC_LEFT,  eval_inter},
    {'+', 1, ASSOC_LEFT,  eval_union},
    {'-', 1, ASSOC_LEFT,  eval_diff},
    {'(', 0, ASSOC_NONE,  NULL}
};

Operator *getop(char c) {
    int i;
    for(i = 0; i < (int)(sizeof(ops)/sizeof(ops[0])); i++)
        if(ops[i].op == c)
            return &ops[i];
    return NULL;
}

Set valueStack[MAX_STACK];
Operator *opStack[MAX_STACK];

int valueTop;
int opTop;

void apply() {
    Operator *op = opStack[--opTop];

    Set b = valueStack[--valueTop];
    Set a = valueStack[--valueTop];

    valueStack[valueTop++] = op->eval(a, b);
}

int main() {

    char line[MAX_LINE];
    while(fgets(line, sizeof(line), stdin)) {

        valueTop = 0;
        opTop = 0;

        int i = 0;

        while(line[i] && line[i] != '\n') {

            if (line[i] == '{') {
                Set s = 0;
                i++;

                while(line[i] != '}') {
                    s |= (1u << (line[i] - 'A'));
                    i++;
                }

                valueStack[valueTop++] = s;
            }
            else if (line[i] == '(') {
                opStack[opTop++] = getop('(');
            }
            else if (line[i] == ')') {
                while(opStack[opTop - 1]->op != '(') apply();
                opTop--; // remove '('
            }
            else if (line[i] == '+' || line[i] == '-' || line[i] == '*') {
                Operator *cur = getop(line[i]);

                while(opTop && opStack[opTop - 1]->op != '(' && (opStack[opTop - 1]->prec > cur->prec || (opStack[opTop - 1]->prec == cur->prec && cur->assoc == ASSOC_LEFT))) 
                    apply();

                opStack[opTop++] = cur;
            }

            i++;
        }

        while(opTop) 
            apply();

        Set ans = valueStack[0];

        putchar('{');

        for(i = 0; i < 26; i++) {
            if (ans & (1u << i)) putchar('A' + i);
        }

        puts("}");
    }

    return 0;
}