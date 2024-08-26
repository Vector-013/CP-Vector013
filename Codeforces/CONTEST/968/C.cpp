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

void solve()
{
    string s;
    ll n;
    cin >> n >> s;
    vector<int> v(26, 0);
    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'a']++;
    }
    int i = 0;
    char c;
    while (n)
    {
        if (v[i])
        {
            c = (i + 'a');
            cout << c;
            n--;
            v[i]--;
            // cout << "popo\n";
        }
        i++;
        i = (i % 26);
        // cout << i << " ";
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