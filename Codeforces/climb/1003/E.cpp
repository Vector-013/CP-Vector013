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
    int N, M, K;
    cin >> N >> M >> K;
    if (N < K && M < K || abs(N - M) > K)
    {
        cout << "-1\n";
        return;
    }
    if (N >= M)
    {
        for (int i = 0; i < N; i += K)
        {
            for (int j = 0; j < min(K, N - i); j++)
                cout << '0';
            for (int j = 0; j < min(K, M - i); j++)
                cout << '1';
        }
    }
    else
    {
        for (int i = 0; i < M; i += K)
        {
            for (int j = 0; j < min(K, M - i); j++)
                cout << '1';
            for (int j = 0; j < min(K, N - i); j++)
                cout << '0';
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
