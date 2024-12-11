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
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(26);
    for (int i = 0; i < n; i++)
    {
        a[s[i] - 'a']++;
    }
    string q = "";
    for (int i = 0; i < 26; i++)
    {
        if (a[i] > 0)
        {
            q += string(1, char(i + 'a'));
        }
    }
    int z = q.size();
    vector<int> encoding(26);
    for (int i = 0; i < z; i++)
    {
        encoding[q[i] - 'a'] = q[z - i - 1] - 'a';
    }
    for (int i = 0; i < n; i++)
    {
        cout << char(encoding[s[i] - 'a'] + 'a');
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