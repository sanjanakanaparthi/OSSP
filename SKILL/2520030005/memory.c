#include <stdio.h>
#include <stdlib.h>

int global_var = 10;

void code_function()
{
}

int main()
{
    static int static_var = 20;
    int stack_var = 30;

    int *heap_var = malloc(sizeof(int));
    *heap_var = 40;

    printf("Address of code   : %p\n", (void *)code_function);
    printf("Address of global : %p\n", (void *)&global_var);
    printf("Address of static : %p\n", (void *)&static_var);
    printf("Address of heap   : %p\n", (void *)heap_var);
    printf("Address of stack  : %p\n", (void *)&stack_var);

    free(heap_var);

    return 0;
}
