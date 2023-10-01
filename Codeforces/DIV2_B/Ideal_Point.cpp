#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool pairsort(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.second < p2.second);
}
void solve()
{
    int n, k, l, r, cmax = 0;
    cin >> n >> k;
    vector<pair<int, int>> v(51);

    for (int i = 0; i < 51; i++)
    {
        v[i].first = i;
        v[i].second = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;

        if (l <= k && r >= k)
        {
            for (int j = l; j <= r; j++)
            {
                v[j].second++;
            }
        }
    }

    sort(v.begin(), v.end(), pairsort);

    if (v[50].first == k && v[49].second != v[50].second)
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }
    v.clear();
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