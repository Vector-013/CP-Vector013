#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

ll mod_mul(ll a, ll b)
{
    return (a * b) % mod;
}
// Function to compute (a^b) % MOD using binary exponentiation
long long power(long long a, long long b, long long MOD)
{
    long long result = 1;
    a = a % MOD; // Handle large numbers
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

// Function to compute modular inverse using Fermat's Little Theorem
long long modInverse(long long a, long long MOD)
{
    return power(a, MOD - 2, MOD);
}

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
    for (int i = 0; i < q; i++)
    {
        cin >> o >> x;
        x--;

        if (o == 1)
        {
            // Update a[x]
            int prev_min = min(ax[posa[x]].first, bx[posb[x]].first);
            ax[posa[x]].first++;
            // Recalculate position after update
            if (posa[x] < n - 1 && ax[posa[x]].first > ax[posa[x + 1]].first)
            {
                // Fix the position by swapping with the next element if necessary
                int idx = posa[x] + 1;
                while (idx < n && ax[idx].first < ax[posa[x]].first)
                    idx++;
                if (idx == n)
                    idx = n - 1;

                int prev = ax[idx].first;
                swap(ax[posa[x]], ax[idx]);
                posa[x] = idx;

                if (min(bx[idx].first, prev) != min(bx[idx].first, ax[idx].first))
                {
                    prod = (prod * modInverse(prev, mod)) % mod;
                    prod = (prod * min(bx[idx].first, ax[idx].first)) % mod;
                }
            }
            else
            {
                if (min(bx[posa[x]].first, ax[posa[x]].first - 1) != min(bx[posa[x]].first, ax[posa[x]].first))
                {
                    prod = (prod * modInverse(min(bx[posa[x]].first, ax[posa[x]].first - 1), mod)) % mod;
                    prod = (prod * min(bx[posa[x]].first, ax[posa[x]].first)) % mod;
                }
            }
        }
        else
        {
            // Update b[x]
            int prev_min = min(ax[posa[x]].first, bx[posb[x]].first);
            bx[posb[x]].first++;
            // Recalculate position after update
            if (posb[x] < n - 1 && bx[posb[x]].first > bx[posb[x + 1]].first)
            {
                // Fix the position by swapping with the next element if necessary
                int idx = posb[x] + 1;
                while (idx < n && bx[idx].first < bx[posb[x]].first)
                    idx++;
                if (idx == n)
                    idx = n - 1;

                int prev = bx[idx].first;
                swap(bx[posb[x]], bx[idx]);
                posb[x] = idx;

                if (min(ax[idx].first, prev) != min(ax[idx].first, bx[idx].first))
                {
                    prod = (prod * modInverse(prev, mod)) % mod;
                    prod = (prod * min(ax[idx].first, bx[idx].first)) % mod;
                }
            }
            else
            {
                if (min(ax[posb[x]].first, bx[posb[x]].first - 1) != min(ax[posb[x]].first, bx[posb[x]].first))
                {
                    prod = (prod * modInverse(min(ax[posb[x]].first, bx[posb[x]].first - 1), mod)) % mod;
                    prod = (prod * min(ax[posb[x]].first, bx[posb[x]].first)) % mod;
                }
            }
        }

        cout << prod << ' ';
    }
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
