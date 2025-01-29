#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
using namespace std;
long long mod = 998244353;

long long mul(long long a, long long b)
{
    return (a * b) % mod;
}

long long power(long long a, long long b, long long m)
{
    long long result = 1;
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

long long modInverse(long long a, long long m)
{
    return power(a, m - 2, m);
}

long long divide(long long a, long long b)
{
    long long inv_b = modInverse(b, mod);
    return (a * inv_b) % mod;
}

void solve()
{
    int n, q, o, x;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> ax(n), bx(n);
    map<ll, ll> posa, posb;
    ll prod = 1ll;
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
        prod = mul(prod, min(ax[i].first, bx[i].first));
    }
    cout << prod << ' ';
    for (int i = 0; i < q; i++)
    {
        cin >> o >> x;
        x--;

        if (o == 1)
        {
            ax[posa[x]].first++;
            if ((posa[x] + 1 < n) && ax[posa[x]].first > ax[posa[x] + 1].first)
            {
                ll idx = lower_bound(ax.begin(), ax.end(), make_pair(ax[posa[x]].first, 0)) - ax.begin();
                if (idx > 0)
                    idx--;
                ll prev = ax[idx].first;
                if (idx > 0)
                {
                    posa[ax[idx].second] = posa[x];
                    swap(ax[posa[x]], ax[idx]);
                    posa[x] = idx;
                }

                if (min(bx[idx].first, prev) != min(bx[idx].first, ax[idx].first))
                {
                    prod = divide(prod, min(bx[idx].first, prev));
                    prod = mul(prod, min(bx[idx].first, ax[idx].first));
                }
            }
            else
            {
                if (min(bx[posa[x]].first, ax[posa[x]].first - 1) != min(bx[posa[x]].first, ax[posa[x]].first))
                {
                    prod = divide(prod, min(bx[posa[x]].first, ax[posa[x]].first - 1));
                    prod = mul(prod, min(bx[posa[x]].first, ax[posa[x]].first));
                }
            }
        }
        else
        {
            bx[posb[x]].first++;
            if ((posb[x] + 1 < n) && bx[posb[x]].first > bx[posb[x] + 1].first)
            {
                ll idx = lower_bound(bx.begin(), bx.end(), make_pair(bx[posb[x]].first, 0)) - bx.begin();
                if (idx > 0)
                    idx--;
                ll prev = bx[idx].first;
                if (idx > 0)
                {
                    posb[bx[idx].second] = posb[x];
                    swap(bx[posb[x]], bx[idx]);
                    posb[x] = idx;
                }

                if (min(ax[idx].first, prev) != min(ax[idx].first, bx[idx].first))
                {
                    prod = divide(prod, min(ax[idx].first, prev));
                    prod = mul(prod, min(ax[idx].first, bx[idx].first));
                }
            }
            else
            {
                if (min(ax[posb[x]].first, bx[posb[x]].first - 1) != min(ax[posb[x]].first, bx[posb[x]].first))
                {
                    prod = divide(prod, min(ax[posb[x]].first, bx[posb[x]].first - 1));
                    prod = mul(prod, min(ax[posb[x]].first, bx[posb[x]].first));
                }
            }
        }
        cout << prod << ' ';
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