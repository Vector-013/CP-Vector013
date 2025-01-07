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
    vector<int> a(n);
    vector<string> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v[i] = bitset<32>(a[i]).to_string();
        sum += a[i];
    }
    if (sum % n != 0)
    {
        cout << "No\n";
        return;
    }
    sum /= n;
    string mid = bitset<32>((int)sum).to_string();
    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int diff, zz;
        if (a[i] != sum)
        {
            diff = abs(a[i] - sum);
            zz = __builtin_ctz(diff);
            mp[zz] += (a[i] < sum) ? 1 : -1;
            diff += 1 << zz;
            if (diff & (diff - 1))
            {
                cout << "No\n";
                return;
            }
            mp[__builtin_ctz(diff)] += (a[i] < sum) ? -1 : 1;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        if (mp[i])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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