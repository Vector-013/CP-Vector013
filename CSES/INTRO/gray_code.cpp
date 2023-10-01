#include <stdio.h>
#include <stdlib.h>
void printer(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return;
}
void flip(int a[], int n, int p)
{
    a[p] = 1 - a[p];
    return;
}
void generate(int a[], int n, int k)
{
    if (k == 0)
    {
        printer(a, n);
        flip(a, n, 0);
        printer(a, n);
        return;
    }
    generate(a, n, k - 1);
    flip(a, n, k);
    generate(a, n, k - 1);
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    generate(a, n, n - 1);
}