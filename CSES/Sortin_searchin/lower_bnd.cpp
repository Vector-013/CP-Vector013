#include <iostream>

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int partition(int s, int e, int a[])
{
    int p = a[s];
    int i = s, j = e;
    while (i < j)
    {
        while (a[i] <= p)
            i++;
        while (a[j] > p)
            j--;
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[s], a[j]);
    return j;
}

void quicksort(int s, int e, int a[])
{
    if (s >= e)
        return;
    int pivot = partition(s, e, a);
    quicksort(s, pivot - 1, a);
    quicksort(pivot + 1, e, a);
}

int main()
{
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    quicksort(0, n - 1, a);
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << '\n';
}