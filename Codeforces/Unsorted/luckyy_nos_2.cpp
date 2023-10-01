#include <bits/stdc++.h>
using namespace std;
long long n, result = 1e15;
void dfs(long long x, int d)
{
    // cout<<x;
    if (x < result)
        if (x >= n && !d)
            result = x;
        else
        {
            dfs(x * 10 + 4, d + 1);
            dfs(x * 10 + 7, d - 1);
        }
}
int main()
{
    cin >> n;
    dfs(0, 0);
    cout << result;
}
