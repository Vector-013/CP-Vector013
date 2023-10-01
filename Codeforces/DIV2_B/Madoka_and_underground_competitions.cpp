#include <iostream>
#include <vector>
using namespace std;
void solve()
{
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i - j - r + c) % k == 0)
                cout << 'X';
            else
            {
                cout << '.';
            }
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}