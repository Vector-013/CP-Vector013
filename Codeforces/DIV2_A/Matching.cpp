#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
const int INF = 2e9;
#define make_pair
#define pb push_back
#define pop pop_back
typedef long long ll;
int power10(int p)
{
    int ans = 1;
    for (int i = 1; i < p + 1; i++)
    {
        ans = ans * 10;
    }
    return ans;
}
void solve()
{
    string s;
    int cnt = 0, ans;
    cin >> s;
    if (s[0] == '0')
    {
        cout << 0 << '\n';
        return;
    }
    else if (s[0] != '?')
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '?')
                cnt++;
        }
        ans = power10(cnt);
        cout << ans << '\n';
    }

    else
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '?')
                cnt++;
        }
        ans = power10(cnt);
        cout << 9 * ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}