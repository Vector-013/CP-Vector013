#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
void solve()
{
    int n, q, o, x;
    cin >> n >> q;
    vector<int> a(n), b(n);
    vector<pair<int, int>> ax(n), bx(n);
    map<int, int> posa, posb;
    long long prod = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ax[i] = {a[i], i};
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        bx[i] = {b[i], i};
    }
    sort(ax.begin(), ax.end());
    sort(bx.begin(), bx.end());
    for (int i = 0; i < n; i++)
    {
        posa[ax[i].second] = i;
        posb[bx[i].second] = i;
        prod = (prod * min(ax[i].first, bx[i].first)) % mod;
    }
    cout << prod << ' ';
    for (int i = 0; i < q; i++)
    {
        cin >> o >> x;
        x--;

        // for (int i = 0; i < n; i++)
        //     cout << ax[i].first << ' ';
        // cout << '\n';
        // for (int i = 0; i < n; i++)
        //     cout << bx[i].first << ' ';
        // cout << '\n';

        if (o == 1)
        {
            ax[posa[x]].first++;
            if (ax[posa[x]].first > ax[posa[x] + 1].first)
            {
                int idx = posa[x] + 1;
                while (idx < n && ax[idx].first < ax[posa[x]].first)
                    idx++;
                idx--;
                // cout << "idx = " << ax[posa[x] + 1].first << ' ';
                int prev = ax[idx].first;
                posa[ax[idx].second] = posa[x];
                swap(ax[posa[x]], ax[idx]);
                posa[x] = idx;

                if (min(bx[idx].first, prev) != min(bx[idx].first, ax[idx].first))
                {
                    prod = (prod / min(bx[idx].first, prev)) % mod;
                    prod = (prod * min(bx[idx].first, ax[idx].first)) % mod;
                }
            }
            else
            {
                if (min(bx[posa[x]].first, ax[posa[x]].first - 1) != min(bx[posa[x]].first, ax[posa[x]].first))
                {
                    prod = (prod / min(bx[posa[x]].first, ax[posa[x]].first - 1)) % mod;
                    prod = (prod * min(bx[posa[x]].first, ax[posa[x]].first)) % mod;
                }
            }
        }
        else
        {
            bx[posb[x]].first++;
            if (bx[posb[x]].first > bx[posb[x] + 1].first)
            {
                int idx = posb[x] + 1;
                while (idx < n && bx[idx].first < bx[posb[x]].first)
                    idx++;
                idx--;
                cout << "idx = " << idx << ' ';
                int prev = bx[idx].first;
                posb[bx[idx].second] = posb[x];
                swap(bx[posb[x]], bx[idx]);
                posb[x] = idx;

                if (min(ax[idx].first, prev) != min(ax[idx].first, bx[idx].first))
                {
                    prod = (prod / min(ax[idx].first, prev)) % mod;
                    prod = (prod * min(ax[idx].first, bx[idx].first)) % mod;
                }
            }
            else
            {
                if (min(ax[posb[x]].first, bx[posb[x]].first - 1) != min(ax[posb[x]].first, bx[posb[x]].first))
                {
                    prod = (prod / min(ax[posb[x]].first, bx[posb[x]].first - 1)) % mod;
                    prod = (prod * min(ax[posb[x]].first, bx[posb[x]].first)) % mod;
                }
            }
        }
        cout << prod << ' ';
    }
    // for (int i = 0; i < n; i++)
    //     cout << ax[i].first << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++)
    //     cout << bx[i].first << ' ';
    // cout << '\n';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}