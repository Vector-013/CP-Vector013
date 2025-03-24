#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n, r, col;
    string s;
    cin >> n >> r >> col >> s;
    set<pair<int, int>> st;
    st.insert({0, 0});
    pair<int, int> p = {0, 0};

    char c;
    for (auto c : s)
    {
        if (c == 'N')
            p.first--;
        if (c == 'S')
            p.first++;
        if (c == 'W')
            p.second--;
        if (c == 'E')
            p.second++;
        pair<int, int> q;
        q.first = p.first - r;
        q.second = p.second - col;
        if (st.count(q))
            cout << 1;
        else
            cout << 0;
        st.insert(p);
    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}