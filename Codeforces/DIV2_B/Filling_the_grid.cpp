#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
const int INF = 2e9;
#define mp make_pair
#define pb push_back
#define pop pop_back
typedef long long ll;
int modder(ll x, ll y, ll z)
{
    ll req;
    req = 1;
    for (int i = 1; i <= y; i++)
    {
        req = (x * req) % z;
    }
    return req;
}
void solve()
{
    int r, c, a, b, cnt = 0;
    bool flag = false;
    ll ans;
    cin >> r >> c;
    vvi v(r, vi(c, -1));
    for (int i = 0; i < r; i++)
    {
        cin >> a;
        if (a < c)
            v[i][a] = 0;
        for (int j = 0; j < a; j++)
            v[i][j] = 1;
    }
    for (int i = 0; i < c; i++)
    {
        cin >> b;
        if (b < r && v[b][i] != 1)
            v[b][i] = 0;
        if (b < r && v[b][i] == 1)
            flag = true;

        for (int j = 0; j < b; j++)
        {
            if (v[j][i] != 0)
                v[j][i] = 1;
            else
                flag = true;
        }
    }
    if (!flag)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (v[i][j] == -1)
                    cnt++;
            }
        }
        ans = modder((ll)2, (ll)cnt, (1e9) + 7);
        cout << ans << '\n';
        return;
    }
    else
    {
        cout << 0 << '\n';
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}