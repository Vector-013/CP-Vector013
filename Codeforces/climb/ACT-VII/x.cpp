#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), d(n), c1, c2;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c1.push_back(i);
        s.insert(i);
    }
    for (int i = 0; i < n; i++)
        cin >> d[i];

    vector<int> status(n, 1);
    int round = n;
    while (c1.size())
    {
        c2.clear();
        int cnt = 0;
        for (int i = 0; i < c1.size(); i++)
        {
            int j = c1[i];
            int x = 0;
            auto it = s.find(j);
            if (it != s.begin())
            {
                x += a[*prev(s.find(j))];
            }
            if (it != s.end())
            {
                x += a[*next(s.find(j))];
            }
            if (d[j] < x)
            {
                cnt++;
                status[j] = 0;
            }
        }
        for (int i = 0; i < c1.size(); i++)
        {
            int j = c1[i];
            if (status[j] == 0)
            {
                auto it = s.find(j);
                if (it != s.begin() && status[*prev(it)] == 1)
                {
                    c2.push_back(*prev(it));
                }
                if (it != s.end() && status[*next(it)] == 1)
                {
                    c2.push_back(*next(it));
                }
            }
        }
        for (int i = 0; i < c1.size(); i++)
        {
            int j = c1[i];
            if (status[j] == 0)
            {
                s.erase(j);
                status[j] = -1;
            }
        }
        cout << cnt << ' ';
        round--;
        c1 = c2;
    }
    while (round--)
        cout << 0 << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}