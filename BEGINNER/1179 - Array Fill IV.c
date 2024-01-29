#include <stdio.h>

void printArray(int *arr, int len, char str[]) {
    for (int i = 0; i < len; i++)
        printf("%s[%d] = %d\n", str, i, arr[i]);
}

int main() {

    int n, even[5], odd[5];

    int i = 0, j = 0, c = 15;
    while(c) {
        c--;
        scanf("%d", &n);

        (n & 1) ? (odd[i++] = n) : (even[j++] = n);

        if (i > 4) {
            printArray(odd, 5, "impar");
            i = 0;
        }
        
        if (j > 4) {
            printArray(even, 5, "par");
            j = 0;
        }

    }

    printArray(odd, i, "impar");
    printArray(even, j, "par");

    return 0;
}