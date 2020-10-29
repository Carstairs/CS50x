// DEMO for valgrind
// http://valgrind.org/docs/manual/quick-start.html#quick-start.prepare

#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));
    //x[10] = 0; //buffer overflow - this is one bigger than a 0 indexed array
    x[9] = 50;
    free(x);
}

int main(void)
{
    f();
    return 0;
}
