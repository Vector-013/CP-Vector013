#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a = (int *)
        malloc(6 * sizeof(int));
    for (int i = 0; i < 6; i++)
    {
        a[i] = i + 1;
    }
    int *p = a;
    printf("%d %d %d ", a[1], a[5], *(p + 7));
    free(p);
    printf("%d %d %d", a[1], a[5], *(p + 7));
}