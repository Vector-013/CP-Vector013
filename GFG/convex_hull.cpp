#include <stdio.h>
#include <stdlib.h>
int mark[];
typedef struct
{
    double x, y;
} pt;

pt max(pt a, pt b)
{
    if (a.x > b.x)
        return a;
    else
        return b;
}

double intercept(pt a, pt b, double k)
{
    return (((k - a.x) * (b.y - a.y) / (b.x - a.x)) + a.y);
}
void merge(pt a[], int start, int mid, int end)
{
    int n1, n2, i, j, k;
    pt large;
    n1 = mid - start + 1;
    n2 = end - mid;
    pt b[n1 + 1], c[n2 + 1];
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
        if (b[i].x < c[j].x)
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
void merge_sort(pt a[], int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    merge_sort(a, mid + 1, end);
    merge_sort(a, start, mid);
    merge(a, start, mid, end);
}

void combine(pt a[], int start, int mid, int end)
{
    int p = mid + 1;
    int q = mid - 1;
}
void convex_hull(pt a[], int start, int end)
{
    int mid = (start + end) / 2;
    int k = end - start + 1;
    if (k == 1 || k == 2 || k == 3)
    {
        for (int i = start; i <= end; i++)
            mark[i] = 1;
    }
    convex_hull(a, start, mid);
    convex_hull(a, mid, end);
    combine(a, start, mid, end);
}
int main()
{
    int n;
    scanf("%d", &n);
    pt a[n];
    mark = (int *)calloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &a[i].x, &a[i].y);
    }
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%lf %lf\n", a[i].x, a[i].y);
    }
}