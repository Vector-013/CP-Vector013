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
    string s;
    cin >> s;
    if (s == string(n, '0') || s == string(n, '1'))
    {
        cout << n << '\n';
        return;
    }
    for (int k = n - 1; k > 1; k--)
    {
        auto w = s;