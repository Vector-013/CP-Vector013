#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int i = 0, j = 0;
    int ppl = 0, maxi = 0;
    while (i < n)
    {
        while (i < n && a[i] < b[j])
        {
            i++;
            ppl++;
            maxi = max(maxi, ppl);
        }
        while (i < n && j < n && b[j] <= a[i])
        {
            j++;
            ppl--;
        }
        if (i == n - 1)
            break;
    }
    cout << maxi << '\n';
}