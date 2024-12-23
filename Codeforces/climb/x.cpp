#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int N;
vector<int> G[5000];
long long ans;
bool dp[5000][5001];
int dfs(int u)
{
    int l = 0;
    dp[u][0] = true;
    for (int v : G[u])
    {
        int r = dfs(v);
        for (int i = l; i >= 0; i--)
            if (dp[u][i])
            {
                dp[u][i + r] = true;
            }
        l += r;
    }
    long long now = 0;
    for (int i = l; i >= 0; i--)
        if (dp[u][i])
        {
            dp[u][i + 1] = true;
            dp[u][i] = false;
            now = max(now, (long long)i * (l - i));
        }
    ans += now;
    return l + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int p;
        cin >> p;
        G[p - 1].push_back(i);
    }
    dfs(0);
    cout << ans << endl;
}
