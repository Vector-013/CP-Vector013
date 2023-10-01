#include <iostream>
using namespace std;
void solve()
{
    long long int n, sum = 0, oddsum = 0, evensum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n % 2 == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                evensum += a[i];
            else
                oddsum += a[i];
        }
        if (evensum <= oddsum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}