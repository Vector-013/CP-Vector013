#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void merge(int a[], int start, int mid, int end)
{
    int n1, n2, i, j, k, large;
    n1 = mid - start + 1;
    n2 = end - mid;
    int b[n1 + 1], c[n2 + 1];
    for (i = 0; i < n1; i++)
    {
        b[i] = a[start + i];
    }
    for (i = 0; i < n2; i++)
    {
        c[i] = a[mid + 1 + i];
    }
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
}
void merge_sort(int a[], int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    merge_sort(a, mid + 1, end);
    merge_sort(a, start, mid);
    merge(a, start, mid, end);
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
    std::sort(a, a + n);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            cnt++;
    }
    printf("%d", cnt + 1);
}