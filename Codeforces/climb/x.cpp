#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, idx = -1;
    cin >> n;
    vector<long long> v(n), pfx(n + 1, 0), cntn(n + 1, 0), maxsf(n + 1), minsf(n + 1);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] != 1 && v[i] != -1)
        {
            idx = i;
            pfx[i + 1] = pfx[i];
        }
        else
        {
            pfx[i + 1] = pfx[i] + v[i];
        }
    }
    long long maxa = 0, mina = 0;
    if (idx == -1)
    {
        maxsf[0] = pfx[0];
        minsf[0] = pfx[0];
        for (int i = 1; i <= n; i++)
        {
            maxsf[i] = max(maxsf[i - 1], pfx[i]);
            minsf[i] = min(minsf[i - 1], pfx[i]);
            maxa = max(maxa, pfx[i] - minsf[i]);
            mina = min(mina, pfx[i] - maxsf[i]);
        }
        for (int i = mina; i <= maxa; i++)
        {
            s.insert(i);
        }
    }
    else
    {
        if (idx > 0)
        {
            maxsf[0] = pfx[0];
            minsf[0] = pfx[0];
            for (int i = 1; i <= idx; i++)
            {
                maxsf[i] = max(maxsf[i - 1], pfx[i]);
                minsf[i] = min(minsf[i - 1], pfx[i]);
                maxa = max(maxa, pfx[i] - minsf[i]);
                mina = min(mina, pfx[i] - maxsf[i]);
            }
            for (int i = mina; i <= maxa; i++)
            {
                s.insert(i);
            }
        }
        if (idx < n - 1)
        {
            maxsf[idx + 1] = pfx[0];
            minsf[idx + 1] = pfx[0];
            maxa = 0, mina = 0;
            for (int i = idx + 2; i <= n; i++)
            {
                maxsf[i] = max(maxsf[i - 1], pfx[i]);
                minsf[i] = min(minsf[i - 1], pfx[i]);
                maxa = max(maxa, pfx[i] - minsf[i]);
                mina = min(mina, pfx[i] - maxsf[i]);
            }
            for (int i = mina; i <= maxa; i++)
            {
                s.insert(i);
            }
        }
        if (idx > 0 && idx < n - 1)
        {
            for (int i = minsf[n - 1] - maxsf[idx - 1]; i <= maxsf[n - 1] - minsf[idx - 1]; i++)
            {
                s.insert(i + v[idx]);
            }
        }
        else
        {
            for (int i = minsf[n - 1]; i <= maxsf[n - 1]; i++)
            {
                s.insert(i + v[idx]);
            }
        }
    }
    cout << s.size() << '\n';
    for (auto i : s)
    {
        cout << i << ' ';
    }
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