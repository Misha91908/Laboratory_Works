#include <stdio.h>
#include <stdlib.h>

int main() {

    int *p;

    p = NULL;

    p = (int *) malloc(sizeof(int));

    *p = 567;

    printf("The adress id: 0x%X\n", p);
    printf("The value id: %d\n", (*p));

    free(p);

    p = NULL;

    return 0;
}