#include <stdio.h>
#include <stdlib.h>
void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c %c\n", a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    printf("%c %c\n", a, c);
    hanoi(n - 1, b, a, c);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n, '1', '2', '3');
}
