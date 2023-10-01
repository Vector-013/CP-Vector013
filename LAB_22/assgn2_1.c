#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printer(char *c[], int a[], int start, int n, char ans[])
{
    if (start == n)
    {
        printf("%s\n", ans);
        return;
    }
    int p = strlen(c[a[start]]);
    for (int i = 0; i < p; i++)
    {
        ans[start] = c[a[start]][i];
        printer(c, a, start + 1, n, ans);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    char *c[] = {"", "abc", "onm", "ihg", "jlkz", "dfe", "wyx", "tuvs", "rqp"};
    // c[1] = "abc";
    // c[2] = "onm";
    // c[3] = "ihg";
    // c[4] = "jlkz";
    // c[5] = "dfe";
    // c[6] = "wyx";
    // c[7] = "tuvs";
    // c[8] = "rqp";
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    char *ans = (char *)calloc(n, sizeof(char));
    printer(c, a, 0, n, ans);
}