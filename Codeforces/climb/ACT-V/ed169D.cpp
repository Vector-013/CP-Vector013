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
    auto maxi = [](int a, int b, int c, int d)
    {
        return max(a, max(b, max(c, d)));
    };
    auto mini = [](int a, int b, int c, int d)
    {
        return min(a, min(b, min(c, d)));
    };
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    vector<int> bg, br, by, gr, gy, ry;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i] == "BG")
            bg.push_back(i);
        else if (s[i] == "BR")
            br.push_back(i);
        else if (s[i] == "BY")
            by.push_back(i);
        else if (s[i] == "GR")
            gr.push_back(i);
        else if (s[i] == "GY")
            gy.push_back(i);
        else
            ry.push_back(i);
    }
    int r1, r2, r3, r4, r5, r6;
    int l1, l2, l3, l4, l5, l6;
    vector<int> l(n, -1), r(n, -1);
    for (int i = 0; i < n; i++)
    {
        int i1, i2, i3, i4, i5, i6;
        i1 = lower_bound(bg.begin(), bg.end(), i) - bg.begin();
        i2 = lower_bound(br.begin(), br.end(), i) - br.begin();
        i3 = lower_bound(by.begin(), by.end(), i) - by.begin();
        i4 = lower_bound(gr.begin(), gr.end(), i) - gr.begin();
        i5 = lower_bound(gy.begin(), gy.end(), i) - gy.begin();
        i6 = lower_bound(ry.begin(), ry.end(), i) - ry.begin();
        int r1 = r2 = r3 = r4 = r5 = r6 = inf;
        int l1 = l2 = l3 = l4 = l5 = l6 = -1;
        r1 = (i1 < bg.size() ? bg[i1] : inf);
        r2 = (i2 < br.size() ? br[i2] : inf);
        r3 = (i3 < by.size() ? by[i3] : inf);
        r4 = (i4 < gr.size() ? gr[i4] : inf);
        r5 = (i5 < gy.size() ? gy[i5] : inf);
        r6 = (i6 < ry.size() ? ry[i6] : inf);
        l1 = (i1 > 0 ? bg[i1 - 1] : -1);
        l2 = (i2 > 0 ? br[i2 - 1] : -1);
        l3 = (i3 > 0 ? by[i3 - 1] : -1);
        l4 = (i4 > 0 ? gr[i4 - 1] : -1);
        l5 = (i5 > 0 ? gy[i5 - 1] : -1);
        l6 = (i6 > 0 ? ry[i6 - 1] : -1);
        if (s[i] == "BG" || s[i] == "RY")
        {
            l[i] = maxi(l2, l3, l4, l5);
            r[i] = mini(r2, r3, r4, r5);
        }
        if (s[i] == "BR" || s[i] == "GY")
        {
            l[i] = maxi(l1, l3, l4, l6);
            r[i] = mini(r1, r3, r4, r6);
        }
        if (s[i] == "BY" || s[i] == "GR")
        {
            l[i] = maxi(l1, l2, l5, l6);
            r[i] = mini(r1, r2, r5, r6);
        }
    }
    while (q--)
    {
        int ll, rr;
        cin >> ll >> rr;
        ll--, rr--;
        int x = min(ll, rr);
        int y = max(ll, rr);
        bool simple = false;
        vector<int> tt(4);
        tt = {l[x], r[x], l[y], r[y]};
        // cout << l[x] << " " << r[x] << " " << l[y] << " " << r[y] << '\n';
        for (int i = 0; i < 4; i++)
        {
            if (tt[i] >= x && tt[i] <= y)
            {
                simple = true;
                break;
            }
        }
        if (!simple)
        {
            int a1, a2;
            if ((s[x] == "BG" && s[y] == "RY") || (s[x] == "RY" && s[y] == "BG"))
            {

                if (l[x] != -1)
                    a1 = x + y - 2 * l[x];
                else
                    a1 = inf;
                if (r[y] != inf)
                    a2 = 2 * r[y] - x - y;
                else
                    a2 = inf;
                int ans = min(a1, a2);
                cout << (ans != inf ? ans : -1) << '\n';
                continue;
            }
            if ((s[x] == "BR" && s[y] == "GY") || (s[x] == "GY" && s[y] == "BR"))
            {
                if (l[x] != -1)
                    a1 = x + y - 2 * l[x];
                else
                    a1 = inf;
                if (r[y] != inf)
                    a2 = 2 * r[y] - x - y;
                else
                    a2 = inf;
                int ans = min(a1, a2);
                cout << (ans != inf ? ans : -1) << '\n';
                continue;
            }
            if ((s[x] == "BY" && s[y] == "GR") || (s[x] == "GR" && s[y] == "BY"))
            {
                if (l[x] != -1)
                    a1 = x + y - 2 * l[x];
                else
                    a1 = inf;
                if (r[y] != inf)
                    a2 = 2 * r[y] - x - y;
                else
                    a2 = inf;
                int ans = min(a1, a2);
                cout << (ans != inf ? ans : -1) << '\n';
                continue;
            }
        }
        cout << y - x << '\n';
    }
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