#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
bool pair_first_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}
bool isprime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = sqrt(n); i >= 2; i--)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void solve()
{
    int n, cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    string w;
    w.resize(1);
    for (int i = 97; i < 123; i++)
    {
        w[0] = i;
        cnt = 0;
        for (int j = 0; j < n; j++)
            if (w != s.substr(j, 1))
                cnt++;

        if (cnt == n)
        {
            cout << w << '\n';
            return;
        }
    }
    w.resize(2);
    for (int i = 97; i < 123; i++)
    {
        w[0] = i;
        for (int j = 97; j < 123; j++)
        {
            w[1] = j;
            cnt = 0;
            for (int k = 0; k < n - 1; k++)
                if (w != s.substr(k, 2))
                    cnt++;
            if (cnt == n - 1)
            {
                cout << w << '\n';
                return;
            }
        }
    }
    w.resize(3);
    for (int m = 97; m < 99; m++)
    {
        w[0] = m;
        for (int i = 97; i < 123; i++)
        {
            w[1] = i;
            for (int j = 97; j < 123; j++)
            {
                w[2] = j;
                cnt = 0;
                for (int k = 0; k < n - 2; k++)
                    if (w != s.substr(k, 3))
                        cnt++;
                if (cnt == n - 2)
                {
                    cout << w << '\n';
                    return;
                }
            }
        }
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