#include <iostream>
#include <vector>
using namespace std;
void solve()
{
    long long int n, k, cnt = 0;
    cin >> n >> k;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != v[n - 1 - i][n - 1 - j])
                cnt++;
        }
    }
    if (n % 2 == 0 && k >= cnt / 2 && (k - cnt / 2) % 2 == 0)
        cout << "YES" << endl;
    else if (n % 2 == 1 && k >= cnt / 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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