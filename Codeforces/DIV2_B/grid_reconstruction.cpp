#include <iostream>
#include <vector>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << 2 * (n - i / 2) << " ";
        }
        else
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << 2 * (n - i / 2) - 1 << " ";
        }
        else
        {
            cout << i << " ";
        }
    }

    cout << 2 * n - 1 << endl;
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