#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int cnt_merge(int a[], int start, int mid, int end)
{
    int n1, n2, i, j, k, large, to_return = 0, x, y;
    n1 = mid - start + 1;
    n2 = end - mid;
    x = n1 - 1;
    int b[n1 + 1], c[n2 + 1];
    for (i = 0; i < n1; i++)
    {
        b[i] = a[start + i];
    }
    for (i = 0; i < n2; i++)
    {
        c[i] = a[mid + 1 + i];
    }
    for (int i = 0; i < n1; i++)
    {
        if (b[i] > c[0])
        {
            x = i;
            break;
        }
    }
    for (int i = 0; i < n2; i++)
    {
        if (b[x] > c[i])
        {
            to_return++;
            continue;
        }
        else
        {
            x++;
            if (x >= n1)
            {
                x = n1 - 1;
                break;
            }
            to_return += i;
            i--;
        }
    }

    to_return += (n1 - 1 - x) * n2;
    // printf("%d\n", to_return);

    large = max(b[n1 - 1], c[n2 - 1]);
    b[n1] = large;
    c[n2] = large;
    i = 0;
    j = 0;
    for (k = start; k <= end; k++)
    {
        if (b[i] < c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
    }
    return to_return;
}

int count_inv(int a[], int start, int end)
{
    if (start == end)
        return 0;
    int mid = (start + end) / 2;
    int p = count_inv(a, mid + 1, end);
    int q = count_inv(a, start, mid);
    int r = cnt_merge(a, start, mid, end);
    return (p + q + r);
}

int main()
{
    int n, i = 0;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int m = count_inv(a, 0, n - 1);
    printf("%d\n", m);
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d ", a[i]);
    // }
}