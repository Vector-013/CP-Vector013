#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
const int L = 305, N = 305, M = 305;
int a[L], b[N][M];
int l, n, m;

int ind[8];

bool dp[8][N][M];
void solve()
{
    int n, m, l;
    cin >> l >> n >> m;
    for (int i = 1; i <= l; i++)
    {
        cin >> a[i];
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