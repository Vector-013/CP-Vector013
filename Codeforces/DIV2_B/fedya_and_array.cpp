#include <iostream>
using namespace std;
void solve()
{
    long long int x, y, a = 1;
    cin >> x >> y;
    int n = (x - y) * 2;
    cout << n << "\n"
         << y << " ";
    for (int i = 0; i < n - 1; i++)
    {
        y += a;
        cout << y << " ";
        if (y == x)
            a = -1;
    }
    cout << "\n";
    return;
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