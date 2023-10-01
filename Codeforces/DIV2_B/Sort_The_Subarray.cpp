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

void solve()
{
    int n, cnt = 0, maxcnt = 1, l = 0, r = 0, fl = -1, fr = -1, q = 0;
    cin >> n;
    int a[n];
    int s[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        if (a[i] != s[i])
        {
            q = i;
            break;
        }
    }
    l = q;
    r = q;
    while (1)
    {
        if (l > 0 && s[l - 1] <= s[l])
            l--;
        if (r < n - 1 && s[r + 1] >= s[r])
            r++;
        if (l != 0 && s[l - 1] > s[l])
            fl = l;
        if (r != n - 1 && s[r + 1] < s[r])
            fr = r;
        if (l == 0)
        {
            if (s[0] <= s[1])
                fl = 0;
            else
                fl = 1;
        }
        if (r == n - 1)
        {
            if (s[n - 1] <= s[n - 1])
                fr = n - 1;
            else
                fr = n - 2;
        }
        if (fr > -1 && fl > -1)
            break;
    }
    cout << fl + 1 << " " << fr + 1 << '\n';
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