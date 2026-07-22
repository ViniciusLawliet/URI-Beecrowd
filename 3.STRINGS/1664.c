/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1664 - Bullshit Bingo
 * 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 500
#define MAX_LEN 26

char words[MAX_WORDS][MAX_LEN];

int exists(char *word, int n) {
    for (int i = 0; i < n; i++)
        if (!strcmp(words[i], word))
            return 1;
    return 0;
}

// Stein's Algorithm for finding GCD (Binary GCD) 
int gcd(int a, int b) {

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Finding K, where K is the greatest power of 2 that divides both a and b.
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k) {
        a >>= 1; b >>= 1;
    }

    // Dividing a by 2 until a becomes odd
    while ((a & 1) == 0) a >>= 1;

    // From here on, 'a' is always odd.
    do {
        // If b is even, remove all factor of 2 in b
        while ((b & 1) == 0) b >>= 1;

        // Now a and b are both odd. (Swap if necessary...)
        if (a > b) {
            int temp;
            temp = a;
            a = b;
            b = temp;
        }

        b = (b - a);
    } while (b != 0);

    // restore common factors of 2
    return a << k;
} // link: https://www.geeksforgeeks.org/dsa/steins-algorithm-for-finding-gcd/

int main() {

    char word[MAX_LEN];
    int len = 0;
    int c;

    int unique = 0;
    int total = 0;
    int sequences = 0;

    while ((c = getchar()) != EOF) {

        if (isalpha(c)) {
            if (len < MAX_LEN - 1)
                word[len++] = tolower(c);
        } else if (len > 0) {

            word[len] = '\0';

            if (!strcmp(word, "bullshit")) {
                total += unique;
                sequences++;
                unique = 0;
            } else {

                if (!exists(word, unique)) {
                    strcpy(words[unique], word);
                    unique++;
                }
            }

            len = 0;
        }
    }

    // EOF with remain word
    if (len > 0) {
        word[len] = '\0';

        if (!strcmp(word, "bullshit")) {
            total += unique;
            sequences++;
            unique = 0;
        }
    }

    /*
    printf("Sum: %d\n", total);
    printf("Sequences: %d\n", sequences);
    printf("GCD: %d\n", gcd(total, sequences));
    */

    int div = gcd(total, sequences);
    printf("%d / %d\n", total/div, sequences/div);
    
    return 0;
}

/*
UDEBUG INPUT EXAMPLE (STRUCTURED): [See https://www.udebug.com/URI/1664]
----------------------------------------------------------------------------------------
Programming 	languages 	can 		be 		    classified 	    BULLSHIT 
into 		    following 	types 		imperative 	and 		    BULLSHIT 
procedural 	    languages 	functional 	languages 	logical 	    BULLSHIT 
programming 	languages 	object 		oriented 			        BULLSHIT 
languages
----------------------------------------------------------------------------------------
hello 	HELLO 		    BULLSHIT
hElLo 	wOrLd 	hello 	BULLSHIT
----------------------------------------------------------------------------------------
This	counts		as	    five	words 			                                            BULLSHIT 
This	counts		as: 	FOUR 				                                                BULLSHIT
                                                                                                BULLSHIT 
The 	previous 	game 	should 	have 	words 		and 	and 	and 	and 	this	BULLSHIT
*/